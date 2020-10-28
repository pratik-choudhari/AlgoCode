#Taking Input
n,s,p,q=list(map(int,input().split(' ')))
a=[0]
#Asignning every element of array to 0.
for i in range(n-1):a.append(0)
# Applying pseudo code
a[0]=s%(2**31)
for i in range(1,n):
    a[i]=a[i-1]*p+q%(2**31)
#Sorting to remove common elements
a.sort()
print(len(a))
