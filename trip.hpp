#ifndef TRIP_HPP
#define TRIP_HPP

#include "client.hpp"
#include "flight.hpp"
#include "hotel.hpp"
#include <iostream>

class Trip {
public:
    Trip(const Flight& flight, const Hotel& hotel, const Client& client, int numberOfTravellers);
    ~Trip();
    void bookFlight();
    void bookHotel();
    bool changeFlight(Flight& flight);
    bool changeHotel(Hotel& hotel);
    void reescheduleTrip(std::string newDate);
    

private:
    Flight flight_;
    Hotel hotel_;
    Client client_;
    int numberOfTravellers;
};


#endif