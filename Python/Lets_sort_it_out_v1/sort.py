def getInput():
    alg = input('Type of sort (selection, insertion, bubble): ').strip().lower()  # get algorithm type
    numStr = input('Enter numbers on single line separated by spaces: ')  # get list of numbers to sort
    numArr = numStr.strip().split(" ")  # split number string into array (strings)
    nums = [x for x in map(lambda num: int(num), numArr)]   # convert to integers
    return (alg, nums)

def bubbleSort(nums):
    numEls = len(nums)  # declare separate variable since will be modifying actual array in loop
    sortedArr = sorted(nums)  # correct sorting to compare to for checking if done
    while(nums != sortedArr):  # if not sorted yet, keep sorting
        for i in range(numEls - 1):  # subtract 1 since only need to loop to second-to-last element because will check the one to the right
            if(nums[i] > nums[i + 1]):  # need to switch
                nums[i], nums[i + 1] = nums[i + 1], nums[i]
    return nums

def insertionSort(nums):
    numEls = len(nums)  # declare separate variable since will be modifying actual array in loop
    for i in range(1, numEls):
        j = i
        while(j > 0 and nums[j - 1] > nums[j]):  # swap until num in correct place
            nums[j - 1], nums[j] = nums[j], nums[j - 1]
            j -= 1
    return nums

def selectionSort(nums):
    numEls = len(nums)  # declare separate variable since will be modifying actual array in loop
    for i in range(numEls - 1):
        minNum = i  # min number seen so far
        j = i + 1
        while j < numEls:  # see if can find a smaller number
            if(nums[j] < nums[minNum]):  # found new min number
                minNum = j
            j += 1
        if(minNum != i):
            nums[i], nums[minNum] = nums[minNum], nums[i]  # swap
    return nums

def run():
    alg, nums = getInput()
    res = ''
    if(alg =="bubble"):
        res = bubbleSort(nums)
    elif(alg == "insertion"):
        res =  insertionSort(nums)
    elif(alg == "selection"):
        res = selectionSort(nums)
    else:
        res = "Invalid algorithm type"
    print(res)

if __name__ == "__main__":
    run()