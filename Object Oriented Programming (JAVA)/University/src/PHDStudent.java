
public class PHDStudent extends Student{
	
	private String thesis;
	
	public PHDStudent(String name, String thesis) {
		super(name);
		this.thesis = thesis;
	}
	
	public void printInfo() {
		System.out.println("PHD Student");
		System.out.println("Name: " + getName());
		System.out.println("Thesis: " + thesis);
		
	}

}
