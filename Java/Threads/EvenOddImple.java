package Threads;

import java.util.Scanner;

class SharedResourceTwo {
    private boolean isEvenTurn = true;

    public synchronized void printEven(int number) {
        while (!isEvenTurn) {
            try {
                wait();
            } catch (InterruptedException E) {
                Thread.currentThread().interrupt();
            }
        }
        System.out.println(Thread.currentThread().getName() + " - Even : " + number);
        isEvenTurn = false;
        notifyAll();
    }

    public synchronized void printOdd(int number) {
        while (isEvenTurn) {
            try {
                wait();
            } catch (InterruptedException E) {
                Thread.currentThread().interrupt();
            }
        }
        System.out.println(Thread.currentThread().getName() + " - Odd : " + number);
        isEvenTurn = true;
        notifyAll();
    }
}

class EvenRunnable implements Runnable {
    private final SharedResourceTwo sr;
    private final int maxNumber;

    public EvenRunnable(SharedResourceTwo sr, int maxNumber) {
        this.sr = sr;
        this.maxNumber = maxNumber;
    }

    @Override
    public void run() {
        for (int i = 0; i < maxNumber; i += 2) {
            sr.printEven(i);
            try {
                Thread.sleep(1000);
            }catch(InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

}

class OddRunnable implements Runnable {
    private final SharedResourceTwo sr;
    private final int maxNumber;

    public OddRunnable(SharedResourceTwo sr, int maxNumber) {
        this.sr = sr;
        this.maxNumber = maxNumber;
    }

    @Override
    public void run() {
        for (int i = 1; i < maxNumber; i += 2) {
            sr.printOdd(i);
            try {
                Thread.sleep(1000);
            }catch(InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

}

public class EvenOddImple {
    public static void main(String[] args) {
        SharedResourceTwo sr = new SharedResourceTwo();
        System.out.println("Give us lenght of Number to iterate through : ");
        try (Scanner sc = new Scanner(System.in)) {
            int Limit = sc.nextInt();
            Limit++;
            Thread evenThread = new Thread(new EvenRunnable(sr, Limit), "even Thread");
            Thread oddThread = new Thread(new OddRunnable(sr, Limit), "odd Thread");

            evenThread.start();
            oddThread.start();
        }
    }
}
