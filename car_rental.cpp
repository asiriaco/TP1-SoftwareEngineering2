// car_rental.cpp
#include "car_rental.hpp"

CarRental::CarRental(const std::string& vehicleModel, const std::string& rentalAgency, int rentalDuration, int avaliableCars)
    : vehicleModel_(vehicleModel), rentalAgency_(rentalAgency), rentalDuration_(rentalDuration), avaliableCars_(avaliableCars) {}


std::string CarRental::getVehicleModel() const {
    return vehicleModel_;
}

std::string CarRental::getRentalAgency() const {
    return rentalAgency_;
}

int CarRental::getRentalDuration() const {
    return rentalDuration_;
}

float CarRental::calculateRentalCost(float dailyRate) const {
    return dailyRate * rentalDuration_;
}

int CarRental::getAvailableCars() const {
    return avaliableCars_;
}

std::vector<std::string> CarRental::getClients() const {
    return clients;
}

bool CarRental::bookCar(Client client, int numberOfCars) {
    if (getAvailableCars() > numberOfCars) {
        clients.push_back(client.getName());
        avaliableCars_ -= numberOfCars;
        return true;
    }
    return false;
}


