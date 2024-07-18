package Exception;
public class AverageCalculator {

    public static double average(String[] numbers) throws NullPointerException, NumberFormatException {
        if (numbers == null) {
            throw new NullPointerException("The input array is null.");
        }

        double sum = 0;
        int count = 0;

        for (String number : numbers) {
            if (number == null) {
                throw new NullPointerException("An element of the array is null.");
            }
            try {
                sum += Double.parseDouble(number);
                count++;
            } catch (NumberFormatException e) {
                throw new NumberFormatException("An element of the array is incorrectly formatted: " + number);
            }
        }

        if (count == 0) {
            throw new ArithmeticException("No valid numbers to calculate the average.");
        }

        return sum / count;
    }

    public static void main(String[] args) {
        String[] numbers = {"10.5", "20.0", "30.5", "40.0"};

        try {
            double avg = average(numbers);
            System.out.println("The average is: " + avg);
        } catch (NullPointerException | NumberFormatException | ArithmeticException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
