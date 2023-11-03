// car_rental.hpp
#ifndef CAR_RENTAL_HPP
#define CAR_RENTAL_HPP

#include <string>

class CarRental {
public:
    CarRental(const std::string& vehicleModel, const std::string& rentalAgency, int rentalDuration, int avaliableCars);
    std::string getVehicleModel() const;
    std::string getRentalAgency() const;
    int getRentalDuration() const;
    float calculateRentalCost(float dailyRate) const;
    int getAvailableCars() const;

private:
    std::string vehicleModel_;
    std::string rentalAgency_;
    int rentalDuration_; 
    int avaliableCars_;
};

#endif  // CAR_RENTAL_HPP