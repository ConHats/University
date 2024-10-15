import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

import javax.swing.*;

public class GUI extends JFrame{
	
	private JPanel panel;
	private JButton button;
	private JFileChooser fileChooser;
	
	public GUI() {
		panel = new JPanel();
		button = new JButton("Open File");
		fileChooser = new JFileChooser();
		
		panel.add(button);
		this.setContentPane(panel);
		
		button.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				int returnValue = fileChooser.showOpenDialog(panel);
				
				if(returnValue == fileChooser.OPEN_DIALOG) {
					File file = fileChooser.getSelectedFile();
					
					try {
						FileReader reader = new FileReader(file);
						BufferedReader bReader = new BufferedReader(reader);
						
						String line = bReader.readLine();
						while(line != null) {
							System.out.println(line);
							line = bReader.readLine();
						}
						
						bReader.close();
						reader.close();
						
					} catch (FileNotFoundException e1) {
						
						
						e1.printStackTrace();
					
					} catch (IOException e1) {
						
						e1.printStackTrace();
					
					}
				}
			}
			
		});
		
		this.setVisible(true);
		this.setSize(300, 300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
