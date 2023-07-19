#include <stdio.h>
#include <unistd.h>

int main(){

    char b[100];
    
    int n = read(0, b, sizeof(b));
        
    int m = write(1, b, n);
    
    return 0;
}
