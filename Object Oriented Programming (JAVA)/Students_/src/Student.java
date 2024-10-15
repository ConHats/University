
public class Student {
	
	private String name;
	private String id;
	
	public Student(String name, String id) {
		
		this.name = name;
		this.id = id;
	}
	
	public String toString() {
		return (name + ": " + id);
	}
	
	public void printInfo() {
		System.out.println("Name: " + name);
		System.out.println("Id: " + id); 
	}

	public boolean equals(Object obj) {
		Student otherStudent = (Student)obj;
		
		if(this.name.equals(otherStudent.name) && this.id.equals(otherStudent.id))
			return true;
		else
			return false;
	}
}
