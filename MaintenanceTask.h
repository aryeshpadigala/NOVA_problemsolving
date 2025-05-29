#pragma once
#include <string>
#include <vector>

class MaintenanceTask {
private:
    std::string taskName;
    std::string description;
    std::vector<std::string> applicableVehicleTypes;

public:
    MaintenanceTask(const std::string& name, const std::string& desc, const std::vector<std::string>& types);

    std::string getTaskName() const;
    std::string getDescription() const;
    const std::vector<std::string>& getApplicableVehicleTypes() const;

    bool isApplicableTo(const std::string& vehicleType) const;
};
