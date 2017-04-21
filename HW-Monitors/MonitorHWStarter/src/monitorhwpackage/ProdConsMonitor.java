package monitorhwpackage;

public class ProdConsMonitor {

    // data fields for the shared buffer, a stack of fixed size based on the
    // static final BUFFER_SIZE in HWMain.
    // Use an array of that length, and an index for the top index
    // which contains an item.
    
    // You will also want to keep track of how many times
    // the insert blocks, and how many times the remove blocks.
    
    // The constructor initializes all data fields
    
    // insert an int value into the buffer
    public synchronized void insert(int value) {
        if (/* buffer full*/) { // buffer is full; can't insert.
            // note that we are blocking during insert
            goToSleep();
        }
        //critical section code here. insert into the stack and adjust the index

        if (/* previously empty buffer now has just 1 item */) { // we just inserted the only item into a previously empty buffer
            notify(); // wake a sleeping thread that waited from inside this monitor
        }
    }

    // remove an item from the buffer, and return its value as an int
    public synchronized int remove() {

        if (/* buffer empty */) { // buffer is empty -- nothing to remove
            // note that we are blocking during remove
            goToSleep();
        }

        // critical section code here. remove item from buffer and adjust the index
        if (/* if the buffer is exactly one element empty */) { // we just removed an item from a previously full buffer
            notify(); // wake a sleeping thread that waited from inside this monitor
        }

        // finally, return the item that was taken from the buffer
    }

    // Jacketing for thread wait. DO NOT MODIFY
    private synchronized void goToSleep() {
        try {
            wait();
        } catch (InterruptedException e) {
            // do nothing
        }
    }

    // Make public synchronized getter methods for the number of times insert has blocked,
    // and the number of times remove has blocked.
}
