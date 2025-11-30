#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int count (char *board, int width, int height, int x, int y)
{
    int count = 0;
    for (int off_y = -1; off_y <= 1; off_y++)
    {
        for (int off_x = -1; off_x <= 1; off_x++)
        {
            if (off_x == 0 && off_y == 0)
                continue;
            int nx = x + off_x;
            int ny = y + off_y;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height)
            {
                if (board[ny * width + nx] == '0')
                    count++;
            }
        }
    }
    return (count);
}

char *iter(char *board, int width, int height)
{
    char *next = calloc(height * width, sizeof(char));
    if (!next)
        return next;
    for (int y = 0; y < height ; y++)
    {
        for (int x = 0; x < width ; x++)
        {
            char cell = board[y * width + x];
            int n = count(board,width,height,x, y);
            if (cell == '0')
            {
                if (n == 2 || n == 3)
                    next[y * width + x] = '0';
                else
                    next[y * width + x] = 0;
            }
            else 
            {
                if (n == 3)
                    next[y * width + x] = '0';
                else
                    next[y * width + x] = 0;
            }
        }
    }
    return next;
}

void print_board(char *board, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            char c = board[i * width + j];
            if ( c == 0)
                putchar(' ');
            else
                putchar(c);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
        return (1);
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iterations = atoi(argv[3]);
    char *board = calloc(height * width, sizeof(char));
    if (!board)
        return (1);

    ssize_t bytes;
    char buf[1024];
    int down = 0;
    int pos_x = 0;    
    int pos_y = 0;


    while ((bytes = read(0, buf, sizeof(buf))) > 0)
    {
        int i = 0;
        while (i < bytes)
        {
            char c = buf[i];
            if (c == 'a' && pos_x > 0)
                pos_x--;
            else if (c == 'd' && pos_x < width - 1)
                pos_x++;
            else if (c == 'w' && pos_y > 0)
                pos_y--;
            else if (c == 's' && pos_y < height - 1)
                pos_y++;
            else if (c == 'x')
                down = !down;
            if (down)
                    board[pos_y * width + pos_x] = '0';

            i++;
        }
    }
    while (iterations)
    {
        char *tmp = board;
        board = iter(board, width, height);
        free (tmp);
        if (!board)
            return (1);
        iterations--;
    }
    print_board(board, width, height);
    free(board);
    return (0);
}