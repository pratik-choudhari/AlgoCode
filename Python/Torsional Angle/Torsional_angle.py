import numpy as np
import math
a=np.array(list(map(int,input().split(' '))))
b=np.array(list(map(int,input().split(' '))))
c=np.array(list(map(int,input().split(' '))))
d=np.array(list(map(int,input().split(' '))))
ab=b-a
bc=c-b
cd=d-c
x=np.cross(ab,bc)
y=np.cross(bc,cd)
p=np.dot(x,y)
normx=np.linalg.norm(x)
normy=np.linalg.norm(y)
i=p/(normx*normy)
print(round(math.degrees(math.acos(i)),2))
