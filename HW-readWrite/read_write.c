/*
 * Author: Matt Lineback
 * HW02 Readers and Writers Problem in C using Multithreading and Semaphores
 * Date: Apr 16 2017
 * 
 */
 
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>

#define NUM_OF_READERS 5
#define NUM_READS 200
#define NUM_WRITES 200

void up(sem_t* semaphore){
	sem_post(semaphore);
}
void down(sem_t* semaphore){
	sem_wait(semaphore);
}
void* reader();
void* writer();


sem_t readerCountMutex; // the mutual exclusion semaphore for the readerCount
int readerCount=0; // number of threads reading or wanting to read

sem_t bufferMutex; // mutual exclusion semaphore for the "shared buffer"
int sharedBuffer=0; // the "shared buffer" is an int starting at 0.
                  // readers read its value and print out.
                  // writer increments the value by 1.

int main() {
   
   pthread_t readerThreads[NUM_OF_READERS];
   pthread_t writerThread;
   sem_init(&readerCountMutex,0,1);
   sem_init(&bufferMutex,0,1);
   int temp[NUM_OF_READERS];
  
   int i;
   for(i=0; i<NUM_OF_READERS; i++){
	 temp[i] = i + 1;
	 pthread_create(&readerThreads[i],0,reader,&temp[i]);
   }
   
   pthread_create(&writerThread, 0, writer,0);
   
   for(i=0; i<NUM_OF_READERS; i++){
	 pthread_join(readerThreads[i],0);
   }
   pthread_join(writerThread,0);
   sem_close(&readerCountMutex);
   sem_close(&bufferMutex);
   
   return 0;
}
void* reader(){
  int i = 0;
  while(i<NUM_READS){
	down(&readerCountMutex);
	readerCount++;
	if(readerCount == 1)down(&bufferMutex);
	  up(&readerCountMutex);
	  printf("Reader %d is reading %d\n",i,sharedBuffer);
	  down(&readerCountMutex);
	  readerCount--;
	if(readerCount == 0)up(&bufferMutex);
	  up(&readerCountMutex);
	  i++;
  }
  return 0;
}
void* writer(){
  int i = 0;
  while(i<NUM_WRITES){
	down(&bufferMutex);
	sharedBuffer++;
	printf("Writer %d is writing %d\n",i,sharedBuffer);
	up(&bufferMutex);
	i++;
  }
  return 0;
}
