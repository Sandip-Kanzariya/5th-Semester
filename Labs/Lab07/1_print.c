#include <stdio.h>
#include <fcntl.h> 
#include <sys/types.h> 
#include <stdlib.h>
#include <unistd.h> 
int main(){

    int fd = open("Text.txt", O_WRONLY);
    printf("Old File descriptor  : %d\n", fd);
    printf("Hello, This is From STDIO Printf");
    
    // Change File Descriptor Of file by 1 which is deafult of printf()
    int newfd = dup2(fd, 1);
    printf("Hello, This is From STDIO Printf");

    return 0;
}