#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int waiting;
sem_t customers, barbers, mutex;

#define CHAIRS 5

void *barber(){
   // printf("Barber\n");
   while(1){
       // Down
       sem_wait(&customers);
       sem_wait(&mutex);

       waiting--;

       // Up
       sem_post(&barbers);
       sem_post(&mutex);

       // process
       printf("Cut Hair : B\n");
   }

   return NULL;
}


void *customer(){

   // printf("customer\n");   
   // down
   sem_wait(&mutex);

   if(waiting < CHAIRS){
       waiting = waiting + 1;

       // up
       sem_post(&customers);
       sem_post(&mutex);


       // printf("customer");   
       // down
       sem_wait(&barbers);


       // process
       printf("Get Hair Cut : C\n");
   }
   else{
       //
       sem_post(&mutex);
   }

   return NULL;
}

int main(){

    // initilize
   int customersi = sem_init(&customers, 0, 1); // 0
   int barbersi = sem_init(&barbers, 0, 1); // 0
   int mutexi = sem_init(&mutex, 1, 1); // 1

   waiting = 0;
  
    // Cretate Threads
   pthread_t  b, c[5];

   int tb = pthread_create(&b, NULL, barber, NULL);

   for(int i = 0;i < 5;i++){
      int tc = pthread_create(&c[i], NULL, customer, NULL);
   }

   int jb = pthread_join(b, NULL);

   // Join
   for(int i = 0;i < 5;i++){
      int jc = pthread_join(c[i], NULL);
   }

  return 0;
}
