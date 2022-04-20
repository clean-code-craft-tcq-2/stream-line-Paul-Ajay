import time
import sys

def senderStub():
    stubFile = open("dataReceived.txt","r")
    for readingLine in stubFile:
        sys.stdout.write(readingLine)
        time.sleep(0.01)

if __name__ == "__main__":
    time.sleep(3)
    senderStub()
