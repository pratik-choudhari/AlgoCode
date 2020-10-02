import random
print("Here is a random number between 0 and 100000000000000000000: ")
def generateNumber():
    number = random.randint(0, 100000000000000000000)
    return number

print(generateNumber())
