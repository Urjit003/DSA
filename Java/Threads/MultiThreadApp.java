package Threads;

import java.util.Scanner;

class PrimeThread extends Thread {
    private int sleepTime;
    private volatile boolean running = true;
    private final Object t1Monitor;

    public PrimeThread(int sleepTime, Object t1Monitor) {
        this.sleepTime = sleepTime;
        this.t1Monitor = t1Monitor;
    }

    public void stopRunning() {
        running = false;
    }

    @Override
    public void run() {
        int num = 2;
        while (running) {
            if (isPrime(num)) {
                System.out.println("PrimeThread - Prime: " + num);
                if (num == 13 || num == 79) {
                    synchronized (t1Monitor) {
                        t1Monitor.notify();
                    }
                }
            }
            num++;
            try {
                Thread.sleep(sleepTime);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        System.out.println("PrimeThread exiting...");
    }

    private boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

class T1Thread extends Thread {
    private volatile boolean running = true;
    private final Object t1Monitor;

    public T1Thread(Object t1Monitor) {
        this.t1Monitor = t1Monitor;
    }

    public void stopRunning() {
        running = false;
        synchronized (t1Monitor) {
            t1Monitor.notifyAll(); // Ensure that the thread exits if it's waiting.
        }
    }

    @Override
    public void run() {
        while (running) {
            synchronized (t1Monitor) {
                try {
                    t1Monitor.wait();
                    if (!running) {
                        break;
                    }
                    System.out.println("T1Thread - Doing work...");
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        }
        System.out.println("T1Thread exiting...");
    }
}

class T2Thread extends Thread {
    private volatile boolean running = true;

    public void stopRunning() {
        running = false;
    }

    @Override
    public void run() {
        while (running) {
            System.out.println("T2Thread - Doing work...");
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        System.out.println("T2Thread exiting...");
    }
}

public class MultiThreadApp {
    public static void main(String[] args) {
        int mainSleepTime = 500;
        int primeSleepTime = 250;

        Object t1Monitor = new Object();

        PrimeThread primeThread = new PrimeThread(primeSleepTime, t1Monitor);
        T1Thread t1Thread = new T1Thread(t1Monitor);
        T2Thread t2Thread = new T2Thread();

        primeThread.start();
        t1Thread.start();
        t2Thread.start();

        try (Scanner scanner = new Scanner(System.in)) {
            boolean primeThreadRunning = true;
            boolean t1ThreadRunning = true;
            boolean t2ThreadRunning = true;

            while (primeThreadRunning || t1ThreadRunning || t2ThreadRunning) {
                System.out.println("Press '1' to stop T1Thread, '2' to stop T2Thread, 'ENTER' to stop PrimeThread.");
                String input = scanner.nextLine();
                if (input.equals("1") && t1ThreadRunning) {
                    t1Thread.stopRunning();
                    t1ThreadRunning = false;
                } else if (input.equals("2") && t2ThreadRunning) {
                    t2Thread.stopRunning();
                    t2ThreadRunning = false;
                } else if (input.isEmpty() && primeThreadRunning) {
                    primeThread.stopRunning();
                    primeThreadRunning = false;
                }
                Thread.sleep(mainSleepTime);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        try {
            primeThread.join();
            t1Thread.join();
            t2Thread.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        System.out.println("Main thread exiting...");
    }
}
