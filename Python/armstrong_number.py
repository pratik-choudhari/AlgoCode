# PYTHON program to find Armstrong  
# numbers in a range 
import math 
  
# Prints Armstrong Numbers in given range 
def findArmstrong(low, high) : 
      
    for i in range(low + 1, high) : 
          
        # number of digits calculation 
        x = i 
        n = 0
        while (x != 0) : 
            x = x / 10
            n = n + 1
              
        # compute sum of nth power of  
        pow_sum = 0 
        x = i 
        while (x != 0) : 
            digit = x % 10
            pow_sum = pow_sum + math.pow(digit, n) 
            x = x / 10
              
        # checks if number i is equal to 
        # the sum of nth power of its digits 
        if (pow_sum == i) : 
            print(str(i) + " "), 
  
# Driver code 
num1 = 0
num2 = int(input())
findArmstrong(num1, num2) 
print("")    
