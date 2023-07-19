#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int nargs, char *args[])
{

    int fd = open(args[1], O_RDONLY);
    
    char bf[1000];
    int fp = read(fd, bf, sizeof(bf));

    int c = close(fd);
    int nu = write(1, bf, fp);
    printf("\n");
    return 0;
}
