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
    void reescheduleTrip(std::string newDate);
    void cancelTrip();
    bool changeFlight(Flight& flight);
    bool changeHotel(Hotel& hotel);
    std::string getStatus() const;


private:
    Flight flight_;
    Hotel hotel_;
    Client client_;
    int numberOfTravellers_;
    int roomNumber_;
    std::string status_;
};


#endif