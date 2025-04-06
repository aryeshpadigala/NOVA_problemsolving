#ifndef ROUTEPLANNER_H
#define ROUTEPLANNER_H

#include "routeParameters.h"
#include <iostream>
using namespace std;

template <typename VehicleType>
class RoutePlanner {
private:
    VehicleType vehicle;
    RouteParameters params;

public:
    RoutePlanner(VehicleType v, RouteParameters rp)
        : vehicle(v), params(rp) {}

    void planRoute() const {
        cout << "Planning route for: " << vehicle.getType() << endl;
        cout << "Route Parameters: ";
        params.display();
        cout << "Recommended Route: " 
             << vehicle.getRouteSuggestion(params) << "\n" << endl;
    }
};

#endif 
