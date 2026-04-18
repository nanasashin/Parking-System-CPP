#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    int number;
    std::cout << "Enter an integer: ";

    while (true) {
        if (std::cin >> number) break;
        // 1. Clear error flags
        std::cin.clear(); 
        
        // 2. Discard invalid input in the buffer up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        
        // 3. Inform and retry
        std::cout << "Invalid input. Please enter a valid integer: ";
    }

    std::cout << "Success! You entered: " << number << std::endl;
    return 0;
}