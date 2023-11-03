#include "trip.hpp"
#include "hotel.hpp"
#include "flight.hpp"
#include "client.hpp"
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>


int main() {

std::cout << "Classes tests started" << std::endl;

std::cout << "Testing class Client.hpp" << std::endl;
#pragma region TEST CLIENT
    Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
    Client client2 = Client("Jane Doe", "janedoe@ymail.com", "321456456");

    assert(client1.getName() == "John Doe");
    assert(client1.getEmail() == "johndoe@ymail.com");
    assert(client1.getPhone() == "123456789");
    assert(client2.getName() == "Jane Doe");
    assert(client2.getEmail() == "janedoe@ymail.com");
    assert(client2.getPhone() == "321456456");

#pragma endregion

std::cout << "Testing class Flight.hpp" << std::endl;
#pragma region TEST FLIGHT
    Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
    assert(flight.getDeparture() == "Sofia");
    assert(flight.getDestination() == "London");
    assert (flight.getDate() == "12.12.2020");
    assert(flight.getCapacity() == 100);

    flight.includeSeats(10);
    assert(flight.getAvailableSeats() == 90);

    flight.bookSeats(client1, 5);
    assert(flight.getAvailableSeats() == 85);

    flight.changeDate("13.12.2020", 5);
    assert(flight.getDate() == "13.12.2020");

    flight.includeSeats(83);
    bool success = flight.bookSeats(client2, 5);
    assert(success == false);

#pragma endregion

std::cout<< "Testing class Hotel.hpp" << std::endl;
#pragma region TEST HOTEL
    Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
    assert(hotel.getName() == "Hilton");
    assert(hotel.getLocation() == "Sofia");
    assert(hotel.getRating() == 5);
    assert(hotel.getPrice() == 400.0);

    int roomNumber = hotel.bookHotel();
    assert(roomNumber == -1);

    std::vector<int> rooms{301, 405, 506, 909, 1302};
    hotel.setAvaliableRooms(rooms);
    roomNumber = hotel.bookHotel();
    assert(roomNumber == 1302);

#pragma endregion

std::cout << "Testing class Trip.hpp" << std::endl;

}
