package Threads;

import java.util.*;

class SharedResource {
    private boolean isFirstThreadTurn = true;

    public synchronized void runFirstThread() {
        while (!isFirstThreadTurn) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        // Perform the first thread's tasks
        for (int i = 0; i < 10; i++) {
            System.out.println(Thread.currentThread().getName() + " - first thread " + i);
        }
        isFirstThreadTurn = false;
        notifyAll();
    }

    public synchronized void runSecondThread() {
        while (isFirstThreadTurn) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        // Perform the first thread's tasks
        for (int i = 0; i < 10; i++) {
            System.out.println(Thread.currentThread().getName() + " - second thread " + i);
        }
        isFirstThreadTurn = true;
        notifyAll();
    }
}

class FirstRunnable implements Runnable {
    private final SharedResource sharedResource;

    public FirstRunnable(SharedResource sr) {
        this.sharedResource = sr;
    }

    @Override
    public void run() {
        for(int i = 0 ; i <2 ;i ++){sharedResource.runFirstThread();}
   }
}

class SecondRunnable implements Runnable {
    private final SharedResource sharedResource;

    public SecondRunnable(SharedResource sr) {
        this.sharedResource = sr;
    }

    @Override
    public void run() {
        for(int i = 0 ; i <2 ;i ++){ sharedResource.runSecondThread();}
    }
}

public class Implementation {
    public static void main(String[] args) {
        SharedResource sr = new SharedResource();
        Thread t1 = new Thread(new FirstRunnable(sr), "Thread - 1");
        Thread t2 = new Thread(new SecondRunnable(sr), "Thread - 2");

        try {
            t1.start();
            t2.start();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

}
