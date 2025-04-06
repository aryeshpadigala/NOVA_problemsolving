#include "battery.h"
#include <iostream>

int main() {
    try {
        Battery battery1(180.0, 90.0, 14.8, 27.0);
        Battery battery2(200.0, 120.0, 13.2, 29.5);

        std::cout << "Battery 1 Details: " << battery1 << std::endl;
        std::cout << "Battery 2 Details: " << battery2 << std::endl;

        battery1.charge(15.0);
        battery2.discharge(20.0);

        std::cout << "After charging Battery 1 and discharging Battery 2:" << std::endl;
        std::cout << battery1 << std::endl;
        std::cout << battery2 << std::endl;

        ++battery1;
        --battery2;

        std::cout << "After incrementing Battery 1 and decrementing Battery 2:" << std::endl;
        std::cout << battery1 << std::endl;
        std::cout << battery2 << std::endl;

        battery2 = battery1;

        std::cout << "After assigning Battery 1 to Battery 2:" << std::endl;
        std::cout << battery2 << std::endl;

        std::cout << "Accessing Battery 1's temperature via operator[]: ";
        std::cout << (*battery1)[2] << " °C" << std::endl;
    } 
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
