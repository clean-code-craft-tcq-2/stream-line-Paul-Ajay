#pragma once

#include <iostream>
#include <random>

using functionPtr = void (*)(std::string);
#define COUNT_OF_READINGS 50 

typedef struct  {
    std::vector<float> SOC;
    std::vector<float> temperature;
    float minimumSoc;
    float maximumSoc;
    float minumumTemperature;
    float maximumTemperature;
} batteryParameters;

std::vector<float> generateRandomNumber( float, float);
std::string formatPrintOutput(float, float);
void printToConsole(std::string);
batteryParameters getSensorData(float, float, float, float);
bool sendSensorData(float, float, float, float, functionPtr);
