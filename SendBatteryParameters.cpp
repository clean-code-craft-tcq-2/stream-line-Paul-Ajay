#include "SendBatteryParameters.h"

std::vector<float> generateRandomNumber(float minimumValue, float MaximumValue) {
    std::vector<float> batteryPropertyVector;
    if (minimumValue >= MaximumValue) {
        return {};
    }
    srand(static_cast<unsigned>(ftime(0)));
    for(int itr = 0; itr < COUNT_OF_READINGS; itr ++) {
        batteryPropertyVector.push_back(
            minimumValue + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(MaximumValue - minimumValue))));
    }
    return batteryPropertyVector;
}

batteryParameters getSensorData(float minimumSoc, float maximumSoc, float minumumTemperature, float maximumTemperature) {
    batteryParameters batteryReadings;
    batteryReadings.SOC = generateRandomNumber(minimumSoc, maximumSoc);
    batteryReadings.temperature = generateRandomNumber(minumumTemperature, maximumTemperature);
    return batteryReadings;
}

std::string formatPrintOutput(float value1, float value2) {
    std::string fromattedString;
    fromattedString = std::to_string(value1) + " , " + std::to_string(value2);
    return fromattedString;
}

void printToConsole(std::string stringToPrint) {
    std::cout<<stringToPrint<<std::endl;
}

bool sendSensorData(float minimumSoc, float maximumSoc, float minumumTemperature, float maximumTemperature, functionPtr fPtr) {
    batteryParameters batteryReadings = getSensorData(minimumSoc, maximumSoc, minumumTemperature, maximumTemperature);
    if (batteryReadings.SOC.empty() || batteryReadings.temperature.empty()) {
        return false;
    }
    for (int itr = 0; itr < COUNT_OF_READINGS; itr ++) {
        (*fPtr)(formatPrintOutput(batteryReadings.SOC.at(itr), batteryReadings.temperature.at(itr)));
    }
    return true;
}
