# A possible solution
import itertools 
n, k = list(map(int, input("enter range and size: ").split()))

def findsubsets(s, n): 
    return list(itertools.combinations(s, n)) 

s = set(list(range(1, n+1)))
for elm in findsubsets(s, k):
    print(elm)
