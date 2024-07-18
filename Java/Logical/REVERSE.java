package Logical;
import java.util.Arrays;

/**
 * REVERSE
 */
public class REVERSE {
    
    static void swap(int []arr, int index1 , int index2) {
        int temp = arr[index1] ;
        arr[index1] =arr[index2];
        arr[index2] = temp;
    }

    static void reverse (int []arr)  {
        int start = 0;
        int end = arr.length- 1;
        while(start < end) {
            //swap
            swap(arr,start, end);
            start++;
            end--;
        }
    }
    public static void main(String[] args) {
        int arr[]= {1,2,3,4,5};
        System.out.println(Arrays.toString(arr));
        reverse(arr);
        System.out.println(Arrays.toString(arr));
    }

   
}