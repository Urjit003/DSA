package String;

public class Reverse {
    public static void main(String[] args) {
        String str = new String("Urjit Dabhi");
        String rev = new StringBuilder(str).reverse().toString();
        System.out.println(rev);
    }
}
