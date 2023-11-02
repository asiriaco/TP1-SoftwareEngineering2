
#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <string>
#include <vector>
#include "client.hpp"

class Flight {
public:
    Flight(std::string departure, std::string destination, std::string date, int capacity);
    std::string getDeparture() const;
    std::string getDestination() const;
    std::string getDate() const;
    int getCapacity() const;
    int getAvailableSeats() const;
    bool bookSeats(Client client, int numberOfSeats);
    std::vector<Client> getClients() const;
    void changeDate(std::string newDate);

private:
    std::string departure;
    std::string destination;
    std::string date;
    int capacity;
    std::vector<Client> clients;
};

#endif

