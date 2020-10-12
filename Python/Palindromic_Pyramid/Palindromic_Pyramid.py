# Python program for Palindrome pyramid pattern printing using numbers
n = int(input("Enter the number of rows : "))
for i in range(1,n+1, +1):
    for j in range(1,i+1 ,+1):
        print(j , end=" ");
    for h in range((i-1),0,-1):
        print(h, end = " ")
    print(end = "\n")
    
"""Ouput:
Enter the number of rows : 8
1 
1 2 1 
1 2 3 2 1 
1 2 3 4 3 2 1 
1 2 3 4 5 4 3 2 1 
1 2 3 4 5 6 5 4 3 2 1 
1 2 3 4 5 6 7 6 5 4 3 2 1 
1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 
"""
