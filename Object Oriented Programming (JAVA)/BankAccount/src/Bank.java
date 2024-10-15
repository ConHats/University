import java.util.*;

public class Bank {
	private ArrayList<BankAccount> accounts = new ArrayList<BankAccount>();
	
	public void addAccount(BankAccount account) {
		accounts.add(account);
	}
	
	public void printAllData() {
		for(BankAccount account : accounts) {
			//polimorfiki klisi
			account.printData();
		}
	}

}
