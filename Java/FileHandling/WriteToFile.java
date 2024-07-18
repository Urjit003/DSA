package FileHandling;

import java.io.IOException;
import java.io.PrintWriter;

public class WriteToFile {
    public static void main(String[] args) {
    // Writing Characters
        // try (BufferedWriter bfr = new BufferedWriter(new
        // FileWriter("E:\codes\Java\FileHandling\demo_write.txt"))) {
        // bfr.write("HELL OWOREL");
        // } catch (IOException E) {
        // System.out.println(E.getMessage());
        // }

    // Writing Bytes
        // try (FileOutputStream bfr = new
        // FileOutputStream("Java\FileHandling\demo_write.txt")) {
        // String data = "Hello from from mount Gundabad";
        // byte[] byteData = data.getBytes();
        // bfr.write(byteData);
        // } catch (IOException E) {
        // System.out.println(E.getMessage());
        // }

        // writing using printWriter
        try (PrintWriter writer = new PrintWriter("Java\\FileHandling\\demo_write.txt")) {
                writer.println("Hello , World");
        } catch (IOException exception) {
            exception.getMessage();
        }
    }
}
