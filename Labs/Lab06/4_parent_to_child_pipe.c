#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

/**4. WAP to pass file name from parent process to child process and
 *  the child process should display file contents.
 */
 
// Run Using This 
// ./a.out file.txt

int main(int n, char *args[])
{

    // // Create Pipe
    int parentToChildPipe[2];
    int pc = pipe(parentToChildPipe);


    int pid = fork();

    // printf("%d", pid);
    
    if (pid == 0) // Child
    {
        // get file name which is pass by Parent
        char file[20];
        read(parentToChildPipe[0], file, sizeof(file));

        // Open File which is pass by Parent
        char fileContain[100];
        int fd = open(file, O_RDONLY);
        int fp = read(fd, fileContain, sizeof(fileContain));

        printf("%s", fileContain);

    }
    else if (pid > 0) // Parent
    {

        // Pass File Name from Parent to Child
        write(parentToChildPipe[1], args[1], 100);
    }

    return 0;
}
