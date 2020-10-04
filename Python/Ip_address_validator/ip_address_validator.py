import re 

regex = '''^(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\.( 
            25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\.( 
            25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\.( 
            25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)$'''
      

def check(Ip):  
    if(re.search(regex, Ip)):  
        return True      
    else:
        return False
      
  
# Driver Code  
if __name__ == '__main__' : 
    

    Ip = input("Enter an IP Address to check its validity : ")
    if (check(Ip)):
        print("Valid IP Address")
    else:
        print("Invalid IP Address")
  
    
  
   