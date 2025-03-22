#ifndef FLEET_H
#define FLEET_H

#include <string>
using namespace std;

enum EngineType { PETROL, DIESEL, ELECTRIC, HYBRID };

class Engine {
private:
    EngineType type;
    double capacity;

public:
    Engine(EngineType t, double c);
    EngineType getEngineType() const;
    double getCapacity() const;
};

class Vehicle {
protected:
    string make;
    string model;
    int year;
    double price;
    Engine engine;

public:
    Vehicle(const string& mk, const string& mdl, int yr, double prc, const Engine& eng);
    virtual ~Vehicle() = default;
    virtual double calculateMileage() const = 0;
    virtual void printDetails() const = 0;
    double getPrice() const;  
};

class TouristVehicle : public Vehicle {
private:
    int seats;
    string transmission;

public:
    TouristVehicle(const string& mk, const string& mdl, int yr, double prc, const Engine& eng, int s, const string& t);
    double calculateMileage() const override;
    void printDetails() const override;
};

class PrivateVehicle : public Vehicle {
private:
    int doors;
    string transmission;

public:
    PrivateVehicle(const string& mk, const string& mdl, int yr, double prc, const Engine& eng, int d, const string& t);
    double calculateMileage() const override;
    void printDetails() const override;
};

double calculateTotalPrice(Vehicle* vehicles[], int size);
void printVehicleDetails(Vehicle* vehicles[], int size);

#endif
