#include <stdio.h>
#include <unistd.h>
/* 1. WAP to create pipe and print values of pipe file descriptors. */
int main()
{
    
    int pipefd[2];

    int c = pipe(pipefd);

    // printf("%d", c);
    if (c == 0)
    {
        printf("Read End : %d\n", pipefd[0]);
        printf("Write End : %d\n", pipefd[1]);
    }
    else
    {
        printf("Pipe isn't created Yet !");
    }

    return 0;
}
