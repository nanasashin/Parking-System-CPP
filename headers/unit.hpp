#ifndef UNIT_HPP_
#define UNIT_HPP_

#include <string>

class unit {
public:
    struct date_and_time {
        int min;
        int hours;
        int day;
        int month;
        int year;
    };

    struct parking_unit {
        bool occupied = false;
        std::string plate_number;
        date_and_time enter_date_time;
        date_and_time exit_date_time;
        float fee;
        float paid_amount;
        float change;
    };
};

enum section {
    enter_park,
    exit_park,
    view_records,
    quit,
};

enum rate_fee {
    hour = 5,
    day = 60,
    month = 1200,
    year = 12000
};

#endif