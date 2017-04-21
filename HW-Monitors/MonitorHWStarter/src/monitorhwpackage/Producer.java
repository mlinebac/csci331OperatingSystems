package monitorhwpackage;

public class Producer extends Thread {

    @Override
    public void run() {
        for (int i = 0; i < HWMain.NUM_ITEMS; i++) {
            // insert a random number between 0 and 10 inclusive into the monitor
            // You should use Math.random() to get a random number, then adjust the range
        }
    }

}
