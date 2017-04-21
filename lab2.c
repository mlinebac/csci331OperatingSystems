//Matt Lineback
//CSCI 331 lab02


#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h>
#include<time.h>
#include<wait.h>
#include<stdlib.h> 

#define ARRAY_SIZE 50000

void bubble_sort(int *myArray, int n);

int main(){

	long int start_time=0;
	long int finish_time=0;
	int i;
	long int elasped_time=0;
	

	pid_t forked_pid = fork();
	int* my_array = (int*)malloc(sizeof(int)*100);
	
	for(i=0; i<ARRAY_SIZE; i++){
		srand((unsigned) time(NULL));
		my_array[i] = rand();
	}
	time(&start_time);
	bubble_sort(my_array, ARRAY_SIZE);
		
		if(forked_pid == 0){
			time(&finish_time);
			elasped_time = finish_time - start_time;
			printf("this is the CHILD process elasped time: %ld\n", elasped_time);
		
		 }else{
			bubble_sort(my_array, ARRAY_SIZE);
			time(&finish_time);
			elasped_time = finish_time - start_time;
			printf("this is the PARENT elasped time: %ld\n",elasped_time);
		
		}
	wait(NULL);
	free(my_array);
return 0;
}

void bubble_sort(int *myArray, int n){
	int i,j,temp;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
	 		if(myArray[j] > myArray[j+1]){
	  			temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
	  		}
	 	}
	}
}
