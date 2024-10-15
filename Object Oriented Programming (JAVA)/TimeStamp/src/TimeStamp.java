
public class TimeStamp {
	//Παραβίαση της αρχής της ενσωμάτωσης
	private int hour;
	private int minute;
	private int second;
	
	public void increaseHour() {
		hour++;
		if(hour == 24)
			hour = 0;
	}
	public TimeStamp(int h, int m, int s) {
		hour =h;
		minute =m;
		second = s;
		
	}
	
	public void printTime() {
		System.out.println(hour + ":" + minute + ":" + second);
		
	}

}
