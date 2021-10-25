#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define FILE_NAME_SIZE 20
#define FILE_SIZE 256

int main(){
    int fd1[2];
    int fd2[2];
    int PID;

    if(pipe(fd1) < 0){
        perror("Blad pipe\n");
    }
    if(pipe(fd2) < 0){
        perror("Blad pipe\n");
    }

    PID = fork();

    if(PID < 0){
        perror("Blad pipe\n");
    }
    else if(PID == 0){
        close(fd1[0]);
        close(fd2[1]);
        char arr[FILE_NAME_SIZE];
        char buffer[FILE_SIZE];

        int file_descriptor;
        read(fd2[0],arr,FILE_NAME_SIZE);
        printf("Potomek: \nNazwa: %s\n",arr);
        file_descriptor = open(arr, O_RDONLY);

        if(file_descriptor > 0){
            int size;
            while((size=read(file_descriptor,buffer,FILE_SIZE))){
                write(fd1[1],buffer,size);
            }
            close(file_descriptor);
        }
        else{
            char error[] = "Nie mozna otworzyc pliku";
            close(file_descriptor);
            write(fd1[1], error, sizeof(error));
        }
    }
    else{
        close(fd1[1]);
        close(fd2[0]);
        char arr[FILE_NAME_SIZE];
        char buffer[FILE_SIZE];
        scanf("%s",arr);
        write(fd2[1], arr, FILE_NAME_SIZE);
        printf("Potomek: \n");
        
        while(read(fd1[0], buffer, FILE_SIZE)){ 
            printf("%s", buffer);
        }
        close(fd1[1]);
        close(fd2[0]);
        close(fd1[0]);
        close(fd2[1]);
    return 0;
    }
    
}