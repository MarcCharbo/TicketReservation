#include <iostream>
#include <fstream>
#include <unordered_map>

#include "TestHarness.h"
#include "Airport.h"
#include "Client.h"
#include "Reservation.h"
#include "Plane.h"


void LoadData_test(Airport& large_airport_lst_test) {
  std::ifstream airport_file("airports.csv");
  std::string code;

  if (airport_file) {

    std::string line, record, id, type, name, continent, iso_country;
    getline(airport_file, line); // skip header

    while (getline(airport_file, line)) {
      if (!line.empty()) {
        int column_count = 0;

        std::istringstream cell(line); // cell from line

        while (getline(cell, record, ',')) {
          if (!record.empty()) {

            if (column_count == 0) {
              id = record.c_str();
            }
            if (column_count == 2) {
              type = record.c_str();
              type = type.substr(1, type.length() - 2);
            }
            if (column_count == 3) {
              name = record.c_str();
              name = name.substr(1, name.length() - 2);
            }
            if (column_count == 8) {
              iso_country = record.c_str();
              iso_country = iso_country.substr(1, iso_country.length() - 2);
            }
            column_count += 1;
          }
        }
        if (type == "large_airport") {
          large_airport_lst_test.AddAirport(id, name, iso_country);
        }
      }
    }
  }
  airport_file.close();
}

Airport large_airport_lst_test{};

// Test - Airport
TEST(LoadData, airport)
{
   // create empty large_airport_list
  LoadData_test(large_airport_lst_test);

  auto temp_airport = large_airport_lst_test.GetAirport("5222");
  auto temp_airport2 = large_airport_lst_test.GetAirport("5360");

  CHECK_EQUAL("Beirut Rafic Hariri International Airport",temp_airport.name_);
  CHECK_EQUAL("LB",temp_airport.iso_country_);

  CHECK_EQUAL("Fairbanks International Airport",temp_airport2.name_);
  CHECK_EQUAL("US",temp_airport2.iso_country_);
}


// Test - Client
TEST(Client, client)
{
//  Client client{client_nbr, first_name, last_name, phone_number, address,
//                city, zip, country};
  Client client{5,"Marc", "Charbonneau","999-999-999","123 Street","Seattle",
                "12345","USA"};

  CHECK_EQUAL("Marc",client.GetUserFirstName());
  CHECK_EQUAL("Charbonneau",client.GetUserLastName());
  CHECK_EQUAL(5,client.GetUserId());
}

Reservation reservation_test{5,0,"5222","5360","01/10/17","05/05/18",2};

// Test - Reservation
TEST(Reservation, reservation){
//  Reservation reservation{reservation_nbr, current_user_id,
//                          airport_code_departure, airport_code_arrival,
//                          departure_date, arrival_date, seat_selection};



  CHECK_EQUAL(0,reservation_test.GetUserId());
  CHECK_EQUAL("5222",reservation_test.GetAirportDepCode());
  CHECK_EQUAL("5360",reservation_test.GetAirportArrivCode());
  CHECK_EQUAL("01/10/17",reservation_test.GetDepDate());
  CHECK_EQUAL("05/05/18",reservation_test.GetArrivDate());
  CHECK_EQUAL(2,reservation_test.GetSeatSelect());
}

Plane plane_test{50,100, 150}; // create plane
// Test - Plane
TEST(Plane, plane){

  CHECK_EQUAL(150,plane_test.get_nbr_coach_seats());
  CHECK_EQUAL(100,plane_test.get_nbr_ext_leg_seats());
  CHECK_EQUAL(50,plane_test.get_nbr_first_clas_seats());
  CHECK_EQUAL(500,plane_test.get_coach_price());
  CHECK_EQUAL(750,plane_test.get_ext_leg_price());
  CHECK_EQUAL(1000,plane_test.get_first_class_price());
}

std::unordered_map<int, Client> client_map{}; // create empty client map
std::unordered_map<int, Reservation> reservation_map{}; // create empty reservation map

// Test - Print Confirmation
TEST(Print, print){

  Client client{5,"Marc", "Charbonneau","999-999-999","123 Street","Seattle",
                "12345","USA"};

  client_map.insert(std::make_pair(5,client));
  reservation_map.insert(std::make_pair(2,reservation_test));
  auto client_test = client_map.at(5);
  auto reservation = reservation_map.at(2);
  auto arriv_airport = large_airport_lst_test.GetAirport(reservation
                                                       .GetAirportArrivCode());

  CHECK_EQUAL(5,client_test.GetUserId());
  CHECK_EQUAL("Charbonneau",client_test.GetUserLastName());
  CHECK_EQUAL("Marc",client_test.GetUserFirstName());
  CHECK_EQUAL(2,reservation.GetSeatSelect());
  CHECK_EQUAL("5360",arriv_airport.id_);
  CHECK_EQUAL("Fairbanks International Airport",arriv_airport.name_);
  CHECK_EQUAL("US",arriv_airport.iso_country_);

}
