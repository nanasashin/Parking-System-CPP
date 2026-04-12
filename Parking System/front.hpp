#ifndef FRONT_HPP_
#define FRONT_FPP_

#include <iostream>
#include <vector>

template<class utils>
class Front {
private:
    template<typename vector_type>
    static void print_parking_status (const std::vector<vector_type>& unit_vec) {
        for (int i = 0; i < unit_vec.size(); i++) {
            if (i % 5 == 0) std::cout << "\n";
            std::string status = (unit_vec[i].occupied) ? "Unavailable" : " Available ";
            std::cout << "Unit #" << utils::convert_number(i + 1, unit_vec.size()) << ": " << status << " | ";
        }
        std::cout << "\n";
    }

public:
    static void front_page(int* pInput) {
        utils::print_line('=', true);
        std::cout << utils::center_text("Parking System") << "\n\n";
        utils::print_line('=', true);
        std::cout << "[0] Park Car\n";
        std::cout << "[1] Exit Car\n";
        std::cout << "[2] Quit\n\n";
        utils::print_line('=', true);
        std::cout << "Input: "; std::cin >> *pInput;
    }
};

#endif