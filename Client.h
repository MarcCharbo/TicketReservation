#ifndef AIRPORT_CLIENT_H
#define AIRPORT_CLIENT_H

#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>

#include "User.h"
#include "Reservation.h"

class Client: public User {
public:
  Client(int client_id, std::string first_name, std::string last_name,
         std::string phone_number, std::string address, std::string city,
         std::string zip, std::string country);

  int GetUserId(){ return client_id_;}
  std::string GetUserFirstName() { return User::user.first_name;};
  std::string GetUserLastName() { return User::user.last_name;};
  void AddReservatioList(int reservation_nbr);
  void PrintReservationList();
  ~Client()= default;

protected:

private:
  int client_id_;
  std::vector<int> reservation_list{};

};


#endif //AIRPORT_CLIENT_H
