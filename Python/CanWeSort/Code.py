# Function for finding if it possible
# to obtain sorted array or not
def fun(arr, n, k):
 
    v = []
 
    # Iterate over all elements until K
    for i in range(k):
         
        # Store elements as multiples of K
        for j in range(i, n, k):
            v.append(arr[j]);
 
        # Sort the elements
        v.sort();
 
        x = 0
 
        # Put elements in their required position
        for j in range(i, n, k):
            arr[j] = v[x];
            x += 1
 
        v = []
 
    # Check if the array becomes sorted or not
    for i in range(n - 1):
        if (arr[i] > arr[i + 1]):
            return False
    return True
 
# Driver code
nk= input().split()
K = int(nk[1])
n = int(nk[0])
arr= list(map(int,input().split())) 

 
if (fun(arr, n, K)):
    print("True")
else:
    print("False")