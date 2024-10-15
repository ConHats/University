import java.util.ArrayList;

public class Course {
	private String name;
	private ArrayList<Student> students= new ArrayList<Student>();
	
	public void addStudent(Student aStudent) {
		students.add(aStudent);
	}
	
	public void printInformation() {
		System.out.println("Course Name: " + name);
		System.out.println("has students: ");
		for(Student s: students)
			System.out.println(s.getName());
	}
		
	public Course(String aName) {
		name = aName;
	}
	
	public String getName() {
		return name;
	}
	
	

}
