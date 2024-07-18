package Logical;
import java.util.ArrayList;
import java.util.Scanner;

public class MAIN {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list  = new ArrayList<Integer>(10);
        for(Integer i : list) {
            list.add(i);
        }
        // for(Integer i : list) {
        //     System.out.print(i + " ");
        // }
        
        // SEARCH FOR AN ELEMENT
        // System.err.println(list.contains(766));
        
        // System.err.println(list);
        // list.set(0,101);
        // System.err.println(list);

        // for(int i = 0 ; i< 5 ; ++i ){
        //     list.add(sc.nextInt());
        // }
        // for(int i = 0 ; i< 5 ; ++i ){
        //     System.out.println(list.get(i));
        // }
     
        // 2D list

        ArrayList<ArrayList<Integer>> _2dlsit = new ArrayList<>();
            // initializing the rows
        for (int i = 0; i < 3; i++) {
                _2dlsit.add(new ArrayList<>());
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                _2dlsit.get(i).add(sc.nextInt());
            }
        }
        System.out.println(_2dlsit + " " + _2dlsit.hashCode() + " ");
    }
}
