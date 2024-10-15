import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;

import javax.swing.*;

public class GUI extends JFrame{
	
	private JTextField input = new JTextField("input name");
	private JButton addButton = new JButton("Add");
	
	private JList list = new JList();
	private JButton shuffleButton = new JButton("Shuffle");
	private JPanel panel = new JPanel();
	
	private DefaultListModel<String> model = new DefaultListModel<>();
	private JScrollPane scrollPane;
	
	
	public GUI(){
		
		list.setModel(model);
		scrollPane = new JScrollPane(list);
		
		panel.add(input);
		panel.add(addButton);
		panel.add(list);
		panel.add(shuffleButton);
		
		addButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				model.addElement(input.getText());
			}
			
		});
		
		shuffleButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				ArrayList<String> nameList = Collections.list(model.elements());
				
				Collections.shuffle(nameList);
				
				model.clear();
				
				for(String name: nameList)
					model.addElement(name);
			}
			
		});
		
		this.setContentPane(panel);
	
		this.setVisible(true);
		this.setSize(300, 300);
		this.setTitle("Collections test");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
}
