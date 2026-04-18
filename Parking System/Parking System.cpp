#include <iostream>
#include <vector>
#include "utils.hpp"
#include "unit.hpp"
#include "pages.hpp"

std::vector<Parking_Unit> Unit;
std::vector<Parking_Unit> Record;

int main () {
    int input;
    bool done = false;
    Utils::init<Parking_Unit>(Unit);

    while (!done) {
        Pages<Utils>::front_page(&input);

        switch (input) {
        case Section::enter_park:
            Pages<Utils>::park_page<Parking_Unit>(Unit);
            break;
        case Section::exit_park:
            break; 
        case Section::quit:
            done = true;
            break;
        default:
            break;
        }
    }
}
