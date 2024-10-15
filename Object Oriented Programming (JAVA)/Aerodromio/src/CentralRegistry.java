import java.util.ArrayList;

public class CentralRegistry {
	private static ArrayList<Airport> airports = new ArrayList<>();
	public static ArrayList<Flight> flights = new ArrayList<>();
	
	//Adds an Airport to the CentralRegistry's ArrayList
	public static void addAirport(Airport airport) {
	    airports.add(airport);
	}
	
	//Adds a flight to the CentralRegistry's ArrayList
	public static void addFlight(Flight flight) {
		flights.add(flight);
		
		Airport airportA = flight.getAirportA();
		Airport airportB = flight.getAirportB();
		
		airportA.addConnectedAirport(airportB);
		airportB.addConnectedAirport(airportA);
		
		if(!airportA.getCompanies().contains(flight.getCompany()))
				airportA.addCompany(flight.getCompany());
		if(!airportB.getCompanies().contains(flight.getCompany()))
			airportB.addCompany(flight.getCompany());
	}
	
	//Choice to clear the Airport ArrayList and start filling it  
	public static void updateDirectConnections() {
	    for (Airport airport : airports) {
	        airport.clearDirectConnections();
	    }
	
	    for (Flight flight : flights) {
	        Airport airportA = flight.getAirportA();
	        Airport airportB = flight.getAirportB();
	
	        airportA.addDirectConnection(airportB);
	        airportB.addDirectConnection(airportA);
	    }
	}
	
	//Counts the direct flights from an airport 
	private static void updateDirectFlightsCount(ArrayList<Airport> airports, ArrayList<Integer> directFlightsCount, Airport airport) {
	    if (airports.isEmpty()) {
	        airports.add(airport);
	        directFlightsCount.add(1);
	        return;
	    }
	    
	    if (directFlightsCount.isEmpty()) {
	        // Initialize the list with zeros for each airport
	        for (int i = 0; i < airports.size(); i++) {
	            directFlightsCount.add(0);
	        }
	    }

	    int index = airports.indexOf(airport);

	    if (index == -1) {
	        airports.add(airport);
	        directFlightsCount.add(1);
	    } else {
	        directFlightsCount.set(index, directFlightsCount.get(index) + 1);
	    }
	}
	
	//Returns a formatted String with the Airports directly connected to (this) Airport
	public static String getDirectlyConnectedAirportsToString(Airport airport) {
		if(!airport.getDirectConnections().isEmpty()) {
				
			String directlyConnectedAirports = "DIRECT FLIGHTS TO:\r\n";
			int airportCount = 1;
				
			for(Airport directAirport: airport.getDirectConnections()) {
					
				directlyConnectedAirports += "[" + airportCount + "]" + directAirport.getCity() + "\r\n";
				airportCount++;
			}
			
			return directlyConnectedAirports;
		}
		else
			return null;
	}
	
	//Returns a formatted String with the Airports indirectly connected to (this) Airport separated for every directly connected Airport
	public static String getIndirectlyConnectedAirportsToString(Airport airport) {
		
		String indirectlyConnectedAirports = "INDIRECT FLIGHTS TO:\r\n\r\n";
		
		if(!airport.getDirectConnections().isEmpty()) {
			for(Airport directAirport: airport.getDirectConnections()) {
				
				indirectlyConnectedAirports += "From " + directAirport.getCity() + ":\r\n";
				int airportCount = 1;
				
				if(directAirport.getDirectConnections().size() > 1) {
					for(Airport indirectAirport: directAirport.getDirectConnections())
						if(indirectAirport != airport) {
							
							indirectlyConnectedAirports += "[" + airportCount + "]" 
														+ indirectAirport.getCity() + "\r\n";
							airportCount++;
						}
					
					indirectlyConnectedAirports += "\r\n";
				}
				else
					indirectlyConnectedAirports += "There's no indirectly connected airports\r\n\r\n";
			}
			return indirectlyConnectedAirports;
		}
		else
			return null;
		
	}
	
	//Finds the Airport with the most flights
	public static Airport getLargestHub() {
		ArrayList<Integer> directFlightsCount = new ArrayList<>();

		for (Flight flight : flights) {
			updateDirectFlightsCount(airports, directFlightsCount, flight.getAirportA());
			updateDirectFlightsCount(airports, directFlightsCount, flight.getAirportB());
		}

		if (directFlightsCount.isEmpty()) {
			return null; // or handle the case where there are no flights
		}

		Airport largestHub = airports.get(0);
		int maxDirectFlights = directFlightsCount.get(0);

		for (int i = 1; i < airports.size(); i++) {
			if (directFlightsCount.get(i) > maxDirectFlights) {
				maxDirectFlights = directFlightsCount.get(i);
				largestHub = airports.get(i);
			}
		}

		return largestHub;
	}
	
	//Collects all the flights in a ArrayList	
	public static ArrayList<Flight> getFlights() {
        return flights;
    }
	
	//Finds the flight with the biggest duration (more minutes)
	public static Flight getLongestFlight() {
		Flight longestFlight = null;
        int maxDuration = -1;

        for (Flight flight : flights) {
            if (flight.getDuration() > maxDuration) {
                maxDuration = flight.getDuration();
                longestFlight = flight;
            }
        }

        return longestFlight;
	}
	
	//Creates an ArrayList with the connected flights from each airport
	public static ArrayList<Airport> getCommonConnections(Airport airport1, Airport airport2) {
        ArrayList<Airport> commonConnections = new ArrayList<>();

        for (Airport connection : airport1.getDirectConnections()) {
            if (airport2.getDirectConnections().contains(connection)) {
                commonConnections.add(connection);
            }
        }

        return commonConnections;
    }
	
	//Returns the Airport located to (city)
	public static Airport getAirport(String city){
			
		for(Airport airport: CentralRegistry.airports)
			if(airport.getCity().equals(city))
				return airport;
			
		return null;
	}
	
	//Returns a String with all the Direct Flights and their details
	public static String getDirectFlightDetails(Airport airportA, Airport airportB) {
		
		if(airportA.isDirectlyConnectedTo(airportB)) {

			String flightDetails = "DIRECT FLIGHTS DETAILS\r\n";
			int airportCount = 1;
			
			for(Flight flight: CentralRegistry.flights)
				if(flight.getAirportA() == airportA && flight.getAirportB() == airportB ||
				   flight.getAirportB() == airportA && flight.getAirportA() == airportB) {
					
					   flightDetails += "[" + airportCount + "]" + flight.toString() + "\r\n";
					   airportCount++;
				}
			return flightDetails;
		}
		else
			return "NO DIRECT FLIGHTS\r\n";
	}

	//Returns a String with all the Indirect Flights and their details
	public static String getInDirectFlightDetails(Airport airportA, Airport airportB) {
		
		int connectionCount = 1;
		ArrayList<Airport> connections = airportA.getCommonConnections(airportB);
		
		if(!connections.isEmpty()) {
			
			String detailsOfFlights = "INDIRECT FLIGHTS through...\r\n";
			
			for(Airport connection: connections) {
				
					   detailsOfFlights += "[" + connectionCount + "]" 
							   			+ connection.getCity() + "," + connection.getCode() + " airport\r\n";
					   connectionCount++;
				}
			return detailsOfFlights;
		}
		else
			return "NO INDIRECT FLIGHTS\r\n";
	}
}
