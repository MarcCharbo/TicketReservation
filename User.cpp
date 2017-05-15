//
// Created by Marc Charbonneau on 4/7/17.
//

#include "User.h"
User::User(int client_id, std::string first_name, std::string last_name,
           std::string phone_number, std::string address, std::string city,
           std::string zip, std::string country) {

        user = {client_id, first_name, last_name, phone_number, address,
                city, zip, country};
}

