package Threads;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

// Customer class to represent customers
class Customer implements Runnable {
    private String name;
    private BlockingQueue<String> orderQueue;

    public Customer(String name, BlockingQueue<String> orderQueue) {
        this.name = name;
        this.orderQueue = orderQueue;
    }

    @Override
    public void run() {
        try {
            // Simulating placing an order
            String order = "Order from " + name;
            System.out.println(name + " placing order: " + order);
            orderQueue.put(order); // Add order to the queue
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

// Manager class to process orders and generate bills
class Manager implements Runnable {
    private BlockingQueue<String> orderQueue;

    public Manager(BlockingQueue<String> orderQueue) {
        this.orderQueue = orderQueue;
    }

    @Override
    public void run() {
        try {
            while (true) {
                // Take the order from the queue
                String order = orderQueue.take();
                System.out.println("Manager processing order: " + order);

                // Simulating generating bill
                System.out.println("Manager generating bill for: " + order);

                // Display the customer order after placing the order
                System.out.println("Customer order after placing the order : " + order);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class Restaurant {
    public static void main(String[] args) {
        // Creating a shared queue for orders
        BlockingQueue<String> orderQueue = new ArrayBlockingQueue<>(10);

        // Create manager thread
        Thread managerThread = new Thread(new Manager(orderQueue), "Manager");
        managerThread.start();

        // Create customers threads
        Thread customerThreadA = new Thread(new Customer("Customer A", orderQueue), "Customer A");
        Thread customerThreadB = new Thread(new Customer("Customer B", orderQueue), "Customer B");
        Thread customerThreadC = new Thread(new Customer("Customer C", orderQueue), "Customer C");

        // Start customers threads
        customerThreadA.start();
        customerThreadB.start();
        customerThreadC.start();

        // Wait for customers threads to finish
        try {
            customerThreadA.join();
            customerThreadB.join();
            customerThreadC.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        // Interrupt manager thread to stop
        managerThread.interrupt();
    }
}
