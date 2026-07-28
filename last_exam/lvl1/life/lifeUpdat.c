#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac != 4)
        return (putchar('e'), 1);

    // FIX 1: av[1] is width, av[2] is height (swapped compared to your version)
    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int it = atoi(av[3]);

    // Handle invalid negative or zero dimensions safely
    if (width <= 0 || height <= 0 || it < 0)
        return 1;

    // FIX 2: Dynamic Allocation instead of VLA to avoid Stack Overflow
    // 1. Cast l- `int ***`
    int ***array = (int ***)malloc(2 * sizeof(int **));
    if (!array) return 1;

    for (int i = 0; i < 2; i++)
    {
        // 2. Cast l- `int **`
        array[i] = (int **)malloc((width + 2) * sizeof(int *));
        if (!array[i]) return 1;

        for (int w = 0; w < width + 2; w++)
        {
            // 3. Cast l- `int *`
            array[i][w] = (int *)calloc((height + 2), sizeof(int));
            if (!array[i][w]) return 1;
        }
    }

    int x = 1;
    int y = 1;
    int pen = 0;
    char cmd;

    while (read(0, &cmd, 1) > 0)
    {
        // Pen moves freely, even out of bounds!
        if (cmd == 'w')
            y--;
        else if (cmd == 'a')
            x--;
        else if (cmd == 's')
            y++;
        else if (cmd == 'd')
            x++;
        else if (cmd == 'x')
            pen = !pen;

        // FIX 3: Draw ONLY if pen is down AND inside the actual board bounds
        if (pen && x >= 1 && x <= width && y >= 1 && y <= height)
            array[0][x][y] = 1;
    }

    // Game of life logic (kept your logic, it works beautifully)
    for (int iter = 0; iter < it; iter++)
    {
        for (int h = 1; h <= height; h++)
        {
            for (int w = 1; w <= width; w++)
            {
                int nb = 0;
                for (int dy = -1; dy <= 1; dy++)
                {
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        if (!(dx == 0 && dy == 0))
                            nb += array[iter % 2][w + dx][h + dy];
                    }
                }
                if (array[iter % 2][w][h] == 1)
                {
                    if (nb == 2 || nb == 3)
                        array[(iter + 1) % 2][w][h] = 1;
                    else
                        array[(iter + 1) % 2][w][h] = 0;
                }
                else
                {
                    if (nb == 3)
                        array[(iter + 1) % 2][w][h] = 1;
                    else
                        array[(iter + 1) % 2][w][h] = 0;
                }
            }
        }
    }

    // Printing loop
    for (int h = 1; h <= height; h++)
    {
        for (int w = 1; w <= width; w++)
        {
            // FIX 4: Changed '0' to 'O' as specified in the subject
            if (array[it % 2][w][h])
                putchar('O');
            else
                putchar(' ');
        }
        putchar('\n');
    }

    // FIX 5: Clean up memory (Free everything to avoid Leaks)
    for (int i = 0; i < 2; i++)
    {
        for (int w = 0; w < width + 2; w++)
        {
            free(array[i][w]);
        }
        free(array[i]);
    }
    free(array);

    return 0;
}