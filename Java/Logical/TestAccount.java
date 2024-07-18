
package Logical;


import java.util.Arrays;
import java.util.Comparator;
import bank.*;
import java.util.function.BiFunction;

public class TestAccount {
    private static void display(Account[] accounts) {
        for (Account ac : accounts) {
            ac.display();
        }
    }
    public static void main(String[] args) throws NegativeAmountException {
        CurrentAccount ca = new CurrentAccount("James", 1_00_000);
        System.out.println("before penalty");
        ca.display();
// TODO set the penalty function on ca according to the function

                // BiFunction<Long,Long,Integer> bf= new BiFunction<Long,Long,Integer>() {
                //         public Integer apply(Long minBal,Long bal){
                //                 long diff = minBal - bal;
                //                 if (diff <= 0) return 0;
                //                 if (diff <= 1_000) return 100;
                //                 if (diff <= 2_000) return 200;
                //                 if (diff <= 3_000) return 300;
                //                 return 500;
                //             }
                // };
/*
(minBal, bal) -> {
                    long diff = minBal - bal;
                    if (diff <= 0) return 0;
                    if (diff <= 1_000) return 100;
                    if (diff <= 2_000) return 200;
                    if (diff <= 3_000) return 300;
                    return 500;
                }
*/
// TODO then withdraw to get the penalty applied on the object ca.
        ca.withdraw(91_000);
        // ca.penalise(bf.apply(10000L, ca.getBalance()));
        ca.display();
        ca.printPassbook();

        // System.out.println(ca.hasPenalty());



        
        Account[] accounts = new Account[5];
        try {
            accounts[0] = new SavingsAccount(12321, "John", 1_00_000);
            accounts[1] = new CurrentAccount(23123, "jane", 1_00_000);
            accounts[2] = new CurrentAccount(12312, "John", 50_000);
            accounts[3] = new SavingsAccount(33411, "Joseph", 1_50_000);
            accounts[4] = new CurrentAccount(23344, "Janet", 75_000);
            System.out.println("before sorting");
            display(accounts);
        } catch (NegativeAmountException nae) {
            nae.printStackTrace();
        }


// TODO create a comparator to order by name, then sort and display
        System.out.println("\n\nafter sorting by name");
        // Arrays.sort(accounts, new Comparator<Account>() {
        //         @Override
        //         public int compare(Account a,Account b){
        //                 return a.getName().compareTo(b.getName());
        //         }
        // });
        Arrays.sort(accounts, Comparator.comparing(Account::getName));
        display(accounts);
// TODO create a comparator to order by balances, then sort and display
        System.out.println("\n\nafter sorting by balance");
        // Arrays.sort(accounts, new Comparator<Account>() {
        //         @Override
        //         public int compare(Account a, Account b){
        //                 // return ((Long)a.getBalance()).compareTo(b.getBalance());
        //                 return Long.compare(a.getBalance(), b.getBalance());
        //         }
        // });
        Arrays.sort(accounts,Comparator.comparing(Account::getBalance));
        display(accounts);
// TODO create a comparator to order by the natural ordering of Account, ie. according to Comparable<Account>
        System.out.println("\n\nafter sorting by natural order");
        Arrays.sort(accounts);
        display(accounts);
// TODO create a comparator to order by the reverse ordering of Account, ie. according to Comparable<Account>
        System.out.println("\n\nafter sorting by reverse order");
        Arrays.sort(accounts,Comparator.reverseOrder());
        display(accounts);
// TODO create a comparator to order by name reversed, then display then
        System.out.println("\n\nafter sorting by name reversed");
        Arrays.sort(accounts,new Comparator<Account>(){
                public int compare(Account a , Account b){
                        return -a.getName().compareTo(b.getName());
                }
        });
        display(accounts);
// TODO create a comparator to order by name ignoring the case, then display
        System.out.println("\n\nafter sorting by name case insensitive");
        Arrays.sort(accounts, new Comparator<Account>(){
                public int compare(Account a,Account b){
                        return a.getName().compareToIgnoreCase(b.getName());
                }
        });
        display(accounts);
// TODO sort the array by name and then on balances.
        System.out.println("\n\nafter sorting by name then on balance");
        Arrays.sort(accounts,Comparator.comparing(Account::getName).thenComparing(Account::getBalance));
        display(accounts);
// TODO create a Comparator by Account type. then sort them by balance and display
        System.out.println("\n\nafter sorting by type then on balance");
        Arrays.sort(accounts,Comparator.comparing(Account::getType).thenComparing(Account::getBalance));
        display(accounts);
    }
    
}

