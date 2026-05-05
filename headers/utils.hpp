#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include "unit.hpp"

class utils {
public: 
    static unit::date_and_time get_full_date() {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream date_time;
        date_time << std::put_time(&tm, "%M%H%d%m%Y");
        return str_to_date_time_unit(date_time.str());
    }

    static void print_line(unit::new_line new_line = unit::new_line{}, char line_char='=') {
        for (int i = 0; i < line_size; i++) std::cout << line_char;
        std::cout << "\n";
        if (new_line.put) std::cout << "\n";
    }

    static std::string center_text(std::string text) {
        int space = static_cast<int>(std::round((line_size / 2) - ((float)text.length()/2.0)));
        for (int i = 0; i < space; i++) text = " " + text;
        return text;
    }

    static std::string convert_number(int number, int max_number) {
        int max_decimal_number = 0;
        int decimal_number = 0;
        std::string number_string = std::to_string(number);
        while (max_number > 0) {
            max_decimal_number += 1;
            max_number /= 10;
        }
        while (number > 0) {
            decimal_number += 1;
            number /= 10;
        } 
        for (int i = 0; i < max_decimal_number - decimal_number; i++) number_string = "0" + number_string;
        return number_string; 
    }

    template<typename T>
    static void init(std::vector<T>& unit_vec, int size = 20) {
        T sample_unit;
        for (int i = 0; i < size; i++) unit_vec.push_back(sample_unit);
    }

    static void clear_screen() {
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
    }

    static bool is_inbound(int input, int max) {
        return (max >= input) ? true : false;
    }

private:
    static const int line_size = 50;

    static unit::date_and_time str_to_date_time_unit(std::string temp) {
        int mins = std::stoi(std::string{temp[0], temp[1]});
        int hours = std::stoi(std::string{temp[2], temp[3]});
        int day = std::stoi(std::string{temp[4], temp[5]});
        int month = std::stoi(std::string{temp[6], temp[7]});
        int year = std::stoi(std::string{temp[8], temp[9], temp[10], temp[11]});
        return unit::date_and_time {mins, hours, day, month, year};
    }
        
};

#endif