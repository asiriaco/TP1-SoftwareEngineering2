#include "flight.hpp"


Flight::Flight(std::string departure, std::string destination, std::string date, int capacity) {
    this->departure = departure;
    this->destination = destination;
    this->date = date;
    this->capacity = capacity;
}

std::string Flight::getDeparture() const {
    return departure;
}

std::string Flight::getDestination() const {
    return destination;
}

std::string Flight::getDate() const {
    return date;
}

int Flight::getCapacity() const {
    return capacity;
}

int Flight::getAvailableSeats() const {
    return capacity - clients.size();
}

bool Flight::bookSeats(Client client, int numberOfSeats) {
    if (getAvailableSeats() > numberOfSeats) {
        clients.push_back(client);
        return true;
    }
    return false;
}

std::vector<Client> Flight::getClients() const {
    return clients;
}

void Flight::changeDate(std::string newDate){
    date = newDate;
}