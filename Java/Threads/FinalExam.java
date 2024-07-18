package Threads;
// Storage  - int 
// Counter - counter from 1 to n and stores the I value to the integer in the Storage class
// Printer - Prints the value that  was added by the counter

import java.util.Scanner;

class Storage {
    private int number ;
    private boolean isAvailable = false; // for reading

    public synchronized void store(int num) {
        while (isAvailable) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        this.number = num;
        isAvailable = true ;
        notifyAll();
    }

    public synchronized int retrieve() {
        while (!isAvailable) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        isAvailable = false;
        notifyAll();
        return number ;
    }
    
}

class Counter implements Runnable {
    private Storage storage ;
    private volatile boolean running = true; 

    public Counter(Storage storage) {
        this.storage = storage;
    }

    public void stop () {
        running = false;
    }

    @Override
    public void run() {
        int count = 1 ;
        while (running) {
            System.out.println("adding "+count + " to " + Thread.currentThread().getName());
            storage.store(count);
            count ++ ;
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }


}

class Printer implements Runnable{
    private final Storage storage;

    public Printer(Storage storage) {
        this.storage = storage;
    }

    @Override
    public void run() {
        while (true) {
            int num = storage.retrieve();

            System.out.println("from "+Thread.currentThread().getName() + " printing : "+ num);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
public class FinalExam {
    public static void main(String[] args) {
        Storage storage = new Storage();
        Counter counter = new Counter(storage);
        Printer printer = new Printer(storage);

        Thread counterThread = new Thread(counter,"counter Thread");
        Thread printerThread = new Thread(printer,"Printer thread");

        Scanner sc = new Scanner(System.in) ;
        int n = sc.nextInt();
        counterThread.start();
        printerThread.start();

        try {
            Thread.sleep(n*1000);
            counter.stop();
            System.exit(1);
        } catch (InterruptedException e) {
            System.out.printf("", e.getMessage());
        }
    }
}
