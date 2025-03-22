#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
using namespace std;

class Vehicle 
{
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(const string &mk, const string &mdl, int yr);
    virtual void displayDetails() const = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle 
{
public:
    Car(const string &mk, const string &mdl, int yr);
    void displayDetails() const override;
};

class Truck : public Vehicle 
{
private:
    double loadCapacity;

public:
    Truck(const string &mk, const string &mdl, int yr, double capacity);
    void displayDetails() const override;
};

class Electric 
{
protected:
    double batteryCapacity;
    double chargeLevel;

public:
    Electric(double capacity, double charge);
    virtual void displayElectricDetails() const = 0;
    virtual ~Electric() = default;
};

class ElectricCar : public Car, public Electric 
{
private:
    int maxRange;

public:
    ElectricCar(const string &mk, const string &mdl, int yr, double capacity, double charge, int range);
    void displayDetails() const override;
    void displayElectricDetails() const override;
};

class ElectricTruck : public Truck, public Electric 
{
private:
    int towingLimit;

public:
    ElectricTruck(const string &mk, const string &mdl, int yr, double payload, double capacity, double charge, int towing);
    void displayDetails() const override;
    void displayElectricDetails() const override;
};

#endif
