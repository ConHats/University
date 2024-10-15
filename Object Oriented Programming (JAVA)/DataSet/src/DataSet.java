
public class DataSet {
	
	private int counter;
	
	private double sum;
	
	private Measurable max;
	private Measurable min;
	
	public DataSet() {
		counter = 0;
		sum = 0;
		min = null;
		max= null;
		
	}
	
	public void add(Measurable item) {
		
		if(counter == 0) {
			max = item;
			min = item;
		} else if(item.getMeasure() > max.getMeasure())
			max = item;
		else if(item.getMeasure() < min.getMeasure())
			min= item;
		
		counter++;
		sum += item.getMeasure();
		
	}
	
	public double calcAverage() {
		if(counter == 0)
			return 0;
		return sum/counter;
	}
	
	public Measurable getMax() {
		return max;
	}
	
	public Measurable getMin() {
		return min;
	}
}
