
package bank;

public class SavingsAccount extends Account {
    
    public SavingsAccount(long acno, String n, long openBal) throws NegativeAmountException {
        super(acno, n, openBal);
    }

    public SavingsAccount(String n, long openBal) throws NegativeAmountException {
        super(n, openBal);
    }
    
}

