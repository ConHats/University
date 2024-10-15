
public class Main {
	
	public static void main(String[] args) {
		
		Student S1,S2;  
		//εντολή reference (αναφορά), λειτουργεί σαν 
		//δείκτης που δυνιτικά μπορεί να δείχνει σε μια 
		//θέση μνήμης με τα στοιχεία του Student S1
		
		S1 = new Student("Babis", "1014");
		S2 = new Student("Takis", "1013");
		
		Course C1 = new Course("Java");
		Course C2 = new Course("Python");
		Course C3 = new Course("Ruby");
		
		S1.addCourse(C1);
		S2.addCourse(C1);
		
		C1.printInformation();
	}

}
 