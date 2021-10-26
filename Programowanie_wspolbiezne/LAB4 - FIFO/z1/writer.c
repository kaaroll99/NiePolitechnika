#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO1 "/tmp/fifo.1"
int main()
{
    char buff[] = "ala ma kota a kot ma ale";
    int fifo;
    if ((fifo = open(FIFO1, O_WRONLY)) < 0){
        printf("ERROR WHILE OPENING FIFO!");
    }
    if (strlen(buff) != write(fifo, buff, strlen(buff))){
        printf("BLAD ZAPISU DO PLIKU!");
    }
    close(fifo);
}