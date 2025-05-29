#include "MaintenanceTask.h"
#include <algorithm>

MaintenanceTask::MaintenanceTask(const std::string& name, const std::string& desc, const std::vector<std::string>& types)
    : taskName(name), description(desc), applicableVehicleTypes(types) {}

std::string MaintenanceTask::getTaskName() const { return taskName; }
std::string MaintenanceTask::getDescription() const { return description; }
const std::vector<std::string>& MaintenanceTask::getApplicableVehicleTypes() const { return applicableVehicleTypes; }

bool MaintenanceTask::isApplicableTo(const std::string& vehicleType) const {
    return std::find(applicableVehicleTypes.begin(), applicableVehicleTypes.end(), vehicleType) != applicableVehicleTypes.end();
}
