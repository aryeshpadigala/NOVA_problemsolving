#include "transport.h"
#include <iostream>
using namespace std;

int main() {
    ElectricCar eCar("BMW", "Model Z", 2024, 100.0, 75.0, 400);
    ElectricTruck eTruck("AUDI", " Electric v8", 2024, 15.0, 300.0, 80.0, 10000);

    cout << "Electric Car Details:" << endl;
    eCar.displayDetails();
    eCar.displayElectricDetails();

    cout << "Electric Truck Details:" << endl;
    eTruck.displayDetails();
    eTruck.displayElectricDetails();

    return 0;
}
