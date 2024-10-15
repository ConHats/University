
public class Flight {
	private Airport airportA;
    private Airport airportB;
    private int duration;
    private String company;

    public Flight(Airport airportA, Airport airportB, int duration, String company) {
        this.airportA = airportA;
        this.airportB = airportB;
        this.duration = duration;
        this.company = company;
    }

    public Airport getAirportA() {
        return airportA;
    }

    public Airport getAirportB() {
        return airportB;
    }

    public int getDuration() {
        return duration;
    }

    public String getCompany() {
        return company;
    }
    
    //When a flight is added, it updates the 2 involving airports
    public void updateAirports() {
        airportA.addFlightAndUpdate(this);
        airportB.addFlightAndUpdate(this);
    }

}
