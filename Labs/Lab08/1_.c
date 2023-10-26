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


       char path[100] = "/bin/";
       strcat(path, args[1]);
       char *options [10] = {NULL};
       options[0] = __FILE__;
      
       for(int i = 2;i < n;i++){
           options[i - 1] = args[i];
       }
       options[n] = NULL;


       int ex = execv(path, options);


       if(ex == -1){
           printf("Invalid Command.\n"); 
       }
   }
   else if(pid > 0){ // Parent
       wait(0);
   }


   return 0;  
}  
