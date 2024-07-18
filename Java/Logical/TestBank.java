
package Logical;

import bank.*;
import bank.Account.Transaction;

import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.function.*;

public class TestBank {
    public static void main(String[] args) throws Exception {
        String bankName = args[0];
        int bankCode = Integer.parseInt(args[1]);
        Bank bank = new Bank(bankName, bankCode);
        long acno1 = bank.openAccount(Bank.AccountType.CURRENT, "James", 1_00_000);
        long acno2 = bank.openAccount(Bank.AccountType.CURRENT, "Joshua", 1_00_000);
        long acno3 = bank.openAccount(Bank.AccountType.SAVINGS, "Jugal", 2_00_000);
        long acno4 = bank.openAccount(Bank.AccountType.CURRENT, "Jinal", 1_00_000);
        long acno5 = bank.openAccount(Bank.AccountType.SAVINGS, "Jeanne", 2_00_000);
        long acno6 = bank.openAccount(Bank.AccountType.CURRENT, "Nidhi", 1_00_000);
        long acno7 = bank.openAccount(Bank.AccountType.CURRENT, "Natalia", 3_00_000);
        long acno8 = bank.openAccount(Bank.AccountType.SAVINGS, "Namrata", 3_00_000);
        long acno9 = bank.openAccount(Bank.AccountType.CURRENT, "Tina", 11_00_000);
        long acno10 = bank.openAccount(Bank.AccountType.SAVINGS, "Tilly", 4_00_000);
        long acno11 = bank.openAccount(Bank.AccountType.SAVINGS, "Andrey", 10_00_000);
        long acno12 = bank.openAccount(Bank.AccountType.CURRENT, "Johanna", 4_00_000);
        long acno13 = bank.openAccount(Bank.AccountType.SAVINGS, "Cyna", 1_00_000);
        long acno14 = bank.openAccount(Bank.AccountType.SAVINGS, "Careena", 5_00_000);
        long acno15 = bank.openAccount(Bank.AccountType.SAVINGS, "Priyanka", 9_00_000);
        long acno16 = bank.openAccount(Bank.AccountType.SAVINGS, "Dipika", 5_00_000);
        long acno17 = bank.openAccount(Bank.AccountType.SAVINGS, "Salman", 7_00_000);
        long acno18 = bank.openAccount(Bank.AccountType.SAVINGS, "Salman", 9_00_000);
        bank.deposit(acno1, 11_000);
        bank.deposit(acno3, 1_000);
        bank.deposit(acno4, 8_000);
        bank.deposit(acno5, 25_000);
        bank.deposit(acno6, 95_000);
        bank.deposit(acno7, 2_99_000);
        bank.deposit(acno8, 100);
        bank.deposit(acno9, 10);

        bank.withdraw(acno10, 3_99_000);
        bank.withdraw(acno8, 2_99_000);
        bank.withdraw(acno7, 8_000);
        bank.withdraw(acno6, 25_000);
        bank.withdraw(acno5, 95_000);
        bank.withdraw(acno4, 99_000);
        bank.withdraw(acno3, 100);
        bank.withdraw(acno2, 95_000);

        bank.display(acno1);
        bank.deposit(acno1, 10_000);
        bank.display(acno1);
        bank.withdraw(acno1, 1_15_000);
        bank.printPassbook(acno1);
        // bank.listAccounts();

        // System.out.println(acno1);

        // bank.getAccountStream().forEach(System.out::println);


        // bank.getAccount(acno1);
        // TODO add a method in Account class called hasPenalty, if the account has any
        // penalty transaction

        // TODO display all accounts which have a penalty
        // bank.getAccountStream().filter(Account::hasPenalty).forEach(System.out::println);

        // TODO getList of Accounts with penalty
        //  Account[] badAccount = bank.getAccountStream().filter(Account::hasPenalty).collect(Collectors.toList()).toArray(new Account[0]);
            // List<Account> badAccount = bank.getAccountStream().filter(Account::hasPenalty).collect(Collectors.toList());

        // TODO sort the list, on different criteria
        // Arrays.sort(badAccount,Comparator.comparing(Account::getBalance));
        // Collections.sort(badAccount);
        // Collections.sort(badAccount,Comparator.comparing(Account::getBalance));
        // Collections.sort(badAccount,Comparator.comparing(Account::getName));
        // Collections.sort(badAccount,Comparator.comparing(Account::getType));
        // Collections.sort(badAccount,Comparator.comparing(Account::getName).thenComparing(Account::getBalance));
        // badAccount.stream().forEach(Account::display);


        // TODO create the Collector using the four components


        // TODO get summary statistics for all the account balances
        // LongSummaryStatistics stats = bank.getAccountStream().mapToLong(Account::getBalance).summaryStatistics();
        // System.out.println(stats);

        // // TODO get the Account with the maximum number of transactions
        // System.out.print("\n\nMax Txn: ");
        // bank.getAccountStream().sorted(new Comparator<Account>() {
        //     public int compare(Account a, Account b){
        //         return Long.compare(b.getTransactionStream().count(),a.getTransactionStream().count());
        //     }
            
        // }).limit(1).forEach(Account::display);

        // bank.getAccountStream().max(Comparator.comparingLong(ac -> ac.getTransactionStream().count())).ifPresent(Account::display);


        // // TODO get the highest transaction amount
        // System.out.print("\n\nMax Amt Ac: ");

        // Bank bnk = new Bank("Name", 102); try with Unavailable

        // bank.getAccountStream().max(Comparator.comparingLong(ac -> ac.getTransactionStream().mapToLong(Transaction::getNetAmount).max().orElse(Long.MIN_VALUE))).ifPresentOrElse(Account::display, () -> System.out.println("Unavailable"));

        // TODO get the summary statistics for the transaction amounts
        // System.out.println("Summary Stats For Individual Ac");

        // bank.getAccountStream().forEach(ac -> System.out.println(ac + ac.getTransactionStream().mapToLong(Transaction::getNetAmount).summaryStatistics().toString()));
        // TODO get the summary statistics for the transaction net-amounts


        // using Collectors.groupingBy
        // Map<String,List<Account>> acTypeWiseMap = bank.getAccountStream().collect(Collectors.groupingBy(ac -> ac.getClass().getName()));
        // System.out.println(acTypeWiseMap);
        
        // TODO get a map of namewise list of accounts
        // Map<String,List<Account>> acNameWise = bank.getAccountStream().collect(Collectors.groupingBy(Account::getName));
        // System.out.println(acNameWise);

        // TODO get a partition of accounts with and without penalty
        // Map<Boolean,List<Account>> acPenaltyWise = bank.getAccountStream().collect(Collectors.groupingBy(Account::hasPenalty));
        // System.out.println(acPenaltyWise);


        // TODO get a map of namewise sum of balance
        Map<String,Long> nameBalance= bank.getAccountStream().collect(Collectors.groupingBy(Account::getName, Collectors.summingLong(Account::getBalance)));
        System.out.println(nameBalance);


        
    }
}
