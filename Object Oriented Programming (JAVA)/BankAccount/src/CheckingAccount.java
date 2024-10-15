
public class CheckingAccount extends BankAccount{
	private int transactionsCounter;
	
	public CheckingAccount(double initialAmount) {
		super(initialAmount);
		transactionsCounter=0;
	}
	
	//epanorismos/ epikalipsi methodou
	//override
	public void deposit (double amount) {
		transactionsCounter++;
		super.deposit(amount);
		
		if(transactionsCounter > 3)
			deductFees();
	}
	public void deductFees() {
		balance -=0.5;
	}
	
	public void printData() {
		System.out.println("Checking Account");
		System.out.println("Balance: " + balance + " free limit: 3 trans." );
	}

}
