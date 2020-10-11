#Function to check if Array can be split so LHS and RHS sum are equal
def canBalanceArray(inputArray) :
    canBalance = False
    length = len(inputArray)
    leftSum = 0
    #find total sum from left
    for i in range(0, length) :
        leftSum += inputArray[i]
    #traverse from right and check for equality
    rightSum = 0
    for i in range(length-1, -1, -1) :
        rightSum += inputArray[i]
        leftSum -= inputArray[i]
   
        if (rightSum == leftSum) :
            canBalance = True

    return canBalance

#Input method
if __name__=='__main__':
    #Input array from user
    inputArray = []
    length = int(input("Enter number of elements in array : "))
    print("Enter each element and press enter : ")
    try:
        for count in range(0, length):
            inputArray.append(int(input()))
    except:
        print("Please enter a number")
    #calling the 'canBalanceArray' function
    print(canBalanceArray(inputArray))

