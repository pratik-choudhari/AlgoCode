import sys

if len(sys.argv) > 2 or len(sys.argv) < 2:
    print("Enter atmost one command line argument.")
    exit()

number = int(sys.argv[1])

squareNumber = number ** 2

numberString = str(number)
squareNumberString = str(squareNumber)

validLength = len(numberString)
startIndex = len(squareNumberString) - len(numberString)

if numberString == squareNumberString[startIndex:]:
    print("Automorphic Number")
else:
    print("Not an automorphic number")

