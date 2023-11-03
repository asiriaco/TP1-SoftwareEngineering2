#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "client.hpp"

class Flight {
public:
    Flight(std::string departure, std::string destination, std::string date, int capacity);
    ~Flight();
    std::string getDeparture() const;
    std::string getDestination() const;
    std::string getDate() const;
    void includeSeats(int seats);
    int getCapacity() const;
    int getAvailableSeats() const;
    bool bookSeats(Client client, int numberOfSeats);
    std::vector<std::string> getClients() const;
    bool changeDate(std::string newDate, int numberOfSeats);

private:
    std::string departure;
    std::string destination;
    std::string date;
    int capacity;
    int avaliableSeats;
    std::vector<std::string> clients;
};

#endif

