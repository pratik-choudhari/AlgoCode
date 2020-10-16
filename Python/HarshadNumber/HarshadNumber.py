def checkHarshad(n): 
    sum = 0
    temp = n 
    while temp > 0 : 
        sum = sum + temp % 10
        temp = temp // 10
    return n % sum == 0

N = int(input())
print(N, end=" ")
if checkHarshad(N):
	print("is Harshad")
else:   
	print("is Not Harshad")