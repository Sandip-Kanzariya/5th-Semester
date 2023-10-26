#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h> 
int main(){

    int fd = open("Text.txt", O_RDONLY);
    printf("Old File descriptor  : %d\n", fd);
    int newfd = dup(fd);
    printf("New File descriptor : %d\n", newfd);
    return 0;
}