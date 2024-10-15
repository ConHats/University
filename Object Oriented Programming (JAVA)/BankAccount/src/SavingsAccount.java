
public class SavingsAccount extends BankAccount {
	private double interestRate;
	
	public SavingsAccount (double initialAmount, double rate) {
		super(initialAmount);
		interestRate = rate;
	}
	
	public void setInterestRate (double rate) {
		interestRate = rate;
	
	}
	public void addInterest() {
		double interest = getBalance() *interestRate;
		balance = balance + interest;
	}
	
	public void printData() {
		System.out.println("Savings Account");
		System.out.println("Balance: " + balance + " rate: " + interestRate);
	}

}
