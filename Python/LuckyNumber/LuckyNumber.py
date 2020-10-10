n=int(input("Input a Number: "))
List=range(-1,n*n+9,2)
i=2
while List[i:]:List=sorted(set(List)-set(List[List[i]::List[i]]));i+=1
print(List[1:n+1])