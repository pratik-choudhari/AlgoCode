import numpy as np
#Taking Input in Form of list and saving in a list
l=[0]
n=list(map(int,input().split(' ')))
l[0]=n
for i in range(len(n)-1):
    l.append(list(map(int,input().split(' '))))
l=np.array(l)
c=0
for i in range(len(n)):
    if (sum(l[:,i])==(len(n)-1)):
        c=i
        
if (sum(l[c])==0):
    print("id : "+str(c))
else:
    print("No Celebrity")
