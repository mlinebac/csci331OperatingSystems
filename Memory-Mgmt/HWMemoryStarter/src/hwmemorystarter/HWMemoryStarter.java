package hwmemorystarter;

import java.util.LinkedList;

public class HWMemoryStarter {

    public static void main(String[] args) {
        //Create a memory manager object, allocate address spaces for several
        //processes, then print the memory map.
        MemoryManager manager = new MemoryManager(10);
        manager.allocate(1,10);
        manager.printMap();
        //Deallocate a few address spaces, and print the memory map again.
        manager.deallocate(1);
        manager.printMap();
        /*Allocate a few smaller address spaces, which will end up being
         *allocated in between larger, already allocated address spaces, then
         *print the memory map again.
         */
        manager.allocate(1,5);
        manager.allocate(2,4);
        manager.printMap();
        /*Please label each of your memory map printouts with a description of the
         current situation, so the reader of the console has context for the 
         status of the memory map at that point, e.g.
         "Just deallocated pids 35 44 and 51. Printing the memory map."
        */
    }

}
