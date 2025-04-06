#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include <iostream>
#include <string>

class DataLogger {
public:
    DataLogger();

    template <typename T>
    void logData(const T& data) const {
        std::cout << "Logging data: " << data << std::endl;
    }
};

#endif
