#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int n, char *args[]){
    if(n == 1){
      printf("Invalid Command !\n");
      return 0;
  }


   int pid = fork();


   if(pid == 0){ // Child
       if(n == 1){
           printf("Error\n"); 
           return 0;
       }


       char path[100] = "/bin/";
       strcat(path, args[1]);
       execl(path, args[1], NULL);


   }
   else if(pid > 0){ // Parent
       wait(0);
   }


      
   return 0;
}  
