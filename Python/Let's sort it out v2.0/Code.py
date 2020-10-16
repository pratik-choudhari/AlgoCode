# FUNCTION FOR MERGE SORT

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    middle = len(arr) // 2
    left_list = arr[:middle]
    right_list = arr[middle:]

    left_list = merge_sort(left_list)
    right_list = merge_sort(right_list)
    return list(merge(left_list, right_list))


def merge(left_half,right_half):
    res = []
    while len(left_half) != 0 and len(right_half) != 0:
        if left_half[0] < right_half[0]:
            res.append(left_half[0])
            left_half.remove(left_half[0])
        else:
            res.append(right_half[0])
            right_half.remove(right_half[0])
    if len(left_half) == 0:
        res = res + right_half
    else:
        res = res + left_half
    return res

# FUNCTION FOR SHELL SORT

def shellSort(arr):
    
    gap = len(arr) // 2
    while gap > 0:

        for i in range(gap, len(arr)):
            temp = arr[i]
            j = i

            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j = j-gap
            arr[j] = temp

        gap = gap//2

# FUNCTION FOR RADIX SORT 

def countingSort(arr, exp1): 
   
    n = len(arr) 
    output = [0] * (n) 
   
    count = [0] * (10) 
   
    for i in range(0, n): 
        index = (arr[i]/exp1) 
        count[int((index)%10)] += 1
   
    for i in range(1,10): 
        count[i] += count[i-1] 
    
    i = n-1
    while i>=0: 
        index = (arr[i]/exp1) 
        output[ count[ int((index)%10) ] - 1] = arr[i] 
        count[int((index)%10)] -= 1
        i -= 1
     
    i = 0
    for i in range(0,len(arr)): 
        arr[i] = output[i] 
 
def radixSort(arr):
 
    max1 = max(arr)
    exp = 1
    while max1/exp > 0:
        countingSort(arr,exp)
        exp *= 10


print("MENU FOR SORTING ALGORITHMS\n")
print("ENTER 1 FOR MERGE SORT")
print("ENTER 2 FOR SHELL SORT")
print("ENTER 3 FOR RADIX SORT\n")
ctr=int(input("ENTER YOUR CHOICE : "))

print()

size=int(input("Enter the size of the array : "))

arr = [0 for x in range(size)]


for i in range(size):
    b=int(input("Enter Number : "))
    arr[i]=b
    
print(arr)


if (ctr==1):
    
    print(merge_sort(arr))
    
elif(ctr==2):
    
    shellSort(arr)
    
    print(arr)

elif(ctr==3):

    radixSort(arr)
 
    print(arr)

else:
    print("WRONG CHOICE ENTERED!!")

    



