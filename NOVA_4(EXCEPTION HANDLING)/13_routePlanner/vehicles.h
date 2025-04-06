#ifndef VEHICLES_H
#define VEHICLES_H

#include "routeParameters.h"
#include <string>
using namespace std;

class Car {
public:
    string getType() const { return "Car"; }

    string getRouteSuggestion(const RouteParameters& params) const {
        if (params.trafficCondition == "Heavy")
            return "Use alternate route through suburbs.";
        return "Use highway for faster travel.";
    }
};

class Truck {
public:
    string getType() const { return "Truck"; }

    string getRouteSuggestion(const RouteParameters& params) const {
        if (params.roadCondition == "Narrow")
            return "Avoid narrow roads. Take industrial route.";
        return "Follow main truck route.";
    }
};

class Motorcycle {
public:
    string getType() const { return "Motorcycle"; }

    string getRouteSuggestion(const RouteParameters& params) const {
        if (params.vehicleCapability == "High Performance")
            return "Use scenic hilly roads.";
        return "Take city routes avoiding highways.";
    }
};

#endif // VEHICLES_H
