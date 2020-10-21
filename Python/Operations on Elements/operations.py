n=int(input())
a=input()

#split is inbuilt method which splits the list from whitespaces
a=a.split()

#initializing requirements
even=[]
odd=[]
s=0
afinal=[]
count=[]
wr=[]
r=[]
arr=[]

for i in range(n):
    #by deafult split method returns a list with all string elments
    k=int(a[i])

    #to get sum of all elements
    afinal.append(k)
    s=s+k

    #getiing odd and even elememts
    if k % 2== 0:
       even.append(k)
    else:
        odd.append(k)

#getting largest and smallest element
max=max(afinal)
min=min(afinal)

#to get repeated elemnts and frequency of each elements
while len(afinal)>0:
    e=afinal[0]
    n= afinal.count(e)
    arr.append(e)
    count.append(n)
    if n>1:
        r.append(e)
    else:
        wr.append(e)
    k=0
    for k in range(n):
        afinal.remove(e)



#print answers
print( "Smallest number:" + str(min))
print( "Largest number:"+ str(max))
print( "Sum of elements:" +str(s))
print("Frequency of elements:")
for i in range(len(arr)):
    print(str(arr[i])+"-"+str(count[i]))

print("Count of distinct elements: "+str(len(wr)))
print("Count of repeating elements: "+str(len(r)))
print( "Count of even elements: "+ str(len(even)))
print( "Count of odd elements:"+ str(len(odd))