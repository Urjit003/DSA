
public class main {

    public static void main(String[] args) {
        for (int i = 1; i <= 10; ++i) {
            System.out.printf("%2d is the %d%s element\n", i, i, (i  == 1) ? "st"
                    : (i  == 2) ? "nd"
                            : (i  == 3) ? "rd"
                                    : "th");
        }
    }
}