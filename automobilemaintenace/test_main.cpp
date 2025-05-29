#include <gtest/gtest.h>
#include "Automobile.h"
#include "MaintenanceTask.h"
#include "MaintenanceLibrary.h"

TEST(VehicleTests, ElectricCarDetails) {
    ElectricCar car("Tesla", "Model 3", 2021, 12000);
    EXPECT_EQ(car.getMake(), "Tesla");
    EXPECT_EQ(car.getModel(), "Model 3");
    EXPECT_EQ(car.getYear(), 2021);
    EXPECT_EQ(car.getType(), "electric");
    EXPECT_EQ(car.getOdometerReading(), 12000);
}

TEST(TaskTests, ApplicabilityCheck) {
    MaintenanceTask oil("Oil Change", "Replace oil", {"gas", "diesel"});
    EXPECT_TRUE(oil.isApplicableTo("gas"));
    EXPECT_FALSE(oil.isApplicableTo("electric"));
}

TEST(LibraryTests, AddAndListVehicle) {
    MaintenanceLibrary lib;
    lib.addVehicle(std::make_shared<GasCar>("Toyota", "Corolla", 2018, 75000));
    testing::internal::CaptureStdout();
    lib.listVehicles();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Toyota"), std::string::npos);
}

TEST(LibraryTests, AddApplicableTask) {
    MaintenanceLibrary lib;
    std::string id = "Honda_Civic_2015";
    auto car = std::make_shared<GasCar>("Honda", "Civic", 2015, 60000);
    lib.addVehicle(car);

    MaintenanceTask oil("Oil Change", "Replace oil", {"gas"});
    lib.addMaintenanceTask(id, oil);

    testing::internal::CaptureStdout();
    lib.listMaintenanceTasks(id);
    std::string out = testing::internal::GetCapturedStdout();
    EXPECT_NE(out.find("Oil Change"), std::string::npos);
}
