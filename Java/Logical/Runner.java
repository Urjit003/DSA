package Logical;
import java.util.*;

import collection.*;

public class Runner {
    
    public static void main(String[] args) {
        CustomStack<Integer> stack = new CustomStack<>(10);
        System.out.println(stack);
        try (Scanner in = new Scanner(System.in)) {
            for (int i = 0; i < 10; i++) {
                stack.push(in.nextInt());
            }
            System.out.println(stack);
            System.out.println(stack.pop());
            System.out.println(stack.pop());
            System.out.println(stack);
        }
    }


}
