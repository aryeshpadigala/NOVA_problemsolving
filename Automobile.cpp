#include "Automobile.h"

Automobile::Automobile(const std::string& mk, const std::string& mdl, int yr, int odo)
    : make(mk), model(mdl), year(yr), odometerReading(odo) {}

std::string Automobile::getMake() const { return make; }
std::string Automobile::getModel() const { return model; }
int Automobile::getYear() const { return year; }
int Automobile::getOdometerReading() const { return odometerReading; }

ElectricCar::ElectricCar(const std::string& mk, const std::string& mdl, int yr, int odo)
    : Automobile(mk, mdl, yr, odo) {}
std::string ElectricCar::getType() const { return "electric"; }

GasCar::GasCar(const std::string& mk, const std::string& mdl, int yr, int odo)
    : Automobile(mk, mdl, yr, odo) {}
std::string GasCar::getType() const { return "gas"; }

DieselCar::DieselCar(const std::string& mk, const std::string& mdl, int yr, int odo)
    : Automobile(mk, mdl, yr, odo) {}
std::string DieselCar::getType() const { return "diesel"; }
