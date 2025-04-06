#include "fleet.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Engine::Engine(EngineType t, double c) : type(t), capacity(c) {
    if (c <= 0) throw invalid_argument("Engine capacity must be positive.");
}

EngineType Engine::getEngineType() const {
    return type;
}

double Engine::getCapacity() const {
    return capacity;
}

Vehicle::Vehicle(const string& mk, const string& mdl, int yr, double prc, const Engine& eng)
    : make(mk), model(mdl), year(yr), price(prc), engine(eng) {
    if (yr < 1886 || yr > 2100) throw invalid_argument("Year is out of valid range.");
    if (prc <= 0) throw invalid_argument("Vehicle price must be positive.");
}

TouristVehicle::TouristVehicle(const string& mk, const string& mdl, int yr, double prc, const Engine& eng, int s, const string& t)
    : Vehicle(mk, mdl, yr, prc, eng), seats(s), transmission(t) {
    if (s <= 0) throw invalid_argument("Number of seats must be positive.");
    if (t.empty()) throw invalid_argument("Transmission type cannot be empty.");
}

double TouristVehicle::calculateMileage() const {
    return engine.getCapacity() * 10.0;
}

void TouristVehicle::printDetails() const {
    cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Price: " << price
         << ", Engine Type: " << engine.getEngineType() << ", Capacity: " << engine.getCapacity()
         << ", Seats: " << seats << ", Transmission: " << transmission << endl;
}

PrivateVehicle::PrivateVehicle(const string& mk, const string& mdl, int yr, double prc, const Engine& eng, int d, const string& t)
    : Vehicle(mk, mdl, yr, prc, eng), doors(d), transmission(t) {
    if (d <= 0) throw invalid_argument("Number of doors must be positive.");
    if (t.empty()) throw invalid_argument("Transmission type cannot be empty.");
}

double Vehicle::getPrice() const {
    return price;
}


double PrivateVehicle::calculateMileage() const {
    return engine.getCapacity() * 12.0;
}

void PrivateVehicle::printDetails() const {
    cout << "Make: " << make << ", Model: " << model << ", Year: " << year << ", Price: " << price
         << ", Engine Type: " << engine.getEngineType() << ", Capacity: " << engine.getCapacity()
         << ", Doors: " << doors << ", Transmission: " << transmission << endl;
}

void displayOutput(const Vehicle& v) {
    v.printDetails();
}

double calculateTotalPrice(Vehicle* vehicles[], int size) {
    double totalPrice = 0;
    for (int i = 0; i < size; ++i) {
        totalPrice += vehicles[i]->getPrice();
    }
    return totalPrice;
}


void printVehicleDetails(Vehicle* vehicles[], int size) {
    for (int i = 0; i < size; ++i) {
        vehicles[i]->printDetails();
    }
}
