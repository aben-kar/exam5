#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_map
{
    int row;
    int cols;
    int **dp;
    char empty;
    char obs;
    char full;
    char **m;
} t_map;


int parse(FILE *f, t_map *m)
{
    char *line = NULL;
    int len = 0;

    if (!f || getline(&line, &len, f) <= 0)
    {
        free(line);
        return 0;
    }

    int i = 0;
    int _row = m->row = 0;

    while (line[i] >= '0' && line[i] <= '9')
    {
        _row = _row * 10 + (line[i] - '0');
        i++;
    }

    if (_row <= 0 || line[i] != ' ')
    {
        free(line);
        return 0;
    }
    m->empty = line[++i];
    if (line[++i] != ' ')
    {
        free(line);
        return 0;
    }
    m->obs = line[++i];
    if (line[++i] != ' ')
    {
        free(line);
        return 0;
    }
    m->full = line[++i];
    if (line[++i] != '\n')
    {
        free(line);
        return 0;
    }

    if (m->empty == m->obs || m->empty == m->full || m->obs == m->full)
    {
        free(line);
        return 0;
    }

    free(line);
    line = NULL;

    m->m = (char **)malloc(_row * sizeof(char *));
    m->dp = (int **)malloc(_row * sizeof(int *));
    m->cols = -1;

    for(int r = 0; r < _row; r++)
    {
        if (!f || getline(&line, &len, f) <= 0)
        {
            free(line);
            free_map(m);
            return 0;
        }

        int row_len = 0;
        while (line[row_len] && line[row_len] != '\n')
        {
            if (line[row_len] != '\n' || row_len == 0)
            {
                free(line);
                free_map(m);
                return 0;
            }
            row_len++;
        }

        if (m->cols == -1)
            m->cols = row_len;
        else if (m->cols != row_len)
        {
            free(line);
            free_map(m);
            return 0;
        }

        m->m[r] = (char *)malloc((_row + 1) * sizeof(char));
        m->dp[r] = (int *)malloc(_row * sizeof(int));

        for (int c = 0; c < m->cols; c++)
        {
            if (line[c] != m->empty && line[c] != m->obs)
            {
                free(line);
                free_map(m);
                return 0;
            }
            m->m[r][c] = line[c];
        }
        m->m[r][m->cols] = '\0';
    }
    if (getline(&line, &len, f) > 0)
    {
        free(line);
        free_map(m);
        return 0;
    }
    free(line);
    return 1;
}

int min3(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

int min3(int a, int b, int c)
{
    if (a <= b && a <= c)

    if (a <= b && a <= c)
}
void bsq(t_map *m)
{
    int max = 0;
    int maxI = 0;
    int maxJ = 0;

    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            if (m->m[i][j] == m->obs)
                m->dp[i][j] = 0;
            else if (i >= 0 && j >= 0)
                m->dp[i][j] = 1 + min3(m->dp[i][j - 1], m->dp[i - 1][j], m->dp[i - 1][j - 1]);
            else
                m->dp[i][j] = 1;
            if (m->dp[i][j] > max)
            {
                max = m->dp[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }
    for (i = max - maxI + 1; i <=  maxI)
        j 
            m->m[i][j] = m->full;
        
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        t_map m = {0};
        if (!parse(stdin, &m))
            fprintf(stderr, "map error\n");
        else
        {
            bsq(&m);
            free_map(&m);
        }
    }
}