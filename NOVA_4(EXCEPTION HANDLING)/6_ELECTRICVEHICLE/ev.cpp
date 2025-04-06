#include <iostream>
#include <stdexcept>
#include "ev.h"
using namespace std;

ElectricVehicle::ElectricVehicle(int id, string mk, string mdl, double capacity, double level)
    : vehicleId(id), make(mk), model(mdl), batteryCapacity(capacity), chargeLevel(level) 
{
    if (capacity <= 0) throw invalid_argument("Battery capacity must be positive.");
    if (level < 0 || level > capacity) throw invalid_argument("Invalid initial charge level.");
}

void ElectricVehicle::charge(double hours) 
{
    if (hours < 0) throw invalid_argument("Charging time cannot be negative.");

    double chargePerHour = batteryCapacity / 5.0; 
    chargeLevel += chargePerHour * hours;
    if (chargeLevel > batteryCapacity) 
    {
        chargeLevel = batteryCapacity;
    }
}

void ElectricVehicle::drive(double miles) 
{
    if (miles < 0) throw invalid_argument("Driving distance cannot be negative.");

    double consumptionPerMile = batteryCapacity / 300.0; 
    double requiredCharge = consumptionPerMile * miles;

    if (requiredCharge <= chargeLevel) 
    {
        chargeLevel -= requiredCharge;
    } 
    else 
    {
        throw runtime_error("Not enough charge to drive " + to_string(miles) + " miles.");
    }
}

void ElectricVehicle::displayVehicleDetails() 
{
    cout << "Vehicle ID: " << vehicleId << endl;
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    cout << "Charge Level: " << chargeLevel << " kWh" << endl << endl;
}
