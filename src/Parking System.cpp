#include <iostream>
#include <vector>
#include "../headers/pages.hpp"
#include "../headers/unit.hpp"

std::vector<unit::parking_unit> Unit;
std::vector<unit::parking_unit> Record;

void init(std::vector<unit::parking_unit>& unit_vec) {
    unit::parking_unit sample_unit;
    for (int i = 0; i < 20; i++) unit_vec.push_back(sample_unit);
}

int main () {
    int input;
    bool done = false;
    init(Unit);

    while (!done) {
        pages::front_page(&input);

        switch (input) {
            case section::enter_park:
                pages::park_page(Unit);
                break;
            case section::exit_park:
                pages::exit_page(Unit, Record);
                break; 
            case section::view_records:
                break;
            case section::quit:
                done = true;
                break;
            default:
                break;
        }
    }

    return 0;
}
