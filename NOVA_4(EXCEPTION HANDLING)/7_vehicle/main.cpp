#include <iostream>
#include <algorithm>
#include <set>
#include "vehicle.h"
using namespace std;

void displayVehicleDetails(Vehicle* vehicles[], int size) {
    for (int i = 0; i < size; ++i)
        vehicles[i]->displayDetails();
}

double calculateTotalMileage(Vehicle* vehicles[], int size) {
    double totalMileage = 0.0;
    for (int i = 0; i < size; ++i)
        totalMileage += vehicles[i]->getMileage();
    return totalMileage;
}

void sortVehiclesByPrice(Vehicle* vehicles[], int size) {
    sort(vehicles, vehicles + size, [](Vehicle* v1, Vehicle* v2) {
        return v1->getPrice() > v2->getPrice();
    });
}

Vehicle* searchVehiclesByVehicleId(Vehicle* vehicles[], int size, int vehicleId) {
    for (int i = 0; i < size; ++i) {
        if (vehicles[i]->getVehicleId() == vehicleId)
            return vehicles[i];
    }
    return nullptr;
}

int main() {
    try {
        set<int> usedIds;

        Car car1(14235, "Toyota", "Supra GR", "Petrol", 14.5, 4500000);
        Car car2(26781, "BMW", "i4 M50", "Electric", 16.0, 5200000);
        Truck truck1(38429, "Mercedes-Benz", "Actros", 26.0, 8.5, 7500000);
        Truck truck2(47290, "Scania", "R500", 30.0, 9.0, 6800000);
        Truck truck3(51984, "MAN", "TGS 28.360", 22.0, 8.2, 5900000);


        Vehicle* all[] = {&car1, &car2, &truck1, &truck2, &truck3};
        Vehicle* vehicles[5];
        int size = 0;

        for (auto v : all) {
            int id = v->getVehicleId();
            if (usedIds.find(id) == usedIds.end()) {
                usedIds.insert(id);
                vehicles[size++] = v;
            } else {
                cerr << "Duplicate vehicle ID " << id << " detected. Skipping.\n";
            }
        }

        cout << "Displaying vehicle details:\n";
        displayVehicleDetails(vehicles, size);

        cout << "Total mileage of all vehicles: " << calculateTotalMileage(vehicles, size) << " kmpl\n";

        sortVehiclesByPrice(vehicles, size);
        cout << "Vehicles sorted by price:\n";
        displayVehicleDetails(vehicles, size);

        int searchId;
        cout << "Enter vehicle ID to search: ";
        cin >> searchId;

        Vehicle* found = searchVehiclesByVehicleId(vehicles, size, searchId);
        if (found) {
            cout << "Vehicle found:\n";
            found->displayDetails();
        } else {
            cout << "Vehicle not found.\n";
        }

    } catch (const exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;
    }

    return 0;
}
