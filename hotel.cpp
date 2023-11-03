#include "hotel.hpp"

Hotel::Hotel(std::string name, std::string location, int rating, double price)
    : name_(name), location_(location), rating_(rating), price_(price) {}


Hotel::~Hotel() {}  

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

void Hotel::setAvaliableRooms(std::vector<int> rooms) {
    for (int room : rooms){
        avaliableRooms.push_back(room);
    }
}

int Hotel::bookHotel() {
    int roomNumber = 0;
    if (avaliableRooms.size() >= 0){
        roomNumber = avaliableRooms.back();
        avaliableRooms.pop_back();
    }
    else{
        return -1;
    }
    return roomNumber;
}