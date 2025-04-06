#include "transport.h"
#include <iostream>

int main() {
    try {
        ElectricAutomobile eCar("Tesla", "Model S", 2024, "SUV", 100.0, 80.0, 360);
        ElectricHeavyVehicle eTruck("Volvo", "Electric", 2021, 15.0, 10.0, 15.0, 10000);

        std::cout << "Electric Car Details:" << std::endl;
        eCar.displayDetails();
        eCar.displayElectricDetails();

        std::cout << "Electric Truck Details:" << std::endl;
        eTruck.displayDetails();
        eTruck.displayElectricDetails();
    }
    catch (const std::invalid_argument &e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
    }

    return 0;
}
