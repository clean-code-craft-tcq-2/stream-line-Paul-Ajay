#include "SendBatteryParameters.h"

int main() {
    float minimumSoc = 0.0;
    float maximumSoc = 1.0;
    float minumumTemperature = 40;
    float maximumTemperature = 100;
    sendSensorData(minimumSoc, maximumSoc, minumumTemperature, maximumTemperature, *printToConsole);
    return 0;
}