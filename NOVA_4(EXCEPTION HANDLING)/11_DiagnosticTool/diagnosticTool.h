
#ifndef DIAGNOSTIC_TOOL_H
#define DIAGNOSTIC_TOOL_H

#include <string>

class DiagnosticTool {
private:
    static int totalTestsPerformed;

public:
    DiagnosticTool();

    void performTest(const std::string& testName);

    static void displayTotalTests();
};

#endif
