x = int(input())
for n in range(1,x):
    sum = 0
    i=1
    while i<n:
        if n%i==0:
            sum = sum + i
        i = i + 1
    if sum==n:
        print(n, end = " ")

