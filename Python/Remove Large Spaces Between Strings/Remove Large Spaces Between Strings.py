a=list(input())
s=""
for i in range(len(a)):
    if a[i]==" " and a[i-1]==" ":
        pass
    elif a[i]==" " and a[i-1]!=" ":
        s+=a[i]
    else:
        s+=a[i]
print(s)
