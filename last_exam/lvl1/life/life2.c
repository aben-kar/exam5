#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// y * with + x (y == height) (x == with)

int count_nighboors(int *board, int x, int y, int w, int h)
{
    int count = 0;
    for(int dy = -1; dy <= 1; dy++){
        for(int dx = -1; dx <= 1; dx++){
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < w && ny >= 0 && ny < h){
                if (board[ny * w + nx])
                    count++;
            }
        }
    }
    return count;
}

int main(int ac, char **av){

    if (ac != 4)   return 0;

    int w = atoi(av[1]);
    int h = atoi(av[2]);
    int iters = atoi(av[3]);

    if (w <= 0 || h <= 0 || iters < 0) return 0;
    int *board = (int *)calloc(w * h, sizeof(int));
    if (!board) return 0;

    // pen
    int px = 0, py = 0;
    int down = 0;
    char c;

    while (read(0, &c, 1) > 0)
    {
        if (c == 'x'){
            down = !down;
            if (down)
            {
                board[py * w + px] = 1;
            } 
            
        }
        else if (c == 'w' || c == 's' || c == 'a' || c == 'd'){
            if (c == 'w' && py > 0) py--;
            if (c == 's' && py < h- 1) py++;
            if (c == 'a' && px > 0) px--;
            if (c == 'd' && px < w - 1)px++;

            if (down)
            {
                board[py * w + px] = 1;
            } 
        }
    }
    for (int i = 0; i < iters; i++){
        int *next = (int *)calloc(w * h, sizeof(int));
        if (!next){
            free(board);
            return 0;
        }
        for (int y = 0; y < h; y++){
            for(int x = 0; x < w; x++){
                int n = count_nighboors(board, x , y, w, h);
                int alive = board[y * w + x];

                if (alive){
                    if (n == 2 || n == 3){
                        next[y * w + x] = 1;
                    }
                }
                else if (n == 3){
                    next[y * w + x] = 1;
                }
            }
        }
        free(board);
        board = next;
    }

    for (int  y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++){
            if(board[y * w + x]){
                putchar('O');
            }
            else{
                putchar(' ');
            }
        }
        putchar('\n');
    }
    free(board);
    return 0;
}