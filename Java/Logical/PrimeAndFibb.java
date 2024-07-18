package Logical;

import java.util.concurrent.BlockingQueue;

public class PrimeAndFibb {
    public static void main(String[] args) {
        int fibbcount = 15;
        int primecount = 15;
        System.out.println("First 15 Fibonacci Numbers:");
        generateFibbSeries(fibbcount);

        System.out.println("\nFirst 15 Prime Numbers:");
        generatePrimeNumber(primecount);
    }

    public static void generateFibbSeries(int n) {
        int num1 = 0, num2 = 1;
        System.out.println(num1 + " " + num2);

        for (int i = 2; i < n; i++) {
            int nextNum = num1 + num2;
            System.out.print(" " + nextNum);
            num1 = num2;
            num2 = nextNum;
        }
        System.out.println();
    }

    public static void generatePrimeNumber(int n) {
        int count = 0, num = 2;

        while (count < n) {
            if (isPrime(num)) {
                System.out.print(num + " ");
                count++;
            }
            num++;
        }
        System.out.println();
    }

    public static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= n/2; i++) { 
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
