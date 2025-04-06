#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>

class Transport {
protected:
    std::string make;
    std::string model;
    int year;

public:
    Transport(const std::string &mk, const std::string &mdl, int yr);
    virtual void displayDetails() const = 0;
    virtual ~Transport() = default; 
};

class Automobile : public Transport {
private:
    std::string carType;

public:
    Automobile(const std::string &mk, const std::string &mdl, int yr, const std::string &type);
    void displayDetails() const override;
};

class HeavyVehicle : public Transport {
private:
    double payloadCapacity;

public:
    HeavyVehicle(const std::string &mk, const std::string &mdl, int yr, double capacity);
    void displayDetails() const override;
};
class Electric {
protected:
    double batteryCapacity;
    double chargeLevel;

public:
    Electric(double capacity, double charge);
    virtual void displayElectricDetails() const = 0;
    virtual ~Electric() = default;
};

class ElectricAutomobile : public Automobile, public Electric {
private:
    int range;

public:
    ElectricAutomobile(const std::string &mk, const std::string &mdl, int yr, const std::string &type, double capacity, double charge, int rng);
    void displayDetails() const override;
    void displayElectricDetails() const override;
};

class ElectricHeavyVehicle : public HeavyVehicle, public Electric {
private:
    int towingCapacity;

public:
    ElectricHeavyVehicle(const std::string &mk, const std::string &mdl, int yr, double payload, double capacity, double charge, int towing);
    void displayDetails() const override;
    void displayElectricDetails() const override;
};

#endif
