#include "hotel.hpp"

Hotel::Hotel(std::string name, std::string location, int rating, double price)
    : name_(name), location_(location), rating_(rating), price_(price) {}

std::string Hotel::getName() const {
    return name_;
}

std::string Hotel::getLocation() const {
    return location_;
}

int Hotel::getRating() const {
    return rating_;
}

double Hotel::getPrice() const {
    return price_;
}

bool Hotel::bookHotel(int numberOfGuests) {
    if (avaliableRooms.size() >= numberOfGuests){
        avaliableRooms.pop_back();
        return true;
    }
    else{
        return false;
    }
}