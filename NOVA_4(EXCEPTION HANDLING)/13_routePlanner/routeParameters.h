#ifndef ROUTEPARAMETERS_H
#define ROUTEPARAMETERS_H

#include <string>
#include <iostream>
using namespace std;

struct RouteParameters {
    string trafficCondition;
    string roadCondition;
    string vehicleCapability;

    void display() const {
        cout << "Traffic: " << trafficCondition
             << ", Road: " << roadCondition
             << ", Capability: " << vehicleCapability << endl;
    }
};

#endif 
