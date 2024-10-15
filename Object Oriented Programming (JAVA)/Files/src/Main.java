import java.io.*;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
//		ArrayList<Employee> company = new ArrayList<>();
//		
//		company.add(new Employee("John"));
//		company.add(new Employee("Bob"));
//		company.add(new Employee("Mary"));
//		company.add(new Employee("Susan"));
//		
//		try {
//			FileOutputStream fileOut = new FileOutputStream("company.ser");
//			ObjectOutputStream out = new ObjectOutputStream(fileOut);
//			
//			out.writeObject(company);
//			
//			out.close();
//			fileOut.close();
//			
//		} catch (FileNotFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		
		ArrayList<Employee> retrievedCompany = null;
		
		try {
			FileInputStream fileIn = new FileInputStream("company.ser");
			ObjectInputStream in = new ObjectInputStream(fileIn);
			
			retrievedCompany = (ArrayList<Employee>) in.readObject();
			in.close();
			fileIn.close();
			 
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		for(Employee e: retrievedCompany)
			System.out.println(e.getName());
		
	}

}
