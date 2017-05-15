//
// Created by Marc Charbonneau on 4/7/17.
//

#include "Airport.h"

void Airport::AddAirport(std::string id,std::string name,
                         std::string iso_country){

  AirportDetails airportDetails{id,name,iso_country};

  airport_map.insert(std::make_pair(airportDetails.id_,airportDetails));

}

AirportDetails Airport::GetAirport(std::string code){

  auto search = this->airport_map.find(code);

  return search->second;

}