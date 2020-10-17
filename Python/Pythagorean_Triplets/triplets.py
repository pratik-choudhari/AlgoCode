import math  


def get_triplet(arr, n): 
  for i in range(n): 
    arr[i] = arr[i] * arr[i] 
  arr.sort() 
  for i in range(n-1, 1, -1):
    b = 0
    c = i - 1
    while (b < c): 
      if (arr[b] + arr[c] == arr[i]): 
        print("Triplets are: ", math.sqrt(arr[b]),", ",math.sqrt(arr[c]),"and", math.sqrt(arr[i]))
        b+=1 
        c-=1
      else: 
        if (arr[b] + arr[c] < arr[i]): 
          b = b + 1
        else: 
          c = c - 1

arr = [3,4,6,5,7,8] 
n = len(arr) 
get_triplet(arr, n)
