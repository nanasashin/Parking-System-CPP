#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <cmath>
#include <cstdlib>

class Utils {
private:
    static const int line_size = 50;

public: 
    static std::string get_date_time() {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M");
        return oss.str();
    }

    static float get_hour() {
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);
        return localTime->tm_hour + (localTime->tm_min / 60.0f) + (localTime->tm_sec / 3600.0f);
    }

    static void print_line(char line_char, bool new_line=false) {
        for (int i = 0; i < line_size; i++) std::cout << line_char;
        std::cout << "\n";
        if (new_line) std::cout << "\n";
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
};

#endif