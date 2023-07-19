#include <stdio.h>
#include <unistd.h>

int main(){

    int n = write(1, "Hellohha\n", 3);
   	 
    return 0;
}
