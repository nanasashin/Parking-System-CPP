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

enum Section {
    enter_park = 0,
    exit_park = 1,
    quit = 2,
};

#endif