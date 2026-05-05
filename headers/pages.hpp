#ifndef PAGES_HPP_
#define PAGES_FPP_

#include <iostream>
#include <vector>
#include "utils.hpp"
#include "unit.hpp"

class pages {
public:
    static void front_page(int* pInput) {
        header();
        std::cout << "[0] Park Car\n";
        std::cout << "[1] Exit Car\n";
        std::cout << "[2] View Records\n";
        std::cout << "[3] Quit\n";
        footer();

        *pInput = input_handler("Input:", unit::range{0, 3});
        utils::clear_screen();
    }

    static void park_page(std::vector<unit::parking_unit>& unit_vec) {
        print_parking_status(unit_vec);
        int parking_slot_number, subscription_plan;
        while (true) {
            parking_slot_number = input_handler("Input Parking Number [0 to exit page]:", unit::range{0, static_cast<int>(unit_vec.size())});
            if (!parking_slot_number) {
                utils::clear_screen();
                return;
            }
            parking_slot_number -= 1;
            if (!unit_vec[parking_slot_number].occupied) break;
            std::cout << "Parking Spot Occupied !!\n";
        }
        print_subscription_plan();
        subscription_plan = input_handler("Input Subscription Plan:", unit::range{subscription_type::hourly, subscription_type::yearly});

        unit_vec[parking_slot_number].occupied = true;
        unit_vec[parking_slot_number].plate_number = input_handler<std::string>("Input Plate Number:");
        unit_vec[parking_slot_number].enter_date_time = utils::get_full_date();
        page_exit();
    }

    static void exit_page(std::vector<unit::parking_unit>& unit_vec, std::vector<unit::parking_unit>& record_vec) {
        print_parking_status(unit_vec);
        int parking_slot_number;
        while (true) {
            parking_slot_number = input_handler("Input Parking Number [0 to exit page]:", unit::range{0, static_cast<int>(unit_vec.size())});
            if (!parking_slot_number) {
                utils::clear_screen();
                return;
            }
            parking_slot_number -= 1;
            if (unit_vec[parking_slot_number].occupied) break;
            std::cout << "Parking Spot Empty !!\n";
        }

        unit_vec[parking_slot_number].exit_date_time = utils::get_full_date();
        record_vec.push_back(unit_vec[parking_slot_number]);
        unit_vec[parking_slot_number] = {};
        page_exit();
    }

private:
    static void print_parking_status(const std::vector<unit::parking_unit>& unit_vec) {
        header();
        for (int i = 0; i < unit_vec.size(); i++) {
            if (i % 5 == 0) std::cout << "\n";
            std::string status = (unit_vec[i].occupied) ? "Unavailable" : " Available ";
            std::cout << "Unit #" << utils::convert_number(i + 1, unit_vec.size()) << ": " << status << " | ";
        }
        std::cout << "\n";
        footer();
    }

    static void print_subscription_plan() {
        utils::print_line();
        std::cout << "[" << subscription_type::hourly << "] Hourly\n";
        std::cout << "[" << subscription_type::daily << "] Daily\n";
        std::cout << "[" << subscription_type::monthly << "] Monthly\n";
        std::cout << "[" << subscription_type::yearly << "] Yearly\n\n";
        utils::print_line();
    }

    template <typename T = int>
    static T input_handler(std::string text, unit::range range = unit::range{}, std::string error_message="invalid input") {
        T input;
        text += " ";
        std::cout << text;
        while (true) {
            while (!(std::cin >> input)) {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "< " << error_message << " > " << text;
            }
            if constexpr (std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>) {
                if (!((input >= range.min && input <= range.max) || (!range.min && !range.max))) {
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "< " << error_message << " > " << text;
                }
                else break;
            } 
            else break;
        }
        return input;
    }

    static void header() {
        utils::print_line();
        std::cout << utils::center_text("Parking System") << "\n\n";
        utils::print_line();
    }

    static void footer() {
        std::cout << "\n";
        utils::print_line();
    }

    static void page_exit(std::string text="Enter 1 to Exit:", int exit_num=1) {
        input_handler(text, unit::range{exit_num, exit_num});
        utils::clear_screen();
    }
};

#endif