 
def Charlie_PF(N): 

	if (N < 2): 
		return 0; 

	arr = [True] * (N + 1); 
	prod = 1; 
	res = 0; 
	p = 2; 
	while (p * p <= N): 
		
		# If p is prime 
		if (arr[p] == True): 
			for i in range(p * 2, N + 1, p): 
				arr[i] = False; 

		
			prod *= p; 
			if (prod > N): 
				return res; 
			res += 1; 
		p += 1; 

	return res; 

 
N = input(); 
print(Charlie_PF(N));
