#include <stdio.h>
#include <unistd.h>


// 3. WAP to pass a message from child process to parent process.
int main()
{

    // Create Pipe
    int pipefd[2];
    int c = pipe(pipefd);

    int pid = fork();

    // printf("%d", pid);
    if (pid == 0) // Child
    {

        char str[20] = "Hello, ";
        write(pipefd[1], str, sizeof(str));

    }
    else if (pid > 0) // Parent
    {
        char rd[20];
        read(pipefd[0], rd, sizeof(rd));
        printf("%s\n", rd);
    }

    return 0;
}
