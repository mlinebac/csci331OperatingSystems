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
    
    public static void main(String[] args) {
        int proc;
        Scheduler schedule = new Scheduler();
        for(int i=0; i<SIZE; i++){
            schedule.createProcess(i);
        }
        for(int i=30; i<SIZE*2; i++){
            proc = schedule.pickNextProcess();
            System.out.println("Process " + proc + " was picked");
            schedule.createProcess(i);
            System.out.println("Process " + i + " was created");
            proc = schedule.pickNextProcess();
            System.out.println("Process " + proc + " was picked");
            schedule.terminateProcess(proc);
            System.out.println("Process " + proc + " was terminated");
        }  
    }
}

