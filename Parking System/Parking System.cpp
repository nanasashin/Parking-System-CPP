#include <iostream>
#include <vector>
#include "utils.hpp"
#include "unit.hpp"
#include "front.hpp"

std::vector<Parking_Unit> Unit;

int main () {
    int input;
    bool done = false;
    Utils::init<Parking_Unit>(Unit);

    while (!done) {
        Front<Utils>::front_page(&input);

        switch (input)
        {
        case 2:
            done = true;
            break;
        
        default:
            break;
        }
    }
    
}
