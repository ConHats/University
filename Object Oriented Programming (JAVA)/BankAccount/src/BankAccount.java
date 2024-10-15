
public class BankAccount {
	protected double balance;
	
	
	public BankAccount(double amount){
		balance = amount;
	}
	
	public double getBalance(){
		return balance;
	}
	
	public void deposit (double amount){
		balance += amount;
	}
	
	public void printData() {
		System.out.println("Normal Bank Account");
		System.out.println("Balance: " + balance);
	}
}
