#include "trip.hpp"

Trip::Trip(const Flight& flight, const Hotel& hotel, const Client& client, int numberOfTravellers)
    : flight_(flight), hotel_(hotel), client_(client), numberOfTravellers_(numberOfTravellers) {
        status_ = "OK";
    }

Trip::~Trip() {
    std::cout << "Trip destructor called" << std::endl;
}

void Trip::bookFlight() {
    if (!flight_.bookSeats(client_, numberOfTravellers_)){
        std::cout << "Flight is fully booked" << std::endl;
    }
    else{
        std::cout << "Successfully booked flight" << std::endl; 
    }
}

void Trip::bookHotel(){
    int roomNumber = hotel_.bookHotel();
    if (roomNumber == -1){
        std::cout << "Hotel is fully booked" << std::endl;
        status_ = "Missing Hotel";
    }
    else{
        roomNumber_ = roomNumber;
        std::cout << "Successfully booked hotel" << std::endl; 
    }
}

void Trip::reescheduleTrip(std::string newDate){
    
    if(!flight_.changeDate(newDate, numberOfTravellers_)){
        std::cout << "Could not reeschedule flight" << std::endl;
    }
    else{
        std::cout << "Successfully reescheduled flight" << std::endl;
    }
}

bool Trip::changeFlight(Flight& flight){
    if(flight.getAvailableSeats() < numberOfTravellers_){
        std::cout << "Flight selected is full. We're keeping with the initial flight" << std::endl;
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
    int newRoomNumber = hotel.bookHotel();

    if(newRoomNumber != -1){
        hotel_ = hotel;
        roomNumber_ = newRoomNumber;
        std::cout << "Successfully changed hotel" << std::endl;
        status_ = "OK";
        return true;
    }
    else{
        std::cout << "Not enough available rooms, we're keeping with the initial booking" << std::endl;
        return false;
    }
}

std::string Trip::getStatus() const{
    return status_;
}

int Trip::getRoomNumber() const{
    return roomNumber_;
}

void Trip::cancelTrip(){
    status_ = "Canceled";
    std::cout << "Successfully cancelled trip" << std::endl;
    hotel_.setAvaliableRooms({roomNumber_});
}





    