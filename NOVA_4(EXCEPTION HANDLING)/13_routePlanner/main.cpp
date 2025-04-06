#include "routePlanner.h"
#include "vehicles.h"

int main() {
    RouteParameters carParams = {"Light", "Smooth", "Standard"};
    RouteParameters truckParams = {"Moderate", "Wide", "Heavy Load"};
    RouteParameters bikeParams = {"Low", "Curvy", "Agile Handling"};


    Car car;
    Truck truck;
    Motorcycle motorcycle;

    RoutePlanner<Car> carPlanner(car, carParams);
    RoutePlanner<Truck> truckPlanner(truck, truckParams);
    RoutePlanner<Motorcycle> bikePlanner(motorcycle, bikeParams);

    carPlanner.planRoute();
    truckPlanner.planRoute();
    bikePlanner.planRoute();

    return 0;
}
