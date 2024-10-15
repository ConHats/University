import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.*;

public class GUI extends JFrame {
	
	//step 1.1
	private JPanel panel= new JPanel();
	
	//step 2.1
	private JTextField studentnameField, studentidField ,courseField ;
	private JButton createStudentButton ,printCourseDetailsButton;	
	private ArrayList<Course> courses = new ArrayList<>();
	
	public GUI() {
		
		courses.add(new Course("Java", 5));
		courses.add(new Course("Python", 3));
		courses.add(new Course("C++", 6));
		courses.add(new Course("JavaScript", 2));
		
		//step 1.2
		panel = new JPanel();
		
		//step 2.2
		studentnameField = new JTextField("Enter the name");
		studentidField = new JTextField("Enter the id");
		createStudentButton = new JButton("Create Student");
		courseField = new JTextField("Enter a course");
		printCourseDetailsButton = new JButton("Print course details");
		
		//step 3
		panel.add(studentnameField);
		panel.add(studentidField);
		panel.add(createStudentButton);
		panel.add(courseField);
		panel.add(printCourseDetailsButton);
		
		//step 4
		this.setContentPane(panel);
		
		//3rd step
		ButtonListener listener = new ButtonListener();
		
		//4rth step
		createStudentButton.addActionListener(listener);
		
		this.setSize(400, 400);
		this.setVisible(true);
		this.setTitle("Student form"); 
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	}
	
	//1st step
	//inner class: it could be a separate class but it only interacts with CUI
	// it only shows here and it shares methods
	class ButtonListener implements ActionListener{
		
		//2nd step
		public void actionPerformed(ActionEvent e) {
			
			String name = studentnameField.getText();
			String id = studentidField.getText();
			
			Student s = new Student(name ,id);
			
			
			//I want to add the new student to the selected course
			String courseName = courseField.getText();
			
			Course selectedCourse = null;
			for(Course course: courses)
				if(courseName.equals(course.getTitle()))
					selectedCourse = course;
			selectedCourse.addStudent(s);
			System.out.println("Student has been created and enrolled");
		}
	}
	
}
