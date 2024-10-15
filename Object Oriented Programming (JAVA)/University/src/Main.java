import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		ArrayList<Student> students = new ArrayList<Student>();
		
		students.add(new UnderGraduate("Babis", 7.78));
		students.add(new PHDStudent("Takis", "Troika & Anergia"));	
		
		for(Student student: students) {
			student.printInfo();
		}
	}

}
