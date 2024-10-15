import javax.swing.*;

public class MyFrame extends JFrame{
	
	
	private JPanel panel;
	private JTextField textField;
	private JButton button;
	
	
	
	
	public MyFrame() {
		
		//Βήμα 1: Δημιουργία Υποδοχέα
		panel = new JPanel();
		
		//Βήμα 2: Δημιουργία γραφικών συστατικών
		textField = new JTextField(10);
		button = new JButton("Press me");
		
		//Βήμα 3: Προσθήκη γραφικών συστατικών στο πάνελ
		panel.add(textField);
		panel.add(button);
		
		//Βήμα 4: Προσαρμογή υποδοχέα
		this.setContentPane(panel);
		
		this.setVisible(true);
		this.setSize(400, 400);
		this.setTitle("My first impressive frame!");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	
	
}
