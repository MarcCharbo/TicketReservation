//
// Created by Marc Charbonneau on 4/7/17.
//

#include "Reservation.h"

Reservation::Reservation(int reservation_nbr, int current_user_id,
                         std::string airport_code_departure,
                         std::string airport_code_arrival,
                         std::string departure_date,
                         std::string arrival_date,int seat_selection)
   : reservation_nbr_(reservation_nbr), user_id_(current_user_id),
     airport_code_departure_(airport_code_departure),
     airport_code_arrival_(airport_code_arrival),
     departure_date_(departure_date), arrival_date_(arrival_date),
     seat_selection_(seat_selection)

{}

