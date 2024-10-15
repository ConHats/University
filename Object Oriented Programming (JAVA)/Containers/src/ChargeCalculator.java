import java.awt.event.*;

import javax.swing.*;

public class ChargeCalculator extends JFrame {
	
	private JPanel panel = new JPanel();
	private JButton button = new JButton("Calculate charge");
	
	private Ship ship;
	
	
	public ChargeCalculator(Ship aShip) {
		
		ship = aShip;
		
		panel.add(button);
		this.setContentPane(panel);
		
		ButtonListener listener = new ButtonListener();
		button.addActionListener(listener);
		
		
		this.setSize(400, 400);
		this.setVisible(true);
		this.setTitle("Charge Calculator");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ButtonListener implements ActionListener {

		
		public void actionPerformed(ActionEvent e) {
			
			double total = ship.calcTotalCharge();
			
			System.out.println("Total charge: " + total);
		}
		
		
	}
	

}
