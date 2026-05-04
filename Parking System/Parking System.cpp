#include <iostream>
#include <vector>
#include "unit.hpp"
#include "pages.hpp"

std::vector<Parking_Unit> Unit;
std::vector<Parking_Unit> Record;

void init(std::vector<Parking_Unit>& unit_vec) {
    Parking_Unit sample_unit;
    for (int i = 0; i < unit_vec.size(); i++) unit_vec.push_back(sample_unit);
}

int main () {
    int input;
    bool done = false;
    init(Unit);

    while (!done) {
        Pages::front_page(&input);

        switch (input) {
            case Section::enter_park:
                Pages::park_page<Parking_Unit>(Unit);
                break;
            case Section::exit_park:
                Pages::exit_page<Parking_Unit>(Unit);
                break; 
            case Section::quit:
                done = true;
                break;
            default:
                break;
        }
    }

}
