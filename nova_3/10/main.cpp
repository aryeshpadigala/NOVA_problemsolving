#include "fleet.h"
#include <iostream>
using namespace std;

int main() {
    Engine petrolEngine(PETROL, 1.8);    
    Engine dieselEngine(DIESEL, 2.5);
    Engine electricEngine(ELECTRIC, 100.0);
    Engine hybridEngine(HYBRID, 1.2);

    TouristVehicle tv1("Mercedes", "Sprinter", 2019, 55000, petrolEngine, 15, "Automatic");
    TouristVehicle tv2("Ford", "Transit", 2021, 48000, dieselEngine, 12, "Manual");
    PrivateVehicle pv1("BMW", "X5", 2022, 62000, hybridEngine, 4, "Automatic");
    PrivateVehicle pv2("Tesla", "Model X", 2023, 80000, electricEngine, 4, "Automatic");

    Vehicle* vehicles[] = {&tv1, &tv2, &pv1, &pv2};
    int size = sizeof(vehicles) / sizeof(vehicles[0]);

    cout << "Fleet Details:\n";
    printVehicleDetails(vehicles, size);
    
    cout << "\nTotal Price of Fleet: $" << calculateTotalPrice(vehicles, size) << endl;

    return 0;
}
