
public class Main {

	public static void main(String[] args) {
		
		DataSet ds1 = new DataSet();
		
		BankAccount BA1= new BankAccount(1500);
		BankAccount BA2= new BankAccount(2000);
		BankAccount BA3= new BankAccount(1000);
		
		ds1.add(BA1);
		ds1.add(BA2);
		ds1.add(BA3);
		
		DataSet ds2 = new DataSet();
		
		Student S1 = new Student(5.55);
		Student S2 = new Student(8.79);
		Student S3 = new Student(7.63);
		
		System.out.println("Average: " + ds1.calcAverage());
		System.out.println("Max. Balance: "+ ds1.getMax().getMeasure());
		System.out.println("Min. Balance: "+ ds1.getMin().getMeasure());
			
		ds2.add(S1);
		ds2.add(S2);
		ds2.add(S3);
		
		System.out.println("Average: " + ds2.calcAverage());
		System.out.println("Max. GPA: "+ ds2.getMax().getMeasure());
		System.out.println("Min. GPA: "+ ds2.getMin().getMeasure());
	}

}
