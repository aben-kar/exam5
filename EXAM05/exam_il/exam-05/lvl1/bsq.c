#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_map
{
    int nb;
    char empty;
    char obs;
    char    full;
    char **m;
    int **dp;
}            t_map;

int ft_atoi(char *str)
{
    int i = 0, sign = 1, res = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' && str[i] == '+')
    {
        if (str[i] == '-') sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

int ft_strlen (char *str)
{
    int i = 0;
    while (str[i]) i++;
    return (i);
}

int    pars(FILE *f, t_map *m)
{
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, f);
    if (ft_strlen(line) < 5)
        return (0);
    int len_line = ft_strlen(line);
    m->empty = line[len_line - 4];
    m->obs = line[len_line - 3];
    m->full = line[len_line - 2];
    line[len_line - 4] = '\0';
    m->nb = ft_atoi(line);
    m->m = (char **)malloc(sizeof(char *) * (m->nb + 1));
    m->dp = (int **)malloc(sizeof(int *) * (m->nb + 1));
    int i = 0;
    int expect = -1;
    while (i < m->nb && getline(&line, &len, f))
    {
        m->m[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
        m->dp[i] = (int *)malloc(sizeof(int) * (ft_strlen(line) + 1));
        int j = 0;
        if (expect == -1)
            expect = ft_strlen(line);
        if (expect != ft_strlen(line))
            return (0);
        while (j < ft_strlen(line))
        {
            m->m[i][j] = line[j];
            j++;
        }
        m->m[i][--j] = '\0';
        i++;
    }
    m->m[i] = NULL;
    fclose(f);
    return (1);
}

int min3(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return (b);
    return (c);
}

void    bsq(t_map *m)
{
    int max = -1, max_i, max_j;
    for (int i = 0; i < m->nb; i++)
    {
        for (int j = 0; j < ft_strlen(m->m[i]); j++)
        {
            if (m->m[i][j] == m->obs)
                m->dp[i][j] = 0;
            else if (i != 0 && j != 0 && m->m[i][j] == m->empty)
                m->dp[i][j] = 1 + min3(m->dp[i][j - 1], m->dp[i - 1][j], m->dp[i - 1][j - 1]);
            else
                m->dp[i][j] = 1;
            if (m->dp[i][j] > max)
            {
                max = m->dp[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    for (int i = max_i - max + 1; i <= max_i; i++)
        for (int j = max_j - max + 1; j <= max_j; j++)
            m->m[i][j] = m->full;
    for (int i = 0; i < m->nb; i++)
        printf("%s\n", m->m[i]);
}

int main(int ac, char **av)
{
    FILE *f;
    t_map *m = (t_map *)malloc(sizeof(t_map));
    if (ac > 2)
        return 1;
    if (ac == 1)
        f = fopen("/dev/stdin", "r");
    else
        f = fopen(av[1], "r");
    if (!pars(f, m))
        return (printf("map error\n"), 1);
    bsq(m);
}













// Assignment name              : bsq
// Expected files               : *.c *.h
// Allowed functions and globals: malloc, calloc, realloc, free, fopen, fclose,
// getline, fscanf, fputs, fprintf, stderr, stdout, stdin, errno
// --------------------------------------------------------------------------------

// The aim of this program is to find the biggest square on a map, avoiding obstacles.
// A file containing the map will be provided. It'll have to be passed as an argument for your program.
// The first line of the map contains information on how to read the map (space separated) :
//  - The number of lines on the map;
//  - The "empty" character;
//  - The "obstacle" character;
//  - The "full" character.
// The map is made up of '"empty" characters', lines and '"obstacle" characters'.
// The aim of the program is to replace '"empty" characters' by '"full" characters' in order to represent the biggest square possible.
// In the case that more than one solution exists, we'll choose to represent the square that's closest to the top of the map, then the one that's most to the left.
// When your program receives more than one map in argument, each solution or "map error" must be followed by a line break.
// Should there be no passed arguments, your program must be able to read on the standard input.

// Definition of a valid map :
//  - All lines must have the same length.
//  - There's at least one line of at least one box.
//  - At each end of line, there's a line break.
//  - The characters on the map can only be those introduced in the first line.
//  - The map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical.
//  - The characters can be any printable character, even numbers.
//  - In case of an invalid map, your program should display "map error" on the error output followed by a line break. Your program will then move on to the next map.

// example:
// %>cat example_file
// 9 . o x
// ...........................
// ....o......................
// ............o..............
// ...........................
// ....o......................
// ...............o...........
// ...........................
// ......o..............o.....
// ..o.......o................
// %>./bsq example_file
// .....xxxxxxx...............
// ....oxxxxxxx...............
// .....xxxxxxxo..............
// .....xxxxxxx...............
// ....oxxxxxxx...............
// .....xxxxxxx...o...........
// .....xxxxxxx...............
// ......o..............o.....
// ..o.......o................
// %>


