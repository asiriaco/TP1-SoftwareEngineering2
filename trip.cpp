#include "trip.hpp"

Trip::Trip(const Flight &flight, const Hotel &hotel, const Client &client,
           const CarRental &carRental, int numberOfTravellers, int numberOfCars)
    : flight_(flight), hotel_(hotel), client_(client), carRental_(carRental),
      numberOfTravellers_(numberOfTravellers), numberOfCars_(numberOfCars) {
  status_ = "OK";
}

Trip::~Trip() {}

void Trip::bookFlight() {
  if (!flight_.bookSeats(client_, numberOfTravellers_)) {
    outputBookingFailure("Flight");
  } else {
    outputBookingSuccess("flight");
  }
}

void Trip::bookHotel() {
  int roomNumber = hotel_.bookHotel();
  if (roomNumber == -1) {
    outputBookingFailure("Hotel");
    status_ = "Missing Hotel";
  } else {
    roomNumber_ = roomNumber;
    outputBookingSuccess("hotel");
  }
}

void Trip::bookCar() {
  if (!carRental_.bookCar(client_, numberOfCars_)) {
    outputBookingFailure("Car");
    status_ = "No cars available";
  } else {
    outputBookingSuccess("car");
    status_ = "Car rented";
  }
}

void Trip::reescheduleTrip(std::string newDate) {

  if (!flight_.changeDate(newDate, numberOfTravellers_)) {
    std::cout << "Could not reeschedule flight" << std::endl;
  } else {
    std::cout << "Successfully reescheduled flight" << std::endl;
  }
}

bool Trip::changeFlight(Flight &flight) {
  if (flight.getAvailableSeats() < numberOfTravellers_) {
    std::cout
        << "Flight selected is full. We're keeping with the initial flight"
        << std::endl;
    return false;
  } else {
    flight_ = flight;
    bookFlight();
    std::cout << "Successfully changed flight" << std::endl;
    return true;
  }
}

bool Trip::changeHotel(Hotel &hotel) {
  int newRoomNumber = hotel.bookHotel();

  if (newRoomNumber != -1) {
    hotel_ = hotel;
    roomNumber_ = newRoomNumber;
    std::cout << "Successfully changed hotel" << std::endl;
    status_ = "OK";
    return true;
  } else {
    std::cout
        << "Not enough available rooms, we're keeping with the initial booking"
        << std::endl;
    return false;
  }
}

bool Trip::changeCar(CarRental &carRental) {
  if (carRental.getAvailableCars() < numberOfCars_) {
    std::cout
        << "Car selected is not available. We're keeping with the initial car"
        << std::endl;
    return false;
  } else {
    carRental_ = carRental;
    bookCar();
    std::cout << "Successfully changed car" << std::endl;
    return true;
  }
}

std::string Trip::getStatus() const { return status_; }

int Trip::getRoomNumber() const { return roomNumber_; }

void Trip::cancelTrip() {
  status_ = "Canceled";
  std::cout << "Successfully cancelled trip" << std::endl;
  hotel_.setAvaliableRooms({roomNumber_});
}

void Trip::outputBookingFailure(const std::string& service) {
    std::cout << service << " no longer availabe. Fully booked or rented out." << std::endl;
}

void Trip::outputBookingSuccess(const std::string& service) {
    std::cout << "Successfully booked/rented " << service << std::endl;
}