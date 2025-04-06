#include "diagnosticTool.h"
#include <iostream>

int main() {
    DiagnosticTool tool1;
    DiagnosticTool tool2;

    tool1.performTest("Engine Check");
    tool2.performTest("Brake System");
    tool1.performTest("Airbag System");

    DiagnosticTool::displayTotalTests();

    return 0;
}
