import java.util.ArrayList;

public class Student {
	
	private String name;
	private String id;
	private ArrayList<Course> courses = new ArrayList<Course>();
	//πίνακας 5 θέσεων που περιέχει 5 αναφορές 
	//σε 5 μαθήματα
	
	
	public void addCourse(Course aCourse) {
		courses.add(aCourse);
		aCourse.addStudent(this);
	}
	
	public Student(String aName, String anID) {
		name = aName;
		id = anID;
	}
	
	public Student(String aName) {
		name = aName;
		id = "9999";
	}
	
	public Student() {
		name = "No name given";
		id = "9999";
	}
	
	public void setID(String anID) {	
			id = anID;
	}
	
	public String getName() {
		return name;
	}
	
	public String getID() {
		return id;
	}
	
	public void printInfo() {
		System.out.println("Student Data ");
		System.out.println("Name: " + name);
		System.out.println("ID: " + id);
		System.out.println("enrolled in: ");
		for(Course c: courses) {
			System.out.println(c.getName());
		}
	}

}
