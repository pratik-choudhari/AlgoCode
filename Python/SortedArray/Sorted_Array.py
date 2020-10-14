N = int(input())
A = list(map(int, input().split()))
Mid = N//2
A1 = A[:Mid]
A2 = A[Mid:]
A1.sort()
A2.sort(reverse = True)
for v in A1:
	print(v, end=" ")
for v in A2:
	print(v, end=" ")
