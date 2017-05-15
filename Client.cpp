//
// Created by Marc Charbonneau on 4/7/17.
//

#include "Client.h"
Client::Client(int client_id, std::string first_name, std::string last_name,
              std::string phone_number, std::string address, std::string city,
              std::string zip, std::string country):User(client_id, first_name,
                                                         last_name, phone_number,
                                                         address,city, zip, country)
{
  client_id_= client_id;
}

void Client::AddReservatioList(int reservation_nbr) {
  this->reservation_list.push_back(reservation_nbr);
}

void Client::PrintReservationList() {
  for (int i = 0; i<reservation_list.size();++i){
    std::cout<<reservation_list[i]<< " ";

  }
}