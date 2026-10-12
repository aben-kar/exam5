#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct client {
    int id;
    char message[100000];
} t_client;

t_client clients[1024];

int max = 0, next_id = 0;

fd_set active, readyRead, readyWrite;
char bafRead[424242], bfWrite[424242];