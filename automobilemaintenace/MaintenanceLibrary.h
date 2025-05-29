#pragma once
#include "Automobile.h"
#include "MaintenanceTask.h"
#include <vector>
#include <map>
#include <memory>
#include <iostream>

class MaintenanceLibrary {
private:
    std::vector<std::shared_ptr<Automobile>> vehicles;
    std::map<std::string, std::vector<MaintenanceTask>> vehicleTasks;

    std::string getVehicleID(const std::shared_ptr<Automobile>& vehicle) const;

public:
    void addVehicle(std::shared_ptr<Automobile> vehicle);
    void removeVehicle(const std::string& vehicleID);
    void listVehicles() const;

    void addMaintenanceTask(const std::string& vehicleID, const MaintenanceTask& task);
    void removeMaintenanceTask(const std::string& vehicleID, const std::string& taskName);
    void listMaintenanceTasks(const std::string& vehicleID) const;

    std::shared_ptr<Automobile> getVehicleByID(const std::string& vehicleID) const;
};
