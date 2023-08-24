#include <stdio.h>
#include <unistd.h>

// 2. WAP to pass a message from parent process to child process.
int main()
{

    // Create Pipe
    int pipefd[2];
    int c = pipe(pipefd);

    int pid = fork();

    // printf("%d", pid);
    if (pid == 0)
    {
        char rd[20];
        read(pipefd[0], rd, sizeof(rd));
        printf("%s\n", rd);
    }
    else if (pid > 0)
    {

        char str[20] = "Hello, ";
        write(pipefd[1], str, sizeof(str));
    }

    return 0;
}
