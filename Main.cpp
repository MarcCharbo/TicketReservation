#include <iostream>
#include <fstream>
#include <unordered_map>

#include "TestHarness.h"
#include "Airport.h"
#include "Plane.h"
#include "Client.h"


// global variables
int client_nbr = 0;
int reservation_nbr = 0;
// end global


void PrintReservationInfo(const std::unordered_map<int, Reservation>&
reservation_map,const std::unordered_map<int, Client>& client_map, Airport& large_airport_lst, const Plane&
                          plane) {

  int current_user_id, current_reservation_nbr;

  std::cout << "Enter your user ID: ";
  std::cin >> current_user_id;
  std::cout << std::endl;

  auto client = client_map.at(current_user_id);
  std::cout << "Hello " + client.GetUserFirstName() + " " +
     client.GetUserLastName()<<std::endl;
  std::cout <<"You have the following reservation numbers: "<<std::endl;
  client.PrintReservationList();
  std::cout << std::endl;
  std::cout <<"Please enter the reservation number you would like to print: ";
  std::cin >> current_reservation_nbr;
  std::cout << std::endl;
  auto reservation = reservation_map.at(current_reservation_nbr);
  std::cout <<"Reservation details: "<<std::endl;

  std::cout << "Airport departure code: " + reservation.GetAirportDepCode()
            <<std::endl;
  auto dep_airport = large_airport_lst.GetAirport(reservation.GetAirportDepCode());
  std::cout << "Airport name: " + dep_airport.name_<<" " <<dep_airport
     .iso_country_<<std::endl;
  std::cout << "Departure date: " + reservation.GetDepDate()<<std::endl;


  std::cout << "Airport arrival code: " + reservation.GetAirportArrivCode()<<std::endl;
  auto arriv_airport = large_airport_lst.GetAirport(reservation
                                                       .GetAirportArrivCode());
  std::cout << "Airport name: " + arriv_airport.name_<<" " <<
            arriv_airport.iso_country_<<std::endl;
  std::cout << "Arrival date: " + reservation.GetArrivDate()<<std::endl;

  auto seat = reservation.GetSeatSelect();
  switch (seat){
    case 1:
      std::cout << "You reserved one seat for a total of "
                   + std::to_string(plane.get_first_class_price())<<std::endl;
      break;
    case 2:
      std::cout << "You reserved one seat for a total of "
                   + std::to_string(plane.get_first_class_price())<<std::endl;
      break;
    case 3:
      std::cout << "You reserved one seat for a total of "
                   + std::to_string(plane.get_first_class_price())<<std::endl;
      break;

    default:
      std::cout<<"Invalid selection, please call customer service"<<std::endl;
      break;
  }
}

void MakeReservation(std::unordered_map<int, Reservation>&
  reservation_map, std::unordered_map<int, Client>& client_map){

  int current_user_id;
  int seat_selection;
  std::string airport_code_departure,airport_code_arrival,departure_date,
     arrival_date;

  std::cout << "Enter your user ID: ";
  std::cin >> current_user_id;
  std::cout << std::endl;
  std::cout << "Enter the airport departure code: ";
  std::cin >> airport_code_departure;
  std::cout << std::endl;
  std::cout << "Enter your departure date: ";
  std::cin >> departure_date;
  std::cout << std::endl;
  std::cout << "Enter the airport arrival code: ";
  std::cin >> airport_code_arrival;
  std::cout << std::endl;
  std::cout << "Enter your arrival date: ";
  std::cin >> arrival_date;
  std::cout << std::endl;
  std::cout << "Enter your seat selection";
  std::cout << std::endl;
  std::cout <<" 1 for first class, 2 for more leg room or 3 for coach: ";
  std::cin >> seat_selection;
  std::cout << std::endl;

  Reservation reservation{reservation_nbr, current_user_id,
                          airport_code_departure, airport_code_arrival,
                          departure_date, arrival_date, seat_selection};

  reservation_map.insert(std::make_pair(reservation_nbr,reservation));

  Client& client = client_map.at(current_user_id);
  client.AddReservatioList(reservation_nbr);

  std::cout << "Your reservation number is: "<< reservation_nbr <<std::endl;
  reservation_nbr += 1;
}

