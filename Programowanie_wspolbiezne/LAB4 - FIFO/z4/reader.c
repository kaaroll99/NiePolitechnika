#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"
#define SIZE 50

void signal_callback_handler(int signum)
{
    printf("Closing program! %d", signum);
    unlink(FIFO1);
    unlink(FIFO2);
    exit(1);
}
int main()
{
    char buffer[SIZE];
    int fifo;
    int fifo1;

    signal(SIGINT, signal_callback_handler);

    if ((mkfifo(FIFO2, 0777)) < 0)
    {
        perror("ERROR WHILE CREATING FIFO!");
    }
    while(1){
    if ((fifo = open(FIFO1, O_RDONLY)) < 0)
    {
        //printf("ERROR WHILE OPENING FIFO!");
        exit(1);
    }
    int data = read(fifo,buffer,SIZE);
    buffer[data]='\0';
    printf("%s\n",buffer);
    close(fifo);
    if ((fifo1 = open(FIFO2, O_WRONLY)) < 0)
    {
        //printf("ERROR WHILE OPENING FIFO!");
        exit(1);
    }
    scanf("%s",buffer);
    if (strlen(buffer) != write(fifo1, buffer, strlen(buffer)))
    {
        printf("BLAD ZAPISU DO PLIKU!");
    }
    }
    close(fifo1);
}