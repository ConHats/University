
public class Main {

	public static void main(String[] args) {
		
		System.out.println("Number of Soldiers: " + Soldier.getCounter());
		
		Soldier S1 = new Soldier("VX101");
		Soldier S2 = new Soldier("ZE202");
		
		System.out.println("Number of Soldiers: " + Soldier.getCounter());
		System.out.println("Number of Soldiers: " + S1.getCounter());
		
		System.out.println(Math.sqrt(5.4));
	}

}
