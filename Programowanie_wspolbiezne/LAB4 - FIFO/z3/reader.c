#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO1 "/tmp/fifo.1"
#define SIZE 50
int main()
{
    char buffer[SIZE];
    int fifo;
    if ((fifo = open(FIFO1, O_RDONLY)) < 0)
    {
        printf("ERROR WHILE OPENING FIFO!");
    }
    int data = read(fifo,buffer,SIZE);
    buffer[data]='\0';
    printf("%s\n",buffer);
    close(fifo);
    unlink(FIFO1);
}