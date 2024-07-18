package bank;

public class NegativeAmountException extends Exception {
    private long amount;
    private Account account;
    NegativeAmountException(String msg, long amt, Account ac) {
        super(msg);
        this.amount = amt;
        this.account = ac;
    }

    public long getAmount() {
        return amount;
    }

    public Account getAccount() {
        return account;
    }

    public String toString() {
        return super.toString()+":"+amount+":"+account;
    }
}

