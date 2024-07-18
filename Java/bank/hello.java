package bank;
import java.util.*;
import java.util.function.IntBinaryOperator;

public class hello {

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            IntBinaryOperator f1  = ( a, b) ->  {
                System.out.println(a);
                return a + b;
            };
            
            
                       // f1.applyAsInt(7, 5);
            System.out.println(f1.applyAsInt(6, 6));
            
        } catch (Exception exception) {

        }
    }

}
