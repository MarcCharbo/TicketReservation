#include <string>
#include <iostream>

#ifndef AIRPORT_PLANE_H
#define AIRPORT_PLANE_H


class Plane {

public:
    Plane(int nbr_first_clas_seats, int nbr_ext_leg_seats,
          int nbr_coach_seats);
    int get_nbr_first_clas_seats() const { return nbr_first_clas_seats_;}
    int get_nbr_ext_leg_seats() const { return nbr_ext_leg_seats_;}
    int get_nbr_coach_seats() const { return nbr_coach_seats_;;}
    int get_first_class_price() const { return first_class_price_;}
    int get_ext_leg_price() const { return ext_leg_price_;}
    int get_coach_price() const { return coach_price_;}
    ~Plane()= default;

protected:

private:
    int nbr_first_clas_seats_;
    int nbr_ext_leg_seats_;
    int nbr_coach_seats_;
    int first_class_price_ = 1000;
    int ext_leg_price_ = 750;
    int coach_price_ = 500;

};


#endif //AIRPORT_PLANE_H
