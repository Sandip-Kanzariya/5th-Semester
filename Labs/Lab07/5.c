#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h> 

int main () {
    int pipefd[2];
    pipe(pipefd);
    int pid = fork();
    if (pid > 0)  //parent
    {
        wait(NULL);
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        execl("/bin/sort", "sort", NULL);
    }
    else if (pid == 0)  //child
    {
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        char buff[1024];
        int fileFd = open("Text.txt", O_RDONLY);
        ssize_t bytesRead = read(fileFd, buff, sizeof(buff));
        write(1, buff, bytesRead);
    }
    return 0;
}