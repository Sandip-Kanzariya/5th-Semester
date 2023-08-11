#include<stdio.h>
#include<pthread.h>


void * fun1(){


   printf("Hello, From Thread-1\n");


   return NULL;
}


void * fun2(){


   printf("Hello, From Thread-2\n");


   return NULL;
}


int main(){


   pthread_t t1, t2;


   int p1 = pthread_create(&t1, NULL, fun1, NULL);
   int p2 = pthread_create(&t2, NULL, fun2, NULL);
  
   int j1 = pthread_join(t1, NULL);
   int j2 = pthread_join(t2, NULL);


   return 0;
}
