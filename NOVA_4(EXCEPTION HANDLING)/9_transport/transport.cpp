#include "transport.h"
#include <stdexcept>  

Transport::Transport(const std::string &mk, const std::string &mdl, int yr)
    : make(mk), model(mdl), year(yr) {
    if (yr < 1886) throw std::invalid_argument("Invalid year for a vehicle.");
}

Automobile::Automobile(const std::string &mk, const std::string &mdl, int yr, const std::string &type)
    : Transport(mk, mdl, yr), carType(type) {
    if (type.empty()) throw std::invalid_argument("Car type cannot be empty.");
}

void Automobile::displayDetails() const {
    std::cout << "Car Make: " << make << ", Model: " << model 
              << ", Year: " << year << ", Type: " << carType << std::endl;
}

HeavyVehicle::HeavyVehicle(const std::string &mk, const std::string &mdl, int yr, double capacity)
    : Transport(mk, mdl, yr), payloadCapacity(capacity) {
    if (capacity < 0) throw std::invalid_argument("Payload capacity cannot be negative.");
}

void HeavyVehicle::displayDetails() const {
    std::cout << "Truck Make: " << make << ", Model: " << model 
              << ", Year: " << year << ", Payload Capacity: " << payloadCapacity << " tons" << std::endl;
}

Electric::Electric(double capacity, double charge)
    : batteryCapacity(capacity), chargeLevel(charge) {
    if (capacity <= 0) throw std::invalid_argument("Battery capacity must be positive.");
    if (charge < 0 || charge >=100) throw std::invalid_argument("Charge level must be between 0 and 100.");
}

ElectricAutomobile::ElectricAutomobile(const std::string &mk, const std::string &mdl, int yr, 
                                       const std::string &type, double capacity, double charge, int rng)
    : Automobile(mk, mdl, yr, type), Electric(capacity, charge), range(rng) {
    if (rng <= 0) throw std::invalid_argument("Range must be a positive value.");
}

void ElectricAutomobile::displayDetails() const {
    Automobile::displayDetails();
    std::cout << "Range: " << range << " km" << std::endl;
}

void ElectricAutomobile::displayElectricDetails() const {
    std::cout << "Battery Capacity: " << batteryCapacity << " kWh, Charge Level: " << chargeLevel << "%" << std::endl;
}

ElectricHeavyVehicle::ElectricHeavyVehicle(const std::string &mk, const std::string &mdl, int yr, 
                                           double payload, double capacity, double charge, int towing)
    : HeavyVehicle(mk, mdl, yr, payload), Electric(capacity, charge), towingCapacity(towing) {
    if (towing < 0) throw std::invalid_argument("Towing capacity cannot be negative.");
}

void ElectricHeavyVehicle::displayDetails() const {
    HeavyVehicle::displayDetails();
    std::cout << "Towing Capacity: " << towingCapacity << " kg" << std::endl;
}

void ElectricHeavyVehicle::displayElectricDetails() const {
    std::cout << "Battery Capacity: " << batteryCapacity << " kWh, Charge Level: " << chargeLevel << "%" << std::endl;
}
