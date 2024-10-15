import java.util.ArrayList;
import java.util.List;

public class Airport {
	
	private String name;
    private String code;
    private String city;
    private String country;
    private ArrayList<String> companies;
    private ArrayList<Airport> directConnections;
    
    
    
    public Airport(String name, String code, String city, String country) {
        this.name = name;
        this.code = code;
        this.city = city;
        this.country = country;
        this.companies = new ArrayList<>();
        this.directConnections = new ArrayList<>();
    }
    
    public String getName() {
        return name;
    }

    public String getCode() {
        return code;
    }

    public String getCity() {
        return city;
    }

    public String getCountry() {
        return country;
    }

    public ArrayList<String> getCompanies() {
		return companies;
	}

   
    //Updates the array of (this) Airport with the new connection
  	public void addConnectedAirport(Airport anAirport) {
  		
  		if(!directConnections.contains(anAirport))
  			directConnections.add(anAirport);
  	}
  	
  	
  	//List including all the connected airports to the inputed one
  	public List<Airport> getDirectConnections() {
        return directConnections;
    }
    
    public boolean isDirectlyConnectedTo(Airport anAirport) {
    	for(Flight flight: CentralRegistry.flights) 
			if(flight.getAirportA() == this && flight.getAirportB() == anAirport ||
			   flight.getAirportB() == this && flight.getAirportA() == anAirport)
				  return true;
		return false;
	}
	
	public boolean isInDirectlyConnectedTo(Airport anAirport) {
		return !this.getCommonConnections(anAirport).isEmpty();
	}
	
	
	//Finds the companies that connect the 2 cities	
	private void updateCompanies(Flight flight) {
	    if (flight.getAirportA() == this || flight.getAirportB() == this) {
	        addCompany(flight.getCompany());
	    }
	}
	
	//Adds company to the ArrayList    
    public void addCompany(String company) {
    	if (!companies.contains(company)) {
            companies.add(company);
        }
    }
    
    //Removes company to the ArrayList
    public void removeCompany(String company) {
        companies.remove(company);
    }
    
    
    //When a flight is not found, it aads it and notifies the CentralRegistry 
    public void addFlightAndUpdate(Flight flight) {
    	if (!CentralRegistry.getFlights().contains(flight)) {
            CentralRegistry.addFlight(flight);
            CentralRegistry.updateDirectConnections();
            updateCompanies(flight);
    	}
    }
    
    //Empties the ArrayList 
    public void clearDirectConnections() {
        directConnections.clear();
    }

    public void addDirectConnection(Airport airport) {
        if (!directConnections.contains(airport)) {
            directConnections.add(airport);
        }
    }
    
    //Returns an array with the Airports connected to (this) Airport and to (anAirport)
    public ArrayList<Airport> getCommonConnections(Airport anAirport) {
			
			ArrayList<Airport> commonConnections = new ArrayList<>();
			
			for(Airport airportA: this.directConnections)
				if(anAirport.directConnections.contains(airportA))
						commonConnections.add(airportA);
			
			return commonConnections;
		}

    
    //Prints the companies serving (this) airport
  	public void printCompanies() {
  		for(String company: companies)
  			System.out.println(company);
  	}
    
}
