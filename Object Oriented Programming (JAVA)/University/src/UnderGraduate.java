
public class UnderGraduate extends Student{
	
	private double GPA;
	
	public UnderGraduate(String name, double gpa) {
		super(name);
		GPA = gpa;
	}
	
	public void printInfo() {
		System.out.println("Undergraduate Student");
		System.out.println("Name: " + getName());
		System.out.println("GPA: " + GPA);
		
	}

}
