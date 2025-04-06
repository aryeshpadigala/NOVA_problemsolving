#include "diagnosticTool.h"
#include <iostream>

int DiagnosticTool::totalTestsPerformed = 0;

DiagnosticTool::DiagnosticTool() {}

void DiagnosticTool::performTest(const std::string& testName) {
    std::cout << "Performing diagnostic test: " << testName << std::endl;
    totalTestsPerformed++;
}

void DiagnosticTool::displayTotalTests() {
    std::cout << "Total diagnostic tests performed: " << totalTestsPerformed << std::endl;
}
