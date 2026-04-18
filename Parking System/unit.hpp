#ifndef UNIT_HPP_
#define UNIT_HPP_

#include <string>

struct Parking_Unit {
    bool occupied = false;
    std::string plate_number;
    std::string start_time;
    std::string exit_time;
    float start_hour;
    float hours_parked;
    float paid_amount;
    float change;
};

struct Section {
    static const int enter_park = 0;
    static const int exit_park = 1;
    static const int quit = 2;
};

#endif