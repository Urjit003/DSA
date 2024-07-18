
package bank;

// import java.util.Map;
import java.util.TreeMap;
// import java.util.Collection;
import java.util.stream.Stream;

// TODO update the class to use a Map<Long, Account> instead of Account[] to maintain all accounts of the bank
// TODO add a method called getAccountStream to return stream of Account objects

public class Bank {
    private String name;
    private long lastAccountNumber;
    // private long accountCode;
    // private Account[] accounts = new Account[10000];

    public TreeMap<Long,Account> accounts= new TreeMap<Long,Account>();

    public Bank(String n, int code) {
        this.name = n;
        this.lastAccountNumber = code * 10_000L;
        // this.accounts.put(code * 10_000L,null);
    }
    public enum AccountType {
        CURRENT {
            @Override
            public Account create(long acno, String n, long openBal) throws NegativeAmountException {
                return new CurrentAccount(acno, n, openBal);
            }
        },
        SAVINGS {
            @Override
            public Account create(long acno, String n, long openBal) throws NegativeAmountException {
                return new SavingsAccount(acno, n, openBal);
            }
        },
        ;
        public abstract Account create(long acno, String n, long openBal) throws NegativeAmountException;
    }
    // public long openAccount(AccountType type, String n, long openBal) throws NegativeAmountException {
    //     if (lastAccountNumber+1 % 10_000 == 0) {
    //         throw new RuntimeException("No more accounts allowed");
    //     }
    //     Account ac = type.create(++lastAccountNumber, n, openBal);
    //     this.accounts[(int)(lastAccountNumber-1)%10_000] = ac;
    //     return ac.getAccountNumber();
    // }
    public long openAccount(AccountType type, String n, long openBal) throws NegativeAmountException {
        
        long ac_no= ++lastAccountNumber;
        Account ac = type.create(ac_no, n, openBal);
        accounts.put(ac_no, ac);
        return ac.getAccountNumber();
    }
    // private Account getAccount(long acno) throws NoSuchAccountException {
    //     Account ac = this.accounts[(int)acno%10_000];
    //     if (ac == null) {
    //         throw new NoSuchAccountException("invalid account number");
    //     }
    //     return ac;
    // }
    private Account getAccount(long acno) throws NoSuchAccountException {
        Account ac = accounts.get(acno);
        if (ac == null) {
            throw new NoSuchAccountException("invalid account number");
        }
        return ac;
    }
    public Stream<Account> getAccountStream(){
        return accounts.values().stream();
    }

    public void deposit(long acno, long amt) throws NegativeAmountException, NoSuchAccountException {
        getAccount(acno).deposit(amt);
    }
    public boolean withdraw(long acno, long amt) throws NegativeAmountException, NoSuchAccountException {
        return getAccount(acno).withdraw(amt);
    }
    public void display(long acno) throws NoSuchAccountException {
        getAccount(acno).display();
    }
    public void printPassbook(long acno) throws NoSuchAccountException {
        getAccount(acno).printPassbook();
    }
    public void listAccounts() {
        System.out.println("List of Accounts for bank:"+this.name);
        for (Account account : accounts.values()) {
            if (account == null) {
                continue;
            }
            account.display();
        }
        System.out.println("End of account list");
    }
}

