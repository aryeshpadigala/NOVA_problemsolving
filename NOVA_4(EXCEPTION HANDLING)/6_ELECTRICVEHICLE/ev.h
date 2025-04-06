#ifndef EV_H
#define EV_H

#include <string>
using namespace std;
class ElectricVehicle 
{
private:
    int vehicleId;
    string make;
    string model;
    double batteryCapacity;
    double chargeLevel;
public:
    ElectricVehicle(int id, string mk, string mdl, double capacity, double level);
    void charge(double hours);
    void drive(double miles);
    void displayVehicleDetails();
};

#endif