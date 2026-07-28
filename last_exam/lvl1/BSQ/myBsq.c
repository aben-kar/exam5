#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_map
{
    int     nb;
    int     cols;
    int     **dp;
    char    empty;
    char    obs;
    char    full;
    char    **m;
} t_map;

int ft_strlen(char *str)
{
    int i = 0;
    while (str && str[i]) i++;
    return (i);
}

void free_map(t_map *m)
{
    if (!m) return;
    if (m->m) {
        for (int i = 0; i < m->nb; i++) free(m->m[i]);
        free(m->m);
    }
    if (m->dp) {
        for (int i = 0; i < m->nb; i++) free(m->dp[i]);
        free(m->dp);
    }
}

int pars(FILE *f, t_map *m)
{
    char *line = NULL;
    size_t len = 0;
    
    if (!f || getline(&line, &len, f) <= 0) {
        free(line);
        return (0);
    }

    // Parse header: [nb] [empty] [obs] [full]\n
    int i = 0;
    m->nb = 0;
    while (line[i] >= '0' && line[i] <= '9') {
        m->nb = m->nb * 10 + (line[i] - '0');
        i++;
    }

    if (m->nb <= 0 || line[i] != ' ') { free(line); return (0); }
    m->empty = line[++i];
    if (line[++i] != ' ') { free(line); return (0); }
    m->obs = line[++i];
    if (line[++i] != ' ') { free(line); return (0); }
    m->full = line[++i];
    if (line[++i] != '\n') { free(line); return (0); }

    // Check distinct chars
    if (m->empty == m->obs || m->empty == m->full || m->obs == m->full) {
        free(line); return (0);
    }

    free(line); line = NULL;

    m->m = (char **)malloc(sizeof(char *) * m->nb);
    m->dp = (int **)malloc(sizeof(int *) * m->nb);
    m->cols = -1;

    for (int r = 0; r < m->nb; r++)
    {
        if (getline(&line, &len, f) <= 0) {
            free(line); free_map(m); return (0);
        }

        int row_len = 0;
        while (line[row_len] && line[row_len] != '\n') row_len++;
        if (line[row_len] != '\n' || row_len == 0) {
            free(line); free_map(m); return (0);
        }

        if (m->cols == -1) m->cols = row_len;
        else if (m->cols != row_len) {
            free(line); free_map(m); return (0);
        }

        m->m[r] = (char *)malloc(sizeof(char) * (m->cols + 1));
        m->dp[r] = (int *)malloc(sizeof(int) * m->cols);

        for (int c = 0; c < m->cols; c++) {
            if (line[c] != m->empty && line[c] != m->obs) {
                free(line); free_map(m); return (0);
            }
            m->m[r][c] = line[c];
        }
        m->m[r][m->cols] = '\0';
    }

    // Check for extra unexpected lines
    if (getline(&line, &len, f) > 0) {
        free(line); free_map(m); return (0);
    }

    free(line);
    return (1);
}

int min3(int a, int b, int c)
{
    if (a <= b && a <= c) return (a);
    if (b <= a && b <= c) return (b);
    return (c);
}

void bsq(t_map *m)
{
    int max = 0, max_i = 0, max_j = 0;

    for (int i = 0; i < m->nb; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            if (m->m[i][j] == m->obs)
                m->dp[i][j] = 0;
            else if (i > 0 && j > 0)
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
    if (ac == 1)
    {
        t_map m = {0};
        if (!pars(stdin, &m))
            fprintf(stderr, "map error\n");
        else
        {
            bsq(&m);
            free_map(&m);
        }
    }
    else
    {
        for (int i = 1; i < ac; i++)
        {
            FILE *f = fopen(av[i], "r");
            t_map m = {0};
            if (!f || !pars(f, &m))
                fprintf(stderr, "map error\n");
            else
            {
                bsq(&m);
                free_map(&m);
            }
            if (f) fclose(f);
            if (i < ac - 1) printf("\n");
        }
    }
    return (0);
}