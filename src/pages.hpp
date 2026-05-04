#ifndef PAGES_HPP_
#define PAGES_FPP_

#include <iostream>
#include <vector>
#include "utils.hpp"

class Pages {
public:
    static void front_page(int* pInput) {
        header();
        std::cout << "[0] Park Car\n";
        std::cout << "[1] Exit Car\n";
        std::cout << "[2] Quit\n";
        footer();

        *pInput = num_input_handler("Input:", 0, 2);
        Utils::clear_screen();
    }

    template <typename vector_type>
    static void park_page(std::vector<vector_type>& unit_vec) {
        print_parking_status<vector_type>(unit_vec);
        int parking_slot_number;
        while (true) {
            parking_slot_number = num_input_handler("Input Parking Number [-1 to exit page]:", -1, unit_vec.size());
            if (parking_slot_number == -1) {
                Utils::clear_screen();
                return;
            }
            parking_slot_number -= 1;
            if (!unit_vec[parking_slot_number].occupied) break;
            std::cout << "Parking Spot Occupied !!\n";
        }
        unit_vec[parking_slot_number].occupied = true;
        unit_vec[parking_slot_number].plate_number = str_input_handler("Input Plate Number:");
        unit_vec[parking_slot_number].start_time = Utils::get_date_time();
        unit_vec[parking_slot_number].start_hour = Utils::get_hours();
        page_exit();
    }

    template<typename vector_type>
    static void exit_page(std::vector<vector_type>& unit_vec) {
        print_parking_status<vector_type>(unit_vec);
        int parking_slot_number;
        while (true) {
            parking_slot_number = num_input_handler("Input Parking Number [-1 to exit page]:", -1, unit_vec.size());
            if (parking_slot_number == -1) {
                Utils::clear_screen();
                return;
            }
            parking_slot_number -= 1;
            if (unit_vec[parking_slot_number].occupied) break;
            std::cout << "Parking Spot Empty !!\n";
        }
        unit_vec[parking_slot_number] = {};
        page_exit();
    }

private:
    template<typename vector_type>
    static void print_parking_status (const std::vector<vector_type>& unit_vec) {
        header();
        for (int i = 0; i < unit_vec.size(); i++) {
            if (i % 5 == 0) std::cout << "\n";
            std::string status = (unit_vec[i].occupied) ? "Unavailable" : " Available ";
            std::cout << "Unit #" << Utils::convert_number(i + 1, unit_vec.size()) << ": " << status << " | ";
        }
        std::cout << "\n";
        footer();
    }

    template <typename T = int>
    static T num_input_handler(std::string text, int min=0, int max=0, std::string error_message="invalid input") {
        T input;
        text += " ";
        std::cout << text;
        while (!(std::cin >> input) && ((input >= min && input <= max) || (min == 0 && max == 0))) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "< " << error_message << " > " << text;
        }
        return input;
    }

    static std::string str_input_handler(std::string text, std::string error_message="invalid input") {
        std::string input;
        text += " ";
        std::cout << text;
        while (!(std::cin >> input)) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "< " << error_message << " > " << text;
        }
        return input;
    }

    static void header() {
        Utils::print_line('=', true);
        std::cout << Utils::center_text("Parking System") << "\n\n";
        Utils::print_line('=', true);
    }

    static void footer() {
        std::cout << "\n";
        Utils::print_line('=', true);
    }

    static void page_exit(std::string text="Enter 1 to Exit:", int exit_num=1) {
        num_input_handler(text, exit_num, exit_num);
        Utils::clear_screen();
    }
};

#endif