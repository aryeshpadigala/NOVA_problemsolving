#include <iostream>
#include <stdexcept>
#include "ev.h"
using namespace std;

int main() 
{
    try {
        ElectricVehicle ev1(12345, "Tesla", "Model 3", 75.0, 50.0);
        ElectricVehicle ev2(67890, "Nissan", "Leaf", 60.0, 30.0);
        ev1.charge(2);
        ev1.displayVehicleDetails();
        ev1.drive(100);
        ev1.displayVehicleDetails();
        ev2.charge(1.5);
        ev2.displayVehicleDetails();
        ev2.drive(50);
        ev2.displayVehicleDetails();
    }
    catch (const exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;
    }

    return 0;
}
