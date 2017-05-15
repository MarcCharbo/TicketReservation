#ifndef AIRPORT_AIRPORT_H
#define AIRPORT_AIRPORT_H

#include <iostream>
#include <unordered_map>

struct AirportDetails{
  std::string id_;
  std::string name_;
  std::string iso_country_;

};

class Airport {

public:
    Airport()= default;
    void AddAirport(std::string id,std::string name,
                    std::string iso_country);
    AirportDetails GetAirport(std::string code);
    ~Airport()= default;

protected:


private:

    std::unordered_map<std::string, AirportDetails> airport_map{};

};



#endif //AIRPORT_AIRPORT_H
