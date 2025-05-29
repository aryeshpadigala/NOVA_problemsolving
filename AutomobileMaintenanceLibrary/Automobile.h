#pragma once
#include <string>

class Automobile {
protected:
    std::string make;
    std::string model;
    int year;
    int odometerReading;

public:
    Automobile(const std::string& make, const std::string& model, int year, int odometerReading);
    virtual ~Automobile() = default;

    virtual std::string getType() const = 0;
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    int getOdometerReading() const;
};

class ElectricCar : public Automobile {
public:
    ElectricCar(const std::string&, const std::string&, int, int);
    std::string getType() const override;
};

class GasCar : public Automobile {
public:
    GasCar(const std::string&, const std::string&, int, int);
    std::string getType() const override;
};

class DieselCar : public Automobile {
public:
    DieselCar(const std::string&, const std::string&, int, int);
    std::string getType() const override;
};
