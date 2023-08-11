#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int nargs, char *args[])
{

	// Source File
	int source_fd = open(args[1], O_RDONLY);
	char source_buff[1000];
	int fp = read(source_fd, source_buff, sizeof(source_buff));

	//
	int destination_fd = open(args[2], O_WRONLY);
	printf("%d", destination_fd);

	int nu = write(destination_fd, source_buff, fp);

	return 0;
}
