/*
 * Author: Matt Lineback
 * Course: CSCI 331 Operating Systems
 * HW: Scheduling Algorithms 
 * Purpose: Create a simple lottery scheduler and simulate the creation and management
 * of many processes using the scheduler.
 */
package Round_Robin_Scheduler;

/*
* Construct a Scheduler object, and create at least 20 "processes" 
* with unique PIDs, initially. Remember, this is just a simulation. 
* You're not literally creating processes; you're just invoking the createProcess
* method with some int arguments.
* Then, invoke pickNextProcess at least 20 times, 
* interspersed with at least 5 calls to terminateProcess and 5 to createProcess
* with new unique PIDs; the list of processes being scheduled changes somewhat 
* "over time" as new processes keep being picked.
* When any process is created, picked, or terminated, have the main method 
* print the PID in a descriptive print statement, e.g. "Process 43 was terminated."
*/
public class TestMain {

    public static final int SIZE = 20;
    
    public static void printNextProcPicked(Scheduler schedule){
        int proc;
        proc = schedule.pickNextProcess();
        System.out.println("Process " + proc + " was picked");
    }
    public static void printProcCreated(Scheduler schedule, int proc){
        schedule.createProcess(proc);
        System.out.println("Process " + proc + " was created");
    }
    public static void printProcTerminated(Scheduler schedule, int proc){
        schedule.terminateProcess(proc);
        System.out.println("Process " + proc + " was terminated");
    }
    
    public static void main(String[] args) {
        int proc;
        Scheduler schedule = new Scheduler();
        for(int i=0; i<SIZE; i++){
            schedule.createProcess(i);
        }
        printNextProcPicked(schedule);
        printNextProcPicked(schedule);
        printProcTerminated(schedule,0);
        printNextProcPicked(schedule);
        printProcCreated(schedule,21);
        printNextProcPicked(schedule);
        printProcTerminated(schedule,11);
        printNextProcPicked(schedule);
        printNextProcPicked(schedule);
        printProcCreated(schedule,22);
        printNextProcPicked(schedule);
        printProcTerminated(schedule,5);
        printNextProcPicked(schedule);
        printNextProcPicked(schedule);
        printProcCreated(schedule,25);
        printNextProcPicked(schedule);
        printProcTerminated(schedule,21);
        printNextProcPicked(schedule);
        printProcCreated(schedule,23);
        printNextProcPicked(schedule);
        printProcTerminated(schedule,1);
        printNextProcPicked(schedule);
        printProcCreated(schedule,24);
        printNextProcPicked(schedule);
        printNextProcPicked(schedule);
        printProcTerminated(schedule,18);
        printNextProcPicked(schedule);
        printNextProcPicked(schedule);
        printNextProcPicked(schedule);
        printNextProcPicked(schedule);
        printNextProcPicked(schedule);
        
       
        
    }
}