void AddClient(std::unordered_map<int, Client>& client_map){

  std::string first_name, last_name, phone_number, address, city, zip, country;
  std::cout << "Enter your first name: ";
  std::cin >> first_name;
  std::cout << std::endl;
  std::cout << "Enter your last name: ";
  std::cin >> last_name;
  std::cout << std::endl;
  std::cout << "Enter your phone number: ";
  std::cin >> phone_number;
  std::cout << std::endl;
  std::cout << "Enter your address: ";
  std::cin >> address;
  std::cout << std::endl;
  std::cout << "Enter your city: ";
  std::cin >> city;
  std::cout << std::endl;
  std::cout << "Enter your zip code: ";
  std::cin >> zip;
  std::cout << std::endl;
  std::cout << "Enter your country: ";
  std::cin >> country;
  std::cout << std::endl;

  Client client{client_nbr, first_name, last_name, phone_number, address,
                city, zip, country};

  client_map.insert(std::make_pair(client.GetUserId(),client));
  std::cout << "Your client number is: "<< client_nbr<<std::endl;
  client_nbr+=1;
}
void LoadData(Airport& large_airport_lst){
  std::ifstream airport_file("airports.csv");
  std::string code;

  Airport* ptr_large_airport_lst = &large_airport_lst;


  if(airport_file){

    std::string line,record, id, type, name, continent, iso_country;
    getline(airport_file,line); // skip header

    while(getline(airport_file,line)){
      if(!line.empty()){
        int column_count = 0;

        std::istringstream cell(line);

        while(getline(cell, record,',')){
         if(!record.empty()){

           if(column_count==0){
             id=record.c_str();
           }
           if(column_count==2){
             type=record.c_str();
             type = type.substr(1,type.length()-2);
           }
           if(column_count==3){
             name=record.c_str();
             name = name.substr(1,name.length()-2);
           }
           if(column_count==8){
             iso_country = record.c_str();
             iso_country = iso_country.substr(1,iso_country.length()-2);
           }
           column_count +=1;
         }
        }
        if(type=="large_airport"){
          large_airport_lst.AddAirport(id,name,iso_country);
        }
      }
    }
  }
  airport_file.close();
}
int main()
{

  // load airport data
  Airport large_airport_lst{}; // create empty large_airport_list
  LoadData(large_airport_lst); // fill large_airport_list
  std::unordered_map<int, Client> client_map{}; // create empty client map
  std::unordered_map<int, Reservation> reservation_map{}; // create empty reservation map

  Plane plane{50,100, 150}; // create plane

  // User Menu
  std::cout<<"========== Welcome to FLYZONE =========="<<std::endl;
  bool menu_continue = true;
  while(menu_continue) {
    std::cout << "--- Menu ---" << "" << std::endl;
    std::cout << "Menu Options: " << "" << std::endl;
    std::cout << "(1) Create your profile" << std::endl;
    std::cout << "(2) Make a flight reservation" << std::endl;
    std::cout << "(3) Print confirmation" << std::endl;
    std::cout << "(4) Exit" << std::endl;
    std::cout << "Enter your menu selection: ";
    int menu_select;
    std::cin >> menu_select;
    std::cout << std::endl;

    switch (menu_select) {

      // create client
      case 1: {
        AddClient(client_map);

      }
        break;

        // make reservation
      case 2: {
        MakeReservation(reservation_map,client_map);
      }
        break;

        // print confirmation
      case 3: {
        PrintReservationInfo(reservation_map,client_map,large_airport_lst, plane);
      }
        break;

        // quit
      case 4: {
        menu_continue = false;
      }
        break;


      default:
        std::cout << "Invalid selection, your options are 1,2,3,4" << std::endl;
    }
    // end user menu
  }

  std::cout << "=== Thank you for using FLYZONE ===" << std::endl;

	// random number generator used in some tests
	srand(::time_t(NULL));
  std::cout << std::endl;
  std::cout << "=== Start TESTING ===" << std::endl;
  TestResult tr;
  TestRegistry::runAllTests(tr);

	// force console screen to hold
	char ch;
	std::cin >> ch;


    return 0;
}
