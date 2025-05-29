#include "Automobile.h"
#include "MaintenanceTask.h"
#include "MaintenanceLibrary.h"
#include <iostream>
#include <memory>
#include <map>
#include <limits>
#include <ctime>
#include <algorithm>

// Convert any input string to lowercase for comparison
std::string toLower(const std::string& str) {
    std::string lower;
    std::transform(str.begin(), str.end(), std::back_inserter(lower), ::tolower);
    return lower;
}

void flushInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getCurrentYear() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return now->tm_year + 1900;
}

std::string buildID(const std::string& make, const std::string& model, int year) {
    return make + "_" + model + "_" + std::to_string(year);
}

void showMenu() {
    std::cout << "\n=== Automobile Maintenance Menu ===\n";
    std::cout << "1. Add Vehicle\n2. Remove Vehicle\n3. List Vehicles\n";
    std::cout << "4. Add Maintenance Task\n5. Remove Maintenance Task\n";
    std::cout << "6. View Maintenance Tasks\n7. Exit\n";
    std::cout << "Choose an option (1-7): ";
}

int main() {
    MaintenanceLibrary lib;
    std::map<std::string, std::vector<std::string>> suggestions = {
        {"electric", {"Battery Inspection", "Software Update"}},
        {"gas", {"Oil Change", "Tire Rotation", "Air Filter Replacement"}},
        {"diesel", {"Oil Change", "Tire Rotation", "Fuel Filter Replacement"}}
    };

    int choice;
    do {
        showMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            flushInput();
            std::cout << "Please enter a valid number.\n";
            continue;
        }
        std::cin.ignore();

        if (choice == 1) {
            std::string make, model, type;
            int year, odo;

            std::cout << "Make: ";
            std::getline(std::cin >> std::ws, make);
            std::cout << "Model: ";
            std::getline(std::cin, model);

            std::cout << "Year: ";
            std::cin >> year;
            if (std::cin.fail() || year < 1900 || year > getCurrentYear()) {
                flushInput();
                std::cout << "Invalid year. Try again.\n";
                continue;
            }

            std::cout << "Odometer (km): ";
            std::cin >> odo;
            if (std::cin.fail() || odo < 0) {
                flushInput();
                std::cout << "Invalid odometer reading.\n";
                continue;
            }

            std::cout << "Vehicle Type (electric/gas/diesel): ";
            std::cin >> type;
            type = toLower(type);

            if (type == "electric")
                lib.addVehicle(std::make_shared<ElectricCar>(make, model, year, odo));
            else if (type == "gas")
                lib.addVehicle(std::make_shared<GasCar>(make, model, year, odo));
            else if (type == "diesel")
                lib.addVehicle(std::make_shared<DieselCar>(make, model, year, odo));
            else {
                std::cout << "Invalid vehicle type. Try again.\n";
                continue;
            }

            if (odo > 80000)
                std::cout << "High mileage. Consider Full Check, Oil Change, or Tire Rotation.\n";

        } else if (choice == 2) {
            std::string make, model;
            int year;
            std::cout << "Make: ";
            std::getline(std::cin >> std::ws, make);
            std::cout << "Model: ";
            std::getline(std::cin, model);
            std::cout << "Year: ";
            std::cin >> year;
            lib.removeVehicle(buildID(make, model, year));

        } else if (choice == 3) {
            lib.listVehicles();

        } else if (choice == 4) {
            std::string make, model, task, desc;
            int year, typeCount = 0;
            std::vector<std::string> applicableTypes;

            std::cout << "Vehicle Make: ";
            std::getline(std::cin >> std::ws, make);
            std::cout << "Model: ";
            std::getline(std::cin, model);
            std::cout << "Year: ";
            std::cin >> year;
            std::cin.ignore();

            std::string id = buildID(make, model, year);
            auto v = lib.getVehicleByID(id);
            if (!v) {
                std::cout << "Vehicle not found.\n";
                continue;
            }

            std::string type = v->getType();
            std::cout << "Suggested tasks for " << type << ":\n";
            for (const auto& t : suggestions[type]) std::cout << "- " << t << "\n";
            std::cout << "You can also enter 'Other' to add a custom task.\n";

            std::cout << "Task Name: ";
            std::getline(std::cin, task);
            std::cout << "Description: ";
            std::getline(std::cin, desc);

            std::cout << "How many vehicle types this task applies to? ";
            std::cin >> typeCount;
            std::cin.ignore();
            for (int i = 0; i < typeCount; ++i) {
                std::string t;
                std::cout << "Applicable Type #" << i + 1 << ": ";
                std::cin >> t;
                applicableTypes.push_back(toLower(t));
            }

            MaintenanceTask taskObj(task, desc, applicableTypes);
            lib.addMaintenanceTask(id, taskObj);

        } else if (choice == 5) {
            std::string make, model, task;
            int year;
            std::cout << "Make: ";
            std::getline(std::cin >> std::ws, make);
            std::cout << "Model: ";
            std::getline(std::cin, model);
            std::cout << "Year: ";
            std::cin >> year;
            std::cin.ignore();
            std::string id = buildID(make, model, year);

            std::cout << "Task Name to Remove: ";
            std::getline(std::cin, task);
            lib.removeMaintenanceTask(id, task);

        } else if (choice == 6) {
            std::string make, model;
            int year;
            std::cout << "Make: ";
            std::getline(std::cin >> std::ws, make);
            std::cout << "Model: ";
            std::getline(std::cin, model);
            std::cout << "Year: ";
            std::cin >> year;
            lib.listMaintenanceTasks(buildID(make, model, year));

        } else if (choice == 7) {
            std::cout << "Thank you for using the system. Goodbye!\n";

        } else {
            std::cout << "Invalid menu option. Please choose 1 to 7.\n";
        }

    } while (choice != 7);

    return 0;
}
