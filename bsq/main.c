#include <stdlib.h>
#include <stdio.h>


ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    int c;
    size_t len = 0;

    if (*lineptr == NULL || *n == 0)
    {
        *n = 128;
        *lineptr = malloc(*n);
        if (!*lineptr)
            return -1;
    }

    while ((c = fgetc(stream)) != EOF)
    {
        if (len + 1 >= *n)
        {
            size_t new_size = *n * 2;
            char *new_ptr = realloc(*lineptr, new_size);
            if (!new_ptr)
                return -1;
            *lineptr = new_ptr;
            *n = new_size;
        }

        (*lineptr)[len++] = (char)c;
        if (c == '\n')
            break;
    }

    if (len == 0 && c == EOF)
        return -1;

    (*lineptr)[len] = '\0';
    return (ssize_t)len;
}

static int my_min(int a, int b, int c)
{
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}


char *parse_map(FILE *fd);
void print_result(char *map, int lines, int cols);
void solve_map(char *map, char fill, char obstacle, char empty, int cols, int lines);


int main(int argc, char *argv[])
{
    char *map;
    FILE *fd;

    if (argc == 1)
    {
        map = parse_map(stdin);
        if (!map)
        {
            fputs("map error\n", stderr);
            return (1);
        }
        free(map);
        return (0);
    }

    for (int i = 1; i < argc; i++)
    {
        fd = fopen(argv[i], "r");
        if (fd == NULL)
        {
            fputs("map error\n", stderr);
            continue;
        }
        map = parse_map(fd);
        if (!map)
        {
            fputs("map error\n", stderr);
            fclose(fd);
            continue;
        }
        fclose(fd);
        free(map);
    }
    
    return (0);
}

char *parse_map(FILE *fd)
{
    char *map = NULL;
    char *line = NULL;
    int lines = 0;
    ssize_t cols = 0;
    size_t buff = 0;
    char empty;
    char obstacle;
    char fill;
    if (fscanf(fd, "%d %c %c %c ", &lines, &empty, &obstacle, &fill) != 4)
    {
        return (NULL);
    }
    if (lines <= 0)
        return (NULL);
    if (empty == obstacle || empty == fill || obstacle == fill)
        return (NULL);
    cols = getline(&line, &buff, fd);
    if (cols <= 0)
    {
        free(line);
        return (NULL);
    }
    if (line[cols -1] == '\n')
    {
        cols--;
        line[cols] = '\0';
        
    }
    map = malloc(lines * cols  * sizeof(char));
    if (!map)
    {
        free(line);
        return (NULL);
    }
    for (int i = 0; i < cols ; i++)
    {
        if (line[i] != empty && line[i] != obstacle)
        {
            free(line);
            free(map);
            return NULL;
        }
        map[i] = line[i];
    }
    free(line);
    line = NULL;
    for (int y = 1; y < lines; y++)
    {
        ssize_t result;
        result = getline(&line, &buff, fd);
        if (result <= 0)
        {
            free(line);
            free(map);
            return NULL;
        }
        if (line[result -1] == '\n')
        {
            result--;
            line[result] = '\0';
        }
        if ( result != cols )
        {
            free (line);
            free (map);
            return (NULL);
        }
        for (int i = 0; i < cols; i++)
        {
            if (line[i] != empty && line[i] != obstacle)
            {
                free(line);
                free(map);
                return (NULL);
            }
            map[y * cols + i] = line[i];
        }
        free(line);
        line = NULL;

    }
    solve_map(map, fill, obstacle, empty, cols, lines); //guarda mapa con el simbolo fill dibujado listo para entregar
    print_result(map, lines, cols);
    return (map);
}

void solve_map(char *map, char fill, char obstacle, char empty, int cols, int lines)
{
    int *dp = malloc(cols * lines * sizeof(int));
    if (!dp)
        return;
    int bigger = 0;
    int best_x;
    int best_y;

    for (int y = 0; y < lines; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            int pos = y * cols + x;
            char c = map[pos];
            if (c == obstacle)
                dp[pos] = 0;
            else
            {
                if (x == 0 ||  y == 0)
                    dp[pos] = 1;
                else
                {
                    dp[pos] = 1 + my_min(dp[(y -1 ) * cols + x], dp[(y -1 ) * cols + (x -1)], dp[y * cols + (x - 1)]);
                }
            }
            if (dp[pos] > bigger)
            {
                bigger = dp[pos];
                best_x = x;
                best_y = y;
            }
        }
    }
    if (bigger == 0)
    {
        free(dp);
        return;
    }
    int start_x = best_x - bigger + 1;
    int start_y = best_y - bigger + 1;
    for (int y = start_y; y <= best_y; y++)
    {
        for (int x = start_x; x <= best_x; x++)
        {
            map[y * cols + x] = fill;
        }
    }
    free(dp);
    return;

}

void print_result(char *map, int lines, int cols)
{
    for (int y = 0; y < lines; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            putchar(map[y * cols + x]);
        }
        putchar('\n');
    }
}
