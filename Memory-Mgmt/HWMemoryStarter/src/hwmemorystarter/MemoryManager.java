package hwmemorystarter;

import java.util.LinkedList;

public class MemoryManager {

    // -----data fields-----
    private final int memorySize; // number of allocation units in "memory"
    private LinkedList<MemorySection> list; // The memory map, as a linked list.
    // Each MemorySection node in the list is a free section or an address space.

    // -----constructors-----
    /**
     * Constructor of MemoryManager class.
     *
     * @param memorySize The number of allocation units in the simulated memory.
     * Must be 1 or greater.
     */
    public MemoryManager(int memorySize) {
        if (memorySize < 1) {
            System.err.println("MemoryManager constructor, invalid memorySize "
                    + memorySize);
        }
        this.memorySize = memorySize;
        list = new LinkedList<>();
        list.add(new MemorySection(0, memorySize));
        // the memory map, upon initial construction, consists of:
        // 1 free section, starting at allocation unit 0, size memorySize
    }

    // -----other class methods-----
    /**
     * Use first fit swapping memory management algorithm to allocate an address
     * space for the given pid, consisting of u allocation units.
     *
     * @param pid PID of process whose address space you wish to deallocate.
     * Must be greater than 0. This process must not already have an address
     * space allocated.
     * @param u Number of allocation units for this process's address space.
     * Must be 1 or greater.
     * @return The allocation unit number where the allocated address space
     * begins. Returns -1 if u is 0 or negative, the pid is 0 or negative,
     * memory has already been allocated to that pid, or the memory cannot be
     * allocated (i.e. no free section big enough)
     */
    public int allocate(int pid, int u){
        MemorySection newNode;
        int freeSection;
        if(u <= 0 || pid <= 0){
            return -1;
        }
        for(int i = 0; i < list.size()-1; i++){
            if(pid == list.get(i).getOwnerPid()){
                return -1;
            }else{
                if(u == list.get(i).getSize()){
                    list.get(i).setOwnerPid(pid);
                }
                if(u >= list.get(i).getSize()){
                    freeSection = list.get(i).getSize();
                    freeSection -= u;
                    list.get(i).setSize(freeSection);
                    freeSection += list.get(i).getStart();
                    newNode = new MemorySection(freeSection,u,pid);
                    list.add(newNode);
                    return freeSection;
                }
            }
        }
        return -1;
    }
    
    /**
     * Deallocate an address space.
     *
     * @param pid PID of process whose address space you wish to deallocate.
     * Must be greater than 0
     * @return The number of allocation units freed. If the pid is 0 or
     * negative, do nothing and return 0 units freed.
     */
    // public int deallocate(int pid)
    
    /**
     * Prints out this memory map, one memory section at a time. Iterates
     * through the MemorySection nodes and prints each one.
     */
    public void printMap(){
        for(int i = 0; i < this.list.size(); i++){
            System.out.println(this.list.get(i));
        }
    }
    
    // -----getter methods-----
    /**
     * memorySize getter method.
     *
     * @return The number of allocation units in this memory manager's "memory."
     */
    public int getMemorySize(){
        return this.memorySize;
    }
    
    /**
     * Determine where the address space of the given pid starts.
     *
     * @param pid Process PID you are querying. Must be greater than 0.
     * @return The allocation unit number where this process's address space
     * starts. Returns -1 if this pid has no address space.
     */
    // public int getAddressSpaceStart(int pid)
    
    /**
     * Get the size of a process's address space.
     *
     * @param pid Process PID you are querying. Must be greater than 0.
     * @return The number of allocation units in this process's address space.
     * Returns 0 if this pid has no address space.
     */
   // public int getAddressSpaceSize(int pid)
        
}
