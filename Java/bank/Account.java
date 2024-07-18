package bank;

/* BY Biswojit */
import java.util.List;
import java.util.function.BiFunction;
import java.util.stream.Stream;
import java.util.ArrayList;
import java.util.Date;
/* BY Biswojit */

/*
An abstract class to represent a bank account. It has methods for deposit, withdraw, toString, display.
Two Account instances are considered equal if their account numbers match.
TODO Override the equals and hashCode methods //already
TODO use a List<Transaction> instead of the array for the passbook  //done
TODO add a method called getPassbook to return a List<Transaction> //modified print passbook
TODO implement the Comparable interface //already
TODO use LocalDate class from the java.time package instead of long for the date in Transaction class //done
TODO add the method called getTransactionStream to return Stream<Transaction> //done
TODO add a method called hasPenalty to return true if the passbook contains a penalty entry
TODO try to get rid of the balance field from the Account class, change the implementation of getBalance method to return balance from the List of Transaction. //done
*/
public abstract class Account implements Comparable<Account> {

    private long accountNumber;
    private String name;
    // long balance;
    // private long balance; getting it from transaction
    static final long minBal = 10_000L;
    private static BiFunction<Long,Long,Integer> bf= new BiFunction<Long,Long,Integer>() {
                        public Integer apply(Long minBal,Long bal){
                            // System.out.println("called with"+minBal+" "+bal);
                                long diff = minBal - bal;
                                if (diff <= 0) return 0;
                                if (diff <= 1_000) return 100;
                                if (diff <= 2_000) return 200;
                                if (diff <= 3_000) return 300;
                                return 500;
                            }
                };

    // private Transaction[] passbook = new Transaction[100];

    /* BY Biswojit */
    // TODO use a List<Transaction> instead of the array for the passbook //Complete

    List<Transaction> passbook = new ArrayList<>();

    // private int nextIndexInPassbook = 0;

    public class Transaction {
        private Date date = new Date();
        private String naration;
        private TransType transType;
        private long amount;

        public Transaction(String n, TransType t, long amt) throws NegativeAmountException {
            if (amt < 0) {
                throw new NegativeAmountException("Negative " + transType.toString().toLowerCase(), amt, Account.this);
            }
            this.naration = n;
            this.transType = t;
            this.amount = amt;
            // Account.this.balance += getNetAmount();
            Account.this.passbook.add(this);
        }

        public Date getDate() {
            return this.date;
        }

        public String getNaration() {
            return this.naration;
        }

        public long getAmount() {
            return this.amount;
        }

        public long getNetAmount() {
            return this.transType.getSign() * this.getAmount();
        }

        public String toString() {
            return "Transaction:" + String.format("%tF, %15s, %10s, %12d", this.date, this.naration,
                    this.transType.toString(), this.amount);
        }
    } // end of inner class Transaction

    public enum TransType {
        CREDIT(1),
        DEBIT(-1),;

        private int sign;

        TransType(int sign) {
            this.sign = sign;
        }

        public int getSign() {
            return this.sign;
        }
    } // end of enum TransType

    ///// ---- Deprecated After Using List
    // public void printPassbook() {
    // long runningBalance = 0;
    // Transaction t = null;
    // System.out.println("Passbook of " + name + " Account # " + accountNumber);
    // for (int transactionIndex = 0; transactionIndex < nextIndexInPassbook;
    // transactionIndex++) {
    // t = passbook[transactionIndex];
    // System.out.println(t + "," + runningBalance);
    // }
    // System.out.println("End of Passbook");
    // }

    // passbook with list

    public void printPassbook() {
        long runningBalance = 0;
        System.out.println("Passbook of " + name + " Account # " + accountNumber);
        for ( Transaction t : passbook) {
            runningBalance += t.getNetAmount();
            System.out.println(t + "," + runningBalance);
        }
        System.out.println("End of Passbook");
    }

    // TODO add a method called getPassbook to return a List<Transaction>

    public List<Transaction> getPassbook(){

        // return Collections.unmodifiableList(passbook);
        return List.copyOf(passbook); //java 10 onwards //copyof makes unmodifiable list
    }

    public Account(long acno, String n, long openBal) throws NegativeAmountException {
        /*
         * if (openBal < 0) {
         * throw new NegativeAmountException("Negative open balance", openBal, this);
         * }
         */
        this.accountNumber = acno;
        this.name = n;
        // this.balance = openBal;
        new Transaction("Opening Balance", TransType.CREDIT, openBal);
    }

// TODO add the method called getTransactionStream to return Stream<Transaction> 

    public Stream<Transaction> getTransactionStream(){
        return passbook.stream(); //stream sources are not modifiable so no worries
    }


    public long getAccountNumber() {
        return this.accountNumber;
    }

    public String getName() {
        return this.name;
    }

    // TODO try to get rid of the balance field from the Account class, change the implementation of getBalance method to return balance from the List of Transaction.
    public long getBalance() {
        long bal=0;
        for(Transaction t : passbook){
            bal+=t.getNetAmount();
        }
        return bal;
    }

    public void deposit(long amt) throws NegativeAmountException {
        /*
         * if (amt < 0) {
         * throw new NegativeAmountException("Negative deposit", amt, this);
         * }
         */
        // this.balance += amt;
        new Transaction("Deposit", TransType.CREDIT, amt);
    }

    public boolean withdraw(long amt) throws NegativeAmountException {
        /*
         * if (amt < 0) {
         * throw new NegativeAmountException("Negative withdraw", amt, this);
         * }
         */
        if (this.getBalance() < amt) {
            return false;
        }
        // this.balance -= amt;
        new Transaction("Withdrawal", TransType.DEBIT, amt);

        if(this.getBalance()<minBal)
            this.penalise(bf.apply(Account.minBal, this.getBalance()));
        return true;
    }

    

    //penalty
    private void penalise(long amt) throws NegativeAmountException{
       new Transaction("Penalty", TransType.DEBIT, amt);
            
    }

    public boolean hasPenalty(){
       for (Transaction transaction : passbook) {
        if(transaction.getNaration().equals("Penalty")){
            return true;
        }
       }
       return false;
    }


    public void display() {
        // System.out.println("Account:"+this.accountNumber+","+this.name+","+this.balance);
        System.out.println(this);
    }

    private static long lastAccountNumber = 1000;

    public Account(String n, long openBal) throws NegativeAmountException {
        this(++lastAccountNumber, n, openBal);
    }

    public String getType(){
        return this.getClass().getName(); //by own for sorting by ac  type
    }

    @Override
    public String toString() {
        return this.getClass().getName() + ":" + this.getAccountNumber() + "," + this.getName() + ","
                + this.getBalance();
    }

    // TODO Override the equals and hashCode methods //already

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (obj == this) {
            return true;
        }
        return this.getAccountNumber() == ((Account) obj).getAccountNumber();
    }

    @Override
    public int hashCode() {
        return (int) this.getAccountNumber();
    }

// TODO implement the Comparable interface //already

    @Override
    public int compareTo(Account ac) {
        return ((Long) (this.getAccountNumber())).compareTo(ac.getAccountNumber());
    }
}
