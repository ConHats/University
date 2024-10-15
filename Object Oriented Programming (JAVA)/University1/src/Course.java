import java.util.ArrayList;

public class Course {
	
	private String title;
	private int credits;
	private ArrayList<Student> students = new ArrayList<>();
	
	public void addStudent(Student aStudent) {
		students.add(aStudent);
	}

	public Course(String title, int credits) {
		this.title = title;
		this.credits = credits;
	}
	
	public void printDetails() {
		System.out.println("Course name: " + title);
		System.out.println("Credits: " + credits);
		System.out.println("has the following students");
		for(Student student: students)
			System.out.println(student);
		System.out.println("-----------------");
	}
	
	public String getTitle() {
		return title;
	
	}
	
}
