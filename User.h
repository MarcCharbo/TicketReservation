#include <iostream>
#include <unordered_map>

#ifndef AIRPORT_USER_H
#define AIRPORT_USER_H

#include <string>

class User {
public:
    User(int client_id, std::string first_name, std::string last_name,
         std::string phone_number, std::string address, std::string city,
         std::string zip, std::string country);
    virtual ~User(){};


protected:

  struct UserDetails{
    int user_id;
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    std::string address;
    std::string city;
    std::string zip;
    std::string country;
  };

  UserDetails user {};

};


#endif //AIRPORT_USER_H
