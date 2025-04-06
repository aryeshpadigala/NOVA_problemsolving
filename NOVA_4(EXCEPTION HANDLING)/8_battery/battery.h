#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>
#include <vector>

class Battery {
private:
    double capacity;
    double chargeLevel;
    double voltage;
    double temperature;
    std::vector<double> parameters;

public:
    Battery(double cap = 100.0, double chargeLvl = 50.0, double volt = 12.0, double temp = 25.0);
    void charge(double amount);
    void discharge(double amount);
    double& operator[](int index);
    Battery& operator*();
    Battery* operator->();
    Battery& operator++();
    Battery& operator--();
    Battery& operator=(const Battery& other);
    friend std::ostream& operator<<(std::ostream& out, const Battery& battery);
    friend std::istream& operator>>(std::istream& in, Battery& battery);
};

#endif
