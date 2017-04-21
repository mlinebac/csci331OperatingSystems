//Author: Matt Lineback
//CSCI 331 OS Lab sec B
//March 31 2017

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define NUM_ITEMS 10000000
#define BUFFER_SIZE 1000

pthread_mutex_t theMutex;
pthread_cond_t condProducer, condConsumer;

int buffer [BUFFER_SIZE];
int buffer_top = 0;

// The producer runs this code.
void* producerCode(void* ptr) {
  srand(time(NULL));
  int i,rand_num;
  for(i = 1; i <= NUM_ITEMS; i++) { // one iteration per item to produce
    pthread_mutex_lock(&theMutex);
    
    while(buffer_top == BUFFER_SIZE-1) {
	 printf("producer is waiting %d\n", i); 
     pthread_cond_wait(&condProducer, &theMutex);
    }
    rand_num = rand() % 11;
	buffer_top++;
	buffer[buffer_top] = rand_num;
	
    // critical region. produce an item for the shared buffer.
    pthread_cond_signal(&condConsumer);
    pthread_mutex_unlock(&theMutex);
  }
  pthread_exit(0);
}

// The consumer runs this code.
void* consumerCode(void* ptr) {
  int i, value = 0;
  for(i = 1; i <= NUM_ITEMS; i++) { // one iteration per item to produce
    pthread_mutex_lock(&theMutex);
    while(buffer_top == -1) {
      printf("consumer is waiting %d\n",i);
      pthread_cond_wait(&condConsumer, &theMutex);
    }
    value += buffer[buffer_top];
    buffer_top --;
    // critical region. consume an item from the shared buffer.

    pthread_cond_signal(&condProducer);
    pthread_mutex_unlock(&theMutex);
  }
  printf("total value %d\n", value);
  pthread_exit(0);
}

int main () {
  pthread_t producer, consumer;

  pthread_mutex_init(&theMutex, 0);
  pthread_cond_init(&condConsumer, 0);
  pthread_cond_init(&condProducer, 0);

  pthread_create(&consumer, 0, consumerCode, 0);
  pthread_create(&producer, 0, producerCode, 0);
  pthread_join(producer, 0);
  pthread_join(consumer, 0);

  pthread_cond_destroy(&condProducer);
  pthread_cond_destroy(&condConsumer);
  pthread_mutex_destroy(&theMutex);
  return 0;
}


