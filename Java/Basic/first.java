package Basic;

import java.util.Scanner;

public class first {
    public static void main(String[] args) {
        boolean IsOkToVote = false;
        int age ;
        System.out.println("Please Enter age : ");
        try (Scanner sc = new Scanner(System.in)) {
            age = sc.nextInt() ;
            if (age >= 18) {
                IsOkToVote = true;
            } else {
                IsOkToVote = false;
            }
        }
        if (IsOkToVote) {
            System.out.println("Ok to vote");
        } else {
            System.out.println("Not ok to vote");
        }
    }
    
    // function that swaps two integers
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }   

}
