  
def Pascal(n):  
  
    for l in range(1, n + 1):  
        x = 1; 
        for i in range(1, l + 1):  
              
            
            print(x, end = " ");  
            x = int(x * (l - i) / i);  
        print("");  
n=int(input())
print (Pascal(n))