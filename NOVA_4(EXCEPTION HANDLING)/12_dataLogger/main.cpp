#include "dataLogger.h"
#include <string>

int main() {
    DataLogger logger;

    logger.logData(390);                        
    logger.logData(19.78f);    
    logger.logData('V');
    logger.logData("Engine");         
    logger.logData(true);  

    return 0;
}
