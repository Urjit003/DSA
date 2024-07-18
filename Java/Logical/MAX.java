package Logical;
import java.util.Arrays;
import java.util.Scanner;

public class MAX {
    static int max(int arr[]) {
        Arrays.sort(arr);
        return arr[arr.length - 1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int []arr = new int[10]; 
        for (int i = 0; i < 10; i++) {
            
            arr[i] = sc.nextInt();
        }
        System.out.println(max(arr));
    }
}
