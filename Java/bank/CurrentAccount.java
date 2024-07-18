package bank;

public class CurrentAccount extends Account {

    private static final long minimumBalance = 5000;
    private static final long penalty = 100;

    public CurrentAccount(long acno, String n, long openBal) throws NegativeAmountException {
        super(acno, n, openBal);
    }

    public CurrentAccount(String n, long openBal) throws NegativeAmountException {
        super(n, openBal);
    }

    public boolean withdraw(long amt) throws NegativeAmountException {
        if (!super.withdraw(amt)) {
            return false;
        }
//        if (this.balance < minimumBalance) {
        if (this.getBalance() < minimumBalance) {
//            this.balance -= penalty;
            new Transaction("Penalty", TransType.DEBIT, penalty);
        }
        return true;
    }
    
}

