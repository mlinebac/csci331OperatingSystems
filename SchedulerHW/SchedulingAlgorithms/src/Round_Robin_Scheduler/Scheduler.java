/*
 * Author: Matt Lineback
 * Course: CSCI 331 Operating Systems
 * HW: Scheduling Algorithms 
 * Purpose: Create a simple round robin scheduler and simulate the creation and management
 * of many processes using the scheduler.
 */
package Round_Robin_Scheduler;

import java.util.*;

public class Scheduler {
    
    Deque <Integer> scheduledProcs;

    //constructor intitializes everything with 0 procs
    public Scheduler(){
        this.scheduledProcs = new LinkedList<>();  
    }
    //returns the num of procs scheduled 
    public int getN(){
        return this.scheduledProcs.size();
    }
    //return true if proc with PID is in the Scheduler, false if not
    public boolean isScheduled(int PID){
        return this.scheduledProcs.contains(PID);
    }
    /* remove the process with the given PID from List of procs to schedule
    * 
    */
    void terminateProcess(int PID){
        boolean contains = isScheduled(PID);
        if (contains != true){
            System.out.println("This " + PID + " does not exist!");
        }else{
            this.scheduledProcs.remove(PID);
        }
    }
    /* add a List node with the given PID to the List of processes 
     * to schedule.
    */
    void createProcess(int PID){
        this.scheduledProcs.add(PID);
    }
    /* return the PID of the next process picked by the Scheduler 
    * the deque will have to be adjusted with an element coming off of one end and
    * going onto the other end of the deque
    */ 
    public int pickNextProcess(){
        int pickedProc = this.scheduledProcs.remove();
        this.scheduledProcs.add(pickedProc);
        return pickedProc;
    }

}//end of Scheduler Class
