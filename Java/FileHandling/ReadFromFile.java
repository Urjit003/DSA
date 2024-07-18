package FileHandling;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class ReadFromFile {
    public static void main(String[] args) {
        // File file = new File("E://codes/Java/FileHandling/demo.txt"); // Remove the leading "/"
        
        // try (Scanner sc = new Scanner(file)) {
        //     while (sc.hasNextLine()) { // Check if there's another line to read
        //         String line = sc.nextLine();
        //         if (line.equals("-1")) {
        //             break; // Exit the loop if "-1" is encountered
        //         }
        //         System.out.println(line);
        //     }
        // } catch (FileNotFoundException e) {
        //     // Handle file not found exception
        //     System.out.println("File not found: " + e.getMessage());
        // } catch (Exception e) {
        //     // Handle other exceptions
        //     e.printStackTrace();
        // }

        //Reading Characters
        // try (BufferedReader bfr = new BufferedReader(new FileReader("E:\\codes\\Java\\FileHandling\\demo.txt"))){
        //     String line;
        //     while(!((line = bfr.readLine()).equals(null))) {
        //         System.out.print(line + " ");
        //     }
        // } catch (Exception e) {
        //     // TODO: handle exception
        // }

        //Reading Bytes
        // try (BufferedReader bfr = new BufferedReader(new FileReader("E:\\codes\\Java\\FileHandling\\demo.txt"))){
        //     int byteData ;
        //     while((byteData = bfr.read()) != -1) {
        //         System.out.print((char)byteData + " ");
        //     }
        // } catch (Exception e) {
        //     // TODO: handle exception
        // }

        //using scanner 
        try (Scanner sc = new Scanner(new File("E:\\codes\\Java\\FileHandling\\demo.txt"))) {
                while (sc.hasNextLine()) {
                    System.out.println(sc.nextLine());
                }
        }catch(IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
