#include "trip.hpp"

Trip::Trip(const Flight& flight, const Hotel& hotel, const Client& client, int numberOfTravellers)
    : flight_(flight), hotel_(hotel), client_(client), numberOfTravellers(numberOfTravellers) {}

void Trip::bookFlight() {
    if (!flight_.bookSeats(client_, numberOfTravellers)){
        std::cout << "Flight is fully booked" << std::endl;
    }
    else{
        std::cout << "Successfully booked flight" << std::endl; 
    }
}

void Trip::bookHotel(){
    if (!hotel_.bookHotel(numberOfTravellers)){
        std::cout << "Hotel is fully booked" << std::endl;
    }
    else{
        std::cout << "Successfully booked hotel" << std::endl; 
    }
}

void Trip::reescheduleTrip(std::string newDate){
    flight_.changeDate(newDate);
}