#include "transport.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(const string &mk, const string &mdl, int yr) : make(mk), model(mdl), year(yr) {}

Car::Car(const string &mk, const string &mdl, int yr) : Vehicle(mk, mdl, yr) {}

void Car::displayDetails() const 
{
    cout << "Car Make: " << make << ", Model: " << model << ", Year: " << year << endl;
}

Truck::Truck(const string &mk, const string &mdl, int yr, double capacity)
    : Vehicle(mk, mdl, yr), loadCapacity(capacity) {}

void Truck::displayDetails() const {
    cout << "Truck Make: " << make << ", Model: " << model << ", Year: " << year << ", Load Capacity: " << loadCapacity << " tons" << endl;
}

Electric::Electric(double capacity, double charge) : batteryCapacity(capacity), chargeLevel(charge) {}

ElectricCar::ElectricCar(const string &mk, const string &mdl, int yr, double capacity, double charge, int range)
    : Car(mk, mdl, yr), Electric(capacity, charge), maxRange(range) {}

void ElectricCar::displayDetails() const 
{
    Car::displayDetails();
    cout << "Range: " << maxRange << " km" << endl;
}

void ElectricCar::displayElectricDetails() const {
    cout << "Battery Capacity: " << batteryCapacity << " kWh, Charge Level: " << chargeLevel << "%" << endl;
}

ElectricTruck::ElectricTruck(const string &mk, const string &mdl, int yr, double payload, double capacity, double charge, int towing)
    : Truck(mk, mdl, yr, payload), Electric(capacity, charge), towingLimit(towing) {}

void ElectricTruck::displayDetails() const {
    Truck::displayDetails();
    cout << "Towing Capacity: " << towingLimit << " kg" << endl;
}

void ElectricTruck::displayElectricDetails() const {
    cout << "Battery Capacity: " << batteryCapacity << " kWh, Charge Level: " << chargeLevel << "%" << endl;
}
