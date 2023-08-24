#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
/***
 * 5. WAP to pass file name from parent process to child process and
 *   the child process should write file contents in another pipe.
 * 
*/
 

// Run Using This 
// ./a.out file.txt

int main(int n, char *args[])
{

    // // Create Pipe
    int parentToChildPipe[2];
    int pc = pipe(parentToChildPipe);

    int childToParentPipe[2];
    int cp = pipe(childToParentPipe);

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

        // Now, Put that content to ChildToParent Pipe
        write(childToParentPipe[1], fileContain, sizeof(fileContain));
    }
    else if (pid > 0) // Parent
    {

        // Pass File Name from Parent to Child
        write(parentToChildPipe[1], args[1], 100);

        wait(0);
        // Get content of file which is read by Child
        char filePass[100];
        read(childToParentPipe[0], filePass, sizeof(filePass));
        printf("%s Contain : \n %s\n", args[1], filePass);
    }

    return 0;
}
