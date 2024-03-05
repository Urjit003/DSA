public class swap {
    public static void swap(int a, int b) {
        int c = a;
        a = b;
        b = c;
    }

    public static void main(String[] args) {
        int a = 10, b = 20;
        swap(a, b);
        System.out.println(a + " " + b);
    }
}