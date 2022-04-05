#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "SendBatteryParameters.h"

TEST_CASE("test case for checking formatPrintOutput function") {
    REQUIRE(formatPrintOutput(3.5, 4.0) == "3.500000 , 4.000000");
}

TEST_CASE("test case for checking generateRandomNumber function") {
    float minimumValue = 0.0;
    float MaximumValue = 10.0;
    std::vector<float> values;
    values = generateRandomNumber(minimumValue, MaximumValue);
    REQUIRE(static_cast<int>(values.size()) == 50);
    REQUIRE(*std::min_element(values.begin(), values.end()) >= minimumValue);
    REQUIRE(*std::max_element(values.begin(), values.end()) <= MaximumValue);
    REQUIRE(generateRandomNumber(0.0, 0.0).empty());
    REQUIRE(generateRandomNumber(0.0, -1.5).empty());
}

TEST_CASE("test case for checking getSensorData function") {
    batteryParameters batteryReadings = getSensorData(0.0, 1.0, 2.0, 100.0);
    REQUIRE(static_cast<int>(batteryReadings.SOC.size()) == 50);
    REQUIRE(static_cast<int>(batteryReadings.temperature.size()) == 50);
}

TEST_CASE("test case for checking sendSensorData function") {
    GIVEN("inputs with correct limits") {
        float minimumSoc = 0.0;
        float maximumSoc = 1.0;
        float minumumTemperature = 40;
        float maximumTemperature = 100;
        WHEN("sendSensorData() is called with input array") {
            bool expectedOutput = true;
            bool outputFromFunction = sendSensorData(minimumSoc, maximumSoc, minumumTemperature, maximumTemperature, *printToConsole);
            THEN("output in given format is generated and send to console") {
                REQUIRE(outputFromFunction == expectedOutput);
            }
        }
    }
    GIVEN("inputs with incorrect limits") {
        float minimumSoc = 0.0;
        float maximumSoc = -1.0;
        float minumumTemperature = 40;
        float maximumTemperature = 100;
        WHEN("sendSensorData() is called with input array") {
            bool expectedOutput = false;
            bool outputFromFunction = sendSensorData(minimumSoc, maximumSoc, minumumTemperature, maximumTemperature, *printToConsole);
            THEN("output in given format is generated and send to console") {
                REQUIRE(outputFromFunction == expectedOutput);
            }
        }
    }
}
