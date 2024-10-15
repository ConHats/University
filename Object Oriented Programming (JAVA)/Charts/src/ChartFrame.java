import javax.swing.JFrame;

import org.jfree.chart.* ;
import org.jfree.data.category.DefaultCategoryDataset;

public class ChartFrame extends JFrame{
	
	public ChartFrame(){
		
		DefaultCategoryDataset dataset = new DefaultCategoryDataset();
		dataset.addValue(212,  "classes", "JDK1.0");
		dataset.addValue(504,  "classes", "JDK1.1");
		dataset.addValue(1520,  "classes", "JDK1.2");
		dataset.addValue(1842,  "classes", "JDK1.3");
		dataset.addValue(2991,  "classes", "JDK1.4");
		
		JFreeChart chart = ChartFactory.createBarChart("Java Standard Class Library", "Versions", "Class count", dataset);
		ChartPanel chartPanel = new ChartPanel(chart);
		
		this.setContentPane(chartPanel);
		
		this.setVisible(true);
		this.setSize(400, 400);
		this.setTitle("Charts");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
