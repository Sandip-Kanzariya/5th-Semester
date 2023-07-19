#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int nargs, char *args[])
{

    for (int i = 1; i < nargs; i++)
    {   
        int fd = open(args[i], O_RDONLY);

        char bf[10000];
        int fp = read(fd, bf, sizeof(bf));

        int c = close(fd);
        int nu = write(1, bf, fp);
        printf("\n----------------------------------\n");
    }


    return 0;
}
