#ifndef TRIP_HPP
#define TRIP_HPP

#include "client.hpp"
#include "flight.hpp"
#include "hotel.hpp"
#include <iostream>

class Trip {
public:
    Trip(const Flight& flight, const Hotel& hotel, const Client& client, int numberOfTravellers);
    void bookFlight();
    void bookHotel();
    void cancelFlight();
    void cancelHotel();
    void reescheduleTrip(std::string newDate);
    void print() const;

private:
    Flight flight_;
    Hotel hotel_;
    Client client_;
    int numberOfTravellers;
};


#endif