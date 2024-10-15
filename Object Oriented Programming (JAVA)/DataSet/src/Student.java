
public class Student implements Measurable{
	
	private double GPA;
	
	//μέθοδος κατασκευαστής
	public Student(double gpa) {
		GPA = gpa;
	}
	
	//μέθοδος get
	public double getMeasure() {
		return GPA;
	}
}
