#include "trip.hpp"

Trip::Trip(const Flight& flight, const Hotel& hotel, const Client& client, int numberOfTravellers)
    : flight_(flight), hotel_(hotel), client_(client), numberOfTravellers(numberOfTravellers) {}

Trip::~Trip() {}

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
    
    if(!flight_.changeDate(newDate, numberOfTravellers)){
        std::cout << "Could not reeschedule flight" << std::endl;
    }
    else{
        std::cout << "Successfully reescheduled flight" << std::endl;
    }
}

bool Trip::changeFlight(Flight& flight){
    if(flight.getAvailableSeats() < numberOfTravellers){
        std::cout << "Not enough available seats" << std::endl;
        return false;
    }
    else{
        flight_ = flight;
        bookFlight();
        std::cout << "Successfully changed flight" << std::endl;
        return true;
    }
}

bool Trip::changeHotel(Hotel& hotel){
    if(hotel.bookHotel(numberOfTravellers)){
        hotel_ = hotel;
        std::cout << "Successfully changed hotel" << std::endl;
        return true;
    }
    else{
        std::cout << "Not enough available rooms" << std::endl;
        return false;
    }
}





    