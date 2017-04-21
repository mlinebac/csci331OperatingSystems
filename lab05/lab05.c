/*
 * Author: Matt Lineback
 * Lab05 pthreads Group B
 * Date: Apr 14 2107
 * 
 */
 
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>

#define N 5
#define NUM_BITES 100
#define LEFT ((i+N-1)%N)
#define RIGHT ((i+1)%N)
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N]; // state of each philosopher
sem_t mutex; // the mutual exclusion semaphore for the state array
sem_t s[N]; // semaphores for each philosopher

void up(sem_t* s){
	sem_post(s);
}
	
void down(sem_t* s){
	sem_wait(s);
}
	
void test(int i) {
   if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
      state[i] = EATING;
      up(&s[i]);
   }
}

void take_forks(int i) {
   down(&mutex);
   state[i] = HUNGRY;
   test(i);
   up(&mutex);
   down(&s[i]);
}

void put_forks(int i) {
   down(&mutex);
   state[i] = THINKING;
   test(LEFT);
   test(RIGHT);
   up(&mutex);
}

void* philosopher(void* a){
	int i;
	int philNum = *((int *) a); 
	for(i=0; i<NUM_BITES; i++){
	  take_forks(philNum);
	  printf("philosopher %d eats some food\n", philNum);
	  put_forks(philNum);
	}
	printf("philosopher %d is full\n",philNum);
	pthread_exit(0);
}
	
int main() {
   pthread_t philosophers[N];
   sem_init(&mutex,0,1);
   
   int i;
   for(i=0; i<N; i++){
	 state[i] = 0;
	 sem_init(&s[i],0,0);
   }
  
   for (i=0; i<N; i++){
     int *temp = (int *) malloc(sizeof(int *));
     *temp = i;
     pthread_create(&philosophers[i], 0, philosopher, (void *) temp);
	}
	
   for (i=0; i<N; i++){
	 pthread_join(philosophers[i], 0);
   }
   
   for (i=0; i<N; i++){
     sem_close(&s[i]);
   }
   
   return 0;
}
