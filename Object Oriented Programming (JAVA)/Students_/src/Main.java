
public class Main {

	public static void main(String[] args) {
		
		Student s1 = new Student("Babis", "iis19043");
		Student s2 = new Student("Babis", "iis19043");
		
		
		
		if(s1.equals(s2))
			System.out.println("We are talking about the same student");
		else
			System.out.println("These guys are different students");
	}

}
