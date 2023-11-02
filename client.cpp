#include "client.hpp"

Client::Client(const std::string& name, const std::string& email, const std::string& phone)
    : name_(name), email_(email), phone_(phone) {}

std::string Client::getName() const {
    return name_;
}

std::string Client::getEmail() const {
    return email_;
}

std::string Client::getPhone() const {
    return phone_;
}