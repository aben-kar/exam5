#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if(ac != 4)
        return(putchar('e'), 1);
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
                putchar('0');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}


// [EN]

// Assignment name : life
// Expected files : *.c *.h
// Allowed functions: atoi, read, putchar, malloc, calloc, realloc, free
// --------------------------------------------------------------------------------
// You must write a program that will simulate a game of life.
// The prototype of this program is the following:
// ./life width height iterations
// Width and height are the dimensions of the board and iterations is the number of
// iterations of the game of life.
// the initial configuration of the board will be drawn by a sequence of commands
// in the standard input.
// Imagine a pen starting in the top left corner of the board.
// Each command is one of these characters:

// w a s d -> move the pen up, left, bottom, and right.
// x -> lift or lower the pen in order to start or stop drawing.

// Once end of file is reached, your program must simulate a game of life on this
// board and print the result in stdout (each cell alive will be represented by
// the character 'O' and each dead cell will be represented by a space)
// each cell outside of the array will be considered dead
// Example:
// $> echo 'sdxddssaaww' | ./a.out 5 5 0 | cat -e
// $
// OOO $
// O O $
// OOO $
// $
// $> echo 'sdxssdswdxddddsxaadwxwdxwaa' | ./a.out 10 6 0 | cat -e
// $
// O OOO $
// O O $
// OOO O $
// O OOO $
// $
// $> echo 'dxss' | ./a.out 3 3 0 | cat -e
// O $
// O $
// O $
// $> echo 'dxss' | ./a.out 3 3 1 | cat -e
// $
// OOO$
// $
// $> echo 'dxss' | ./a.out 3 3 2 | cat -e
// O $
// O $
// O $
