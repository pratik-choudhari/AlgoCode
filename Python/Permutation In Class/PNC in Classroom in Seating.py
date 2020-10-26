def fact(a,b):
    s=a
    for i in range(a,b):
        s*=i+1
    return (s)
n=int(input("Enter the num of people: "))
m=int(input("Enter the number of seats available: "))
print(fact(m,n))
