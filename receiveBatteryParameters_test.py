import unittest
import re
import math
from receiveBatteryParameters import calculateAverageOf, getSocTemperatureValues, printParameters, readStreamData, readingIsValid

formatTemperaturePattern = r"Temperature -  MovingAverage:[ \d\. ]+MinValue:[ \d\. ]+MaxValue:[ \d\. ]"
formatSocPattern = r"SoC -  MovingAverage:[ \d\. ]+MinValue:[ \d\. ]+MaxValue:[ \d\. ]"

class TypewiseTest(unittest.TestCase):
    def test_calculateAverageOf(self):
        epsilon = 0.001
        testList = [3,15,0,9.112,68.9]
        self.assertAlmostEqual(calculateAverageOf(testList),19.20,delta = epsilon)
        testList = [67.7,14,99.3,0.4,11.4]
        self.assertAlmostEqual(calculateAverageOf(testList),38.56,delta = epsilon)

    def test_getSocTemperatureValues(self):
        testStr = "0.97, 45.7"
        soc,temp = getSocTemperatureValues(testStr)
        self.assertEqual(0.97,soc)
        self.assertEqual(45.7,temp)
        testStr = ""
        soc,temp = getSocTemperatureValues(testStr)
        self.assertTrue(math.isnan(soc))
        self.assertTrue(math.isnan(temp))

    def test_readingIsValid(self):
        self.assertTrue(readingIsValid(3.34))
        self.assertFalse(readingIsValid(-1))
        self.assertFalse(readingIsValid(math.nan))

    def test_printParameters(self):
        self.assertTrue(re.match(formatTemperaturePattern,printParameters("Temperature",26.21,44.44,55.4)))
        self.assertTrue(re.match(formatSocPattern,printParameters("SoC",0.85,1,00.1)))


if __name__ == "__main__":
    unittest.main()