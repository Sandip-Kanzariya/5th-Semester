#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
	
int main(int nargs, char *args[]){
    
    // Source File 
	int source_fd = open(args[1], O_RDONLY);
	char source_buff[1000];
	int fp = read(source_fd, source_buff, sizeof(source_buff));
	
    
    // 
	int destination_fd = open(args[2], O_WRONLY | O_CREAT);
	int nu = write(destination_fd, source_buff, fp);

	return 0;
}
