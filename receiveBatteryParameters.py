import sys
from threading import Thread
import time
import math

noOfReadings = 50

def readStreamData(noOfReadings):
    readingsSocList = []
    readingsTemperatureList = []
    readingNumber = 0
    for readingNumber in range(noOfReadings):
        currentReading = sys.stdin.readline()
        soc,temperature = getSocTemperatureValues(currentReading)
        if(readingIsValid(soc) and readingIsValid(temperature)):
            readingsSocList.append(soc)
            readingsTemperatureList.append(temperature)
            printParameters("SoC",calculateAverageOf(readingsSocList[-5:]),min(readingsSocList),max(readingsSocList))
            printParameters("Temperature",calculateAverageOf(readingsTemperatureList[-5:]),min(readingsTemperatureList),max(readingsTemperatureList))
    return(readingNumber+1)

def printParameters(parameterType,movingAvg,minVal,maxVal):
    stringToPrint = "{parameterType} -  MovingAverage: {movingAvg} MinValue: {minVal} MaxValue: {maxVal}".format(parameterType = parameterType, movingAvg = movingAvg,minVal = minVal,maxVal = maxVal)
    print(stringToPrint)
    return(stringToPrint)

def calculateAverageOf(inputList):
    return(round(sum(inputList)/len(inputList),2))

def getSocTemperatureValues(currentReading):
    if(len(list(currentReading.split(",")))>1):
        Soc = float(currentReading.split(",")[0].strip())
        temperature = float(currentReading.split(",")[1].strip())
        #print(Soc,temperature)
        return(Soc,temperature)
    else:
        return(math.nan,math.nan)

def readingIsValid(reading):
    if(reading!=math.nan and reading>=0):
        return(True)
    else:
        return(False)

if __name__ == "__main__":
    readStreamData(50)

