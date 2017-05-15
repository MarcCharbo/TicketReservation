#include <iostream>
#include <unordered_map>

#ifndef AIRPORT_RESERVATION_H
#define AIRPORT_RESERVATION_H

class Reservation {

public:
    Reservation(int reservation_nbr, int current_user_id, std::string
    airport_code_departure, std::string airport_code_arrival, std::string
    departure_date, std::string arrival_date,int seat_selection);

  int GetReservationNumber(){return reservation_nbr_;}
  int GetUserId(){return user_id_;}
  std::string GetAirportDepCode(){ return airport_code_departure_;}
  std::string GetAirportArrivCode(){ return airport_code_arrival_;}
  std::string GetDepDate(){ return departure_date_;}
  std::string GetArrivDate(){ return arrival_date_;}
  int GetSeatSelect(){ return seat_selection_;}
  ~Reservation()= default;

protected:

private:
    int reservation_nbr_;
    int user_id_;
    std::string airport_code_departure_;
    std::string airport_code_arrival_;
    std::string departure_date_;
    std::string arrival_date_;
    int seat_selection_;

};


#endif //AIRPORT_RESERVATION_H
