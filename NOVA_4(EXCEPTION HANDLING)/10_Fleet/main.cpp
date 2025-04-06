#include "fleet.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    try {
        Engine petrolEngine(PETROL, 1.5);
        Engine dieselEngine(DIESEL, 2.0);

        TouristVehicle tv1("Toyota", "Innova", 2020, 50000, petrolEngine, 7, "Automatic");
        PrivateVehicle pv1("Hyundai", "i20", 2021, 29000, dieselEngine, 4, "Manual");

        Vehicle* vehicles[] = {&tv1, &pv1};
        int size = sizeof(vehicles) / sizeof(vehicles[0]);

        printVehicleDetails(vehicles, size);
        cout << "Total Price: " << calculateTotalPrice(vehicles, size) << endl;
    } catch (const invalid_argument& e) {
        cerr << "Input Error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unexpected error occurred." << endl;
    }

    return 0;
}
