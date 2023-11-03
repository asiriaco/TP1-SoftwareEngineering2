// car_rental.hpp
#ifndef CAR_RENTAL_HPP
#define CAR_RENTAL_HPP

#include <string>
#include "client.hpp"

class CarRental {
public:
    CarRental(const std::string& vehicleModel, const std::string& rentalAgency, int rentalDuration, int avaliableCars);
    std::string getVehicleModel() const;
    std::string getRentalAgency() const;
    int getRentalDuration() const;
    float calculateRentalCost(float dailyRate) const;
    int getAvailableCars() const;
    bool bookCar(Client car, int numberOfCars);
    std::vector<std::string> getClients() const;

private:
    std::string vehicleModel_;
    std::string rentalAgency_;
    int rentalDuration_; 
    int avaliableCars_;
    std::vector<std::string> clients;
};

#endif  // CAR_RENTAL_HPP