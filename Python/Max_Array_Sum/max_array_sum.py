def find_max_sum(arr): 
    incl = 0
    excl = 0
     
    for i in arr: 
          
        # Current max excluding i
        new_excl = excl if excl>incl else incl 
         
        # Current max including i 
        incl = excl + i 
        excl = new_excl 
      
    # return max of incl and excl 
    return (excl if excl>incl else incl) 
  
# Driver program to test above function
l=int(input())
a =[int(x) for x in input().split()]  
print (find_max_sum(a)) def find_max_sum(arr): 
    incl = 0
    excl = 0
     
    for i in arr: 
          
        # Current max excluding i
        new_excl = excl if excl>incl else incl 
         
        # Current max including i 
        incl = excl + i 
        excl = new_excl 
      
    # return max of incl and excl 
    return (excl if excl>incl else incl) 
  
# Driver program to test above function
l=int(input())
a =[int(x) for x in input().split()]  
print (find_max_sum(a)) 
