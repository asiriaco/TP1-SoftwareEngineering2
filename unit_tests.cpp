#include "trip.hpp"
#include "hotel.hpp"
#include "flight.hpp"
#include "client.hpp"
#include "car_rental.hpp"
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

#pragma region TEST CLIENT
void testClientName(){
    Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
    assert(client1.getName() == "John Doe");
}

void testClientEmail(){
    Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
    assert(client1.getEmail() == "johndoe@ymail.com");
}

void testClientPhone(){
    Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
    assert(client1.getPhone() == "123456789");   
}
#pragma endregion

#pragma region TEST FLIGHT
void testFlightDeparture(){
    Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
    assert(flight.getDeparture() == "Sofia");    
}

void testFlightDestination(){
    Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
    assert(flight.getDestination() == "London");    
}

void testFlightDate(){
    Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
    assert (flight.getDate() == "12.12.2020");    
}

void testFlightCapacity(){
    Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
    assert(flight.getCapacity() == 100);    
}

void testFlightAvailableSeats(){
    Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
    flight.includeSeats(10);
    assert(flight.getAvailableSeats() == 90);    
}

void testFlightChangeOfDate(){
    Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
    flight.changeDate("13.12.2020", 5);
    assert(flight.getDate() == "13.12.2020");    
}
#pragma endregion

#pragma region TEST HOTEL
void testHotelName(){
    Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
    assert(hotel.getName() == "Hilton");    
}

void testHotelLocation(){
    Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
    assert(hotel.getLocation() == "Sofia");    
}   

void testHotelRating(){
    Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
    assert(hotel.getRating() == 5);    
}

void testHotelPrice(){
    Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
    assert(hotel.getPrice() == 400.0);    
}

void testBookingFullHotel(){
    Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
    int roomNumber = hotel.bookHotel();
    assert(roomNumber == -1);    
}

void testBookingHotel(){
    Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
    std::vector<int> rooms{909, 1302};
    hotel.setAvaliableRooms(rooms);
    int roomNumber = hotel.bookHotel();
    assert(roomNumber == 1302);    
}
#pragma endregion

#pragma region TEST CAR RENTAL
void testCarRentalVehicleModel(){
    CarRental carRental = CarRental("Chevrolet Onix", "Hertz", 5, 10);
    assert(carRental.getVehicleModel() == "Chevrolet Onix");    
}

void testCarRentalRentalAgency(){
    CarRental carRental = CarRental("Chevrolet Onix", "Hertz", 5, 10);
    assert(carRental.getRentalAgency() == "Hertz");    
}

void testCarRentalRentalDuration(){
    CarRental carRental = CarRental("Chevrolet Onix", "Hertz", 5, 10);
    assert(carRental.getRentalDuration() == 5);    
}

void testCarRentalAvailableCars(){
    CarRental carRental = CarRental("Chevrolet Onix", "Hertz", 5, 10);
    assert(carRental.getAvailableCars() == 10);    
}
#pragma endregion

int main(){

    std::cout << "Starting Unity Tests" << std::endl;

    testClientName();
    testClientEmail();
    testClientPhone();
    std::cout << "All 3 unity tests passed for class Client" << std::endl;

    testFlightDeparture();
    testFlightDestination();
    testFlightDate();
    testFlightCapacity();
    testFlightAvailableSeats();
    testFlightChangeOfDate();
    std::cout << "All 6 unity tests passed for class Flight" << std::endl;

    testHotelName();
    testHotelLocation();
    testHotelRating();
    testHotelPrice();
    testBookingFullHotel();
    testBookingHotel();
    std::cout << "All 6 unity tests passed for class Hotel" << std::endl;

    testCarRentalVehicleModel();
    testCarRentalRentalAgency();
    testCarRentalRentalDuration();
    testCarRentalAvailableCars();
    std::cout << "All 4 unity tests passed for class CarRental" << std::endl;

    std::cout << "19/19 unity tests passed" << std::endl;

    return 0;
}