#include "trip.hpp"
#include "hotel.hpp"
#include "flight.hpp"
#include "client.hpp"
#include <iostream>
#include <assert.h>
#include <string>
#include <vector>


int main() {

std::cout << "System test started" << std::endl;

    Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
    Client client2 = Client("Jane Doe", "janedoe@ymail.com", "321456456");
    Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
    Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
    CarRental car = CarRental("Chevrolet Onix", "Hertz", 5, 10);
    CarRental car2 = CarRental("Kia Soul", "Localiza", 2, 5);

#pragma region TEST TRIP
    Trip trip = Trip(flight, hotel, client1, car, 2, 1);
    assert(trip.getStatus() == "OK");

    trip.bookFlight();
    trip.bookHotel();

    assert(trip.getRoomNumber() == 909);

    Hotel hotel2 = Hotel("Ritz", "Sofia", 5, 600.0);
    bool success = trip.changeHotel(hotel2);
    assert(success == false);

    std::vector<int> newRooms{100, 401, 707};
    hotel2.setAvaliableRooms(newRooms);
    success = trip.changeHotel(hotel2);
    assert(success = true);

    int currentRoomNumber = trip.getRoomNumber();
    assert(currentRoomNumber == 707);

    trip.cancelTrip();
    assert(trip.getStatus() == "Canceled");

    Hotel hotel3 = Hotel("Plaza", "Sofia", 5, 150.0);

    Trip trip2 = Trip(flight, hotel3, client2, car,  5, 10);
    trip2.bookHotel();
    std::cout << trip2.getStatus() << std::endl;
    assert(trip2.getStatus() == "Missing Hotel");  

    hotel2.setAvaliableRooms({205, 409, 614, 456, 781 });
    success = trip2.changeHotel(hotel2);
    assert(success == true);
    assert(trip2.getStatus() == "OK");
  
#pragma endregion

std::cout << "System test finished, all tests passed" << std::endl;

return 0;
}
