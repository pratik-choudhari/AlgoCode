n = int(input("Enter a natural number: "))
lesser_n = n%60
lesser_nplus = (n+1)%60

def fibSumSq(n):
    i, j = 0, 1

    for _ in range(2,n+1):
        s= i + j
        s=s%10
        j, i = s, j
    return s

if lesser_n <= 1:
    i = lesser_n
else:
    i = fibSumSq(lesser_n)
if lesser_nplus <= 1:
    j = lesser_nplus
else:
    j = fibSumSq(lesser_nplus)

print((i * j) % 10)