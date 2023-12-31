
#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <string>
#include <vector>
#include <iostream>

class Hotel {
public:
    Hotel(std::string name, std::string location, int rating, double price);
    ~Hotel();
    std::string getName() const;
    std::string getLocation() const;
    void setAvaliableRooms(std::vector<int> rooms);
    int getRating() const;
    double getPrice() const;
    int bookHotel();
    void cancelBooking(int roomNumber);
private:
    std::vector<int> avaliableRooms;
    std::string name_;
    std::string location_;
    int rating_;
    double price_;
};

#endif 

