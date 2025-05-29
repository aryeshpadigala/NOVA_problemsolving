#include "MaintenanceLibrary.h"
#include <algorithm>

std::string MaintenanceLibrary::getVehicleID(const std::shared_ptr<Automobile>& vehicle) const {
    return vehicle->getMake() + "_" + vehicle->getModel() + "_" + std::to_string(vehicle->getYear());
}

void MaintenanceLibrary::addVehicle(std::shared_ptr<Automobile> vehicle) {
    vehicles.push_back(vehicle);
}

void MaintenanceLibrary::removeVehicle(const std::string& vehicleID) {
    vehicles.erase(std::remove_if(vehicles.begin(), vehicles.end(),
        [&](const std::shared_ptr<Automobile>& v) {
            return getVehicleID(v) == vehicleID;
        }), vehicles.end());
    vehicleTasks.erase(vehicleID);
}

void MaintenanceLibrary::listVehicles() const {
    for (const auto& v : vehicles) {
        std::cout << "Make: " << v->getMake()
                  << ", Model: " << v->getModel()
                  << ", Year: " << v->getYear()
                  << ", Type: " << v->getType()
                  << ", Odometer: " << v->getOdometerReading() << " km\n";
    }
}

void MaintenanceLibrary::addMaintenanceTask(const std::string& vehicleID, const MaintenanceTask& task) {
    for (const auto& v : vehicles) {
        if (getVehicleID(v) == vehicleID) {
            if (task.isApplicableTo(v->getType())) {
                vehicleTasks[vehicleID].push_back(task);
                std::cout << "✅ Task added successfully.\n";
            } else {
                std::cout << "❌ This task is not applicable for a " << v->getType() << " vehicle.\n";
            }
            return;
        }
    }
    std::cout << "⚠️  Vehicle not found.\n";
}

void MaintenanceLibrary::removeMaintenanceTask(const std::string& vehicleID, const std::string& taskName) {
    auto& tasks = vehicleTasks[vehicleID];
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
        [&](const MaintenanceTask& t) { return t.getTaskName() == taskName; }), tasks.end());
}

void MaintenanceLibrary::listMaintenanceTasks(const std::string& vehicleID) const {
    auto it = vehicleTasks.find(vehicleID);
    if (it != vehicleTasks.end()) {
        for (const auto& t : it->second) {
            std::cout << "- " << t.getTaskName() << ": " << t.getDescription() << "\n";
        }
    } else {
        std::cout << "No tasks recorded for this vehicle.\n";
    }
}

std::shared_ptr<Automobile> MaintenanceLibrary::getVehicleByID(const std::string& vehicleID) const {
    for (const auto& v : vehicles) {
        if (getVehicleID(v) == vehicleID)
            return v;
    }
    return nullptr;
}
