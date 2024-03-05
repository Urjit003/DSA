package Basic;

import java.util.Scanner;

public class oocp {
    String name ;
    void SetName(String name) {
        this.name = name;
    }
    String GetName() {
        return name;
    }   //
    public static void main(String[] args) {
        oocp a1 ;
        try (Scanner sc = new Scanner(System.in)) {
            a1 = new oocp();
            a1.SetName(sc.nextLine());
        }
        System.out.println(Add(10,20));
    } 
        // function that return sum of two values
        public static int Add(int a, int b) {
            return a + b;
        }    

    


}
