#include <iostream>
#include <stdexcept>
#include "vehicle.h"
using namespace std;

Vehicle::Vehicle(int id, string mk, string mdl)
    : vehicleId(id), make(mk), model(mdl) 
{
    if (id <= 0) throw invalid_argument("Vehicle ID must be positive.");
    if (mk.empty() || mdl.empty()) throw invalid_argument("Make and model cannot be empty.");
}

// 🔧 ADD THIS METHOD to support vehicle ID lookup
int Vehicle::getVehicleId() const {
    return vehicleId;
}

// ----------- Car -----------
Car::Car(int id, string mk, string mdl, string engine, double mlg, double prc)
    : Vehicle(id, mk, mdl), engineType(engine), mileage(mlg), price(prc) 
{
    if (mlg < 0) throw invalid_argument("Car mileage cannot be negative.");
    if (prc < 0) throw invalid_argument("Car price cannot be negative.");
}

void Car::displayDetails() const {
    cout << "Car - ID: " << vehicleId << ", Make: " << make
         << ", Model: " << model << ", Engine: " << engineType
         << ", Mileage: " << mileage << " kmpl, Price: " << price << endl;
}

double Car::getMileage() const { return mileage; }
double Car::getPrice() const { return price; }


// ----------- Truck -----------
Truck::Truck(int id, string mk, string mdl, double payload, double mlg, double prc)
    : Vehicle(id, mk, mdl), payloadCapacity(payload), mileage(mlg), price(prc) 
{
    if (payload < 0) throw invalid_argument("Truck payload capacity cannot be negative.");
    if (mlg < 0) throw invalid_argument("Truck mileage cannot be negative.");
    if (prc < 0) throw invalid_argument("Truck price cannot be negative.");
}

void Truck::displayDetails() const {
    cout << "Truck - ID: " << vehicleId << ", Make: " << make
         << ", Model: " << model << ", Payload: " << payloadCapacity
         << " tons, Mileage: " << mileage << " kmpl, Price: " << price << endl;
}

double Truck::getMileage() const { return mileage; }
double Truck::getPrice() const { return price; }
