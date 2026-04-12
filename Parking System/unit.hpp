#ifndef UNIT_HPP_
#define UNIT_HPP_

#include <string>

struct Parking_Unit {
    std::string car_name;
    std::string starting_time;
    std::string end_time;
    float total_hour;
    bool occupied = false;
};

#endif