
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client {
public:
    Client(const std::string& name, const std::string& email, const std::string& phone);
    std::string getName() const;
    std::string getEmail() const;
    std::string getPhone() const;
private:
    std::string name_;
    std::string email_;
    std::string phone_;
};

#endif // CLIENT_HPP

