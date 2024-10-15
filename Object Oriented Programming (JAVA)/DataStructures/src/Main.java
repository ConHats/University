import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		HashSet set = new HashSet();
		
		BankAccount ba1 = new BankAccount("001", 1000);
		BankAccount ba2 = new BankAccount("001", 1000);
		
		set.add(ba1);
		set.add(ba2);
		
		Iterator i = set.iterator();
		
		while(i.hasNext()) {
			BankAccount ba = (BankAccount)i.next();
			System.out.println(ba.getCode() + ": " + ba.getBalance());
		}
	}

}

class BankAccount {
	private String code;
	private double balance;
	
	
	public BankAccount(String code, double balance) {
		this.code = code;
		this.balance = balance;
	}

	public String getCode() {
		return code;
	}
	
	public double getBalance() {
		return balance;
	}

	public int hashCode() {
		return code.hashCode();
	}
	
	public boolean equals(Object o) {
		
		BankAccount other = (BankAccount)o;
		
		return other.code.equals(this.code);
	}
}
