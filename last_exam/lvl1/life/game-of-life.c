#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if(ac != 4)
        return(putchar('e'), 1);
        // change with and hight.
    int height = atoi(av[1]);
    int width = atoi(av[2]);
    int it = atoi(av[3]);

    int array[2][width + 2][height + 2];
    for(int i = 0; i < 2; i++)
    {
        for(int h = 0; h < height + 2; h++)
        {
            for(int w = 0; w < width + 2; w++)
            {
                array[i][w][h] = 0;
            }
        }
    }

    int x = 1;
    int y = 1;
    int pen = 0;
    char cmd;
    while(read(0, &cmd, 1) > 0)
    {
        if(cmd == 'w' && y > 1)
            y--;
        else if(cmd == 'a' && x > 1)
            x--;
        else if(cmd == 's' && y < height)
            y++;
        else if(cmd == 'd' && x < width)
            x++;
        else if(cmd == 'x')
            pen = !pen;
        if(pen)
            array[0][x][y] = 1;
    }

    for(int iter = 0; iter < it; iter++)
    {
        for(int h = 1; h <= height; h++)
        {
            for(int w = 1; w <= width; w++)
            {
                int nb = 0;
                for(int dy = -1; dy <= 1; dy++)
                {
                    for(int dx = -1; dx <= 1; dx++)
                    {
                        if(!(dx == 0 && dy == 0))
                            nb += array[iter % 2][w + dx][h + dy];
                    }
                }
                if(array[iter%2][w][h] == 1)
                {
                    if(nb == 2 || nb == 3)
                        array[(iter + 1) % 2][w][h] = 1;
                    else
                        array[(iter + 1) % 2][w][h] = 0;
                }
                else
                {
                    if(nb == 3)
                        array[(iter + 1) % 2][w][h] = 1;
                    else
                        array[(iter + 1) % 2][w][h] = 0;
                }
            }
        }
    }

    for(int h = 1; h <= height; h++)
    {
        for(int w = 1; w <= width; w++)
        {
            if(array[it % 2][w][h])
                putchar('O');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}
