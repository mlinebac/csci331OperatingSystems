/*
 * Author: Matt Lineback 
 * Lab 06 group B
 * 4/28/2017
*/
#include<stdio.h>
#include<stdlib.h>

#define NUM_ALLOC_UNITS 64

// global "bitmap" int array. each element value is the PID of the process
// that 'owns' that allocation unit. value 0 for a free unit.
int map[NUM_ALLOC_UNITS]; // 1 index per allocation unit

// void printMap() -- Don't modify this function!
// print the memory map values, indicating the process
// that owns each allocation unit of memory.
// Tabs between each value and the next. 8 values per line of output.
// At the start of each line put number of first allocation unit on the line,
// followed by a colon and a tab. Then the 8 alloc unit values
// separated by tabs.
void printMap() {
   int i;
   for(i = 0; i < NUM_ALLOC_UNITS; i++){ // all units begin free
      if(i%8 == 0) { printf("%d:\t", i); } // label at beginning of line
      printf("%d\t", map[i]); // current value
      if(i%8 == 7) { printf("\n"); } // newline every 8th item
   }
}

// int deallocate(int pid)
// Deallocate all allocation units assigned to the given pid.
// Go through all of memory, and restore all allocations units
// owned by that pid to the "free" state.
// Return the number of allocation units freed.
// If the pid is 0 or negative, do nothing and return 0 units freed.
int deallocate(int pid) {
	int i, count = 0;
	if (pid <= 0){
		return 0;
	}else{
		for(i=0; i<NUM_ALLOC_UNITS; i++){
			if (pid == map[i]){
				map[i] = 0;
				count ++;
			}	
		}
	return count;
	}
}
// int allocate(int pid, int u)
// Allocate to the given pid a section of u contiguous allocation units.
// Use "first fit" algorithm.
// Return the allocation unit number where the address space begins.
// Return -1 if:
//    u is 0 or negative
//    the pid is 0 or negative
//    memory has already been allocated to that pid.
//    the memory cannot be allocated (no free section big enough)
int allocate(int pid, int u) {
   int i;
   int startIndex=0;
   int free_sect_size = 0;   	
   if (u<=0 || pid<=0){
	  return -1;
   }
	for(i=0; i<NUM_ALLOC_UNITS; i++){
		if(pid == map[i]){  
			//printf("memory has already been allocated to that pid %d the memory cannot be allocated (no free section big enough", pid); 
			return -1;
		}
	}
	for(i=0; i<NUM_ALLOC_UNITS; i++){
		if(map[i] != 0){//not a free section
			free_sect_size = 0;
			
		}else{//enter free section here
			free_sect_size ++;
			if(free_sect_size == 1){
				for(startIndex = i; startIndex<u; startIndex++){
				map[startIndex] = pid;
				}
			}
			return -1;
		}
		
	} 
	return startIndex;	
}

// Don't modify main, please!
int main() {
   srand(time(0)); // seed random number generator

   // init the bitmap values to 0 -- memory is free initially
   int i; // loopie
   for(i = 0; i < NUM_ALLOC_UNITS; i++){ // iterate through bitmap
      map[i] = 0; // alloc unit i is free
   }

   printf("Initial memory map:\n");
   printMap();

   // Testing allocate
   int allocIndex, allocAmount;
   allocIndex = allocate(-1, 5);
   printf("Improper call to allocate. Allocation index %d should be -1.\n",
          allocIndex);
   allocIndex = allocate(5, -1);
   printf("Improper call to allocate. Allocation index %d should be -1.\n",
          allocIndex);
   allocIndex = allocate(0, 5);
   printf("Improper call to allocate. Allocation index %d should be -1.\n",
          allocIndex);
   allocIndex = allocate(5, 0);
   printf("Improper call to allocate. Allocation index %d should be -1.\n",
          allocIndex);


   for(i = 0; i < 14; i++) {
      if(i < 7)
         allocAmount = rand()%5+6; // between 6 and 10 inclusive
      else
         allocAmount = rand()%4+1; // between 1 and 4 inclusive
      allocIndex = allocate(i, allocAmount); // allocate to i
      if(allocIndex == -1) {
         printf("No memory allocated to pid %d.\n", i);
      } else { // memory was allocated to pid i
         printf("%d units allocated to pid %d starting at unit %d.\n",
                allocAmount, i, allocIndex);
      }


      if(i == 6) { // test deallocate after allocating the first 7
         printf("Memory map after allocating pid 0 through %d:\n", i);
         printMap();

         int deallocAmount, j;
         for(j = 0; j <= 8; j+=2) { // iterations for 0 2 4 6 8
            // 8 has not been allocated, and pid 0 doesn't exist
            deallocAmount = deallocate(j); // deallocate pid j
            printf("Deallocated %d units from pid %d.\n",
                   deallocAmount, j);
         }

         printf("Memory map after deallocations:\n");
         printMap();
      } // end of deallocation tests, after allocating to pid 6
   }

   printf("Memory map at the end:\n");
   printMap();

   return 0;
}
/*lab6StarterCode.c
Open with
Displaying lab6StarterCode.c.
*/
