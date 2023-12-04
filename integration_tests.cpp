#include "car_rental.hpp"
#include "client.hpp"
#include "flight.hpp"
#include "hotel.hpp"
#include "trip.hpp"
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

void testSeatsForClient() {
  Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
  Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
  flight.bookSeats(client1, 5);
  assert(flight.getAvailableSeats() == 95);
}

void testOverBooking() {
  Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
  Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
  flight.includeSeats(97);
  bool success = flight.bookSeats(client1, 5);
  assert(success == false);
}

void testOverBookingCar() {
  CarRental car = CarRental("Kia Soul", "Localiza", 2, 5);
  Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
  bool success = car.bookCar(client1, 6);
  assert(success == false);
}

void testTripStatus() {
  Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
  Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
  Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
  CarRental car = CarRental("Kia Soul", "Localiza", 2, 5);
  Trip trip = Trip(flight, hotel, client1, car, 5, 5);
  assert(trip.getStatus() == "OK");
}

void testCancelleTrip() {
  Client client1 = Client("John Doe", "johndoe@ymail.com", "123456789");
  Flight flight = Flight("Sofia", "London", "12.12.2020", 100);
  Hotel hotel = Hotel("Hilton", "Sofia", 5, 400.0);
  CarRental car = CarRental("Kia Soul", "Localiza", 2, 5);
  Trip trip = Trip(flight, hotel, client1, car, 5, 5);
  trip.cancelTrip();
  assert(trip.getStatus() == "Successfully cancelled trip");
}

int main() {
  std::cout << "Integration tests started" << std::endl;
  testSeatsForClient();
  testOverBooking();
  testOverBookingCar();
  testTripStatus();
  testCancelleTrip();
  std::cout << "Integration tests finished, 5/5 tests passed" << std::endl;
}