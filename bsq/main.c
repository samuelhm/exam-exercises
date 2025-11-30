#include <stdlib.h>
#include <stdio.h>

char *parse_map(FILE *fd);
void print_result(char *map);

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
        print_result(map);
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
        print_result(map);
        free(map);
    }
    
    return (0);
}

char *parse_map(FILE *fd)
{
    char *map = NULL;
    char *line = NULL;
    int lines = 0;
    size_t cols = 0;
    char empty;
    char obstacle;
    char fill;
    if (fscanf(fd, "%d %c %c %c ", &lines, &empty, &obstacle, &fill) != 4)
    {
        return (NULL);
    }
    if (cols = getline(&line, 0, fd) == -1)
    {
        free(line);
        return (NULL);
    }
    map = malloc(lines * (cols - 1) * sizeof(char));
    if (!map)
    {
        free(line);
        return (NULL);
    }
    for (int i = 0; i < (cols - 1); i++)
        map[i] = line[i];
    free(line);
    line = NULL;
    for (int y = 1; y < lines; y++)
    {
        int result;
        result = getline(&line, 0, fd);
        if ( result != cols )
        {
            free (line);
            free (map);
            return (NULL);
        }
        for (int i = 0; i < (cols - 1); i++)
            map[y * (cols - 1) + i] = line[i];
        free(line);
        line = NULL;

    }
    return (map);
}