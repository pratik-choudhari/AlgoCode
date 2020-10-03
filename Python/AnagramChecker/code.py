#Function to check whether two string are anagram or not
def checker(string1,string2):
	if sorted(string1)==sorted(string2):
		print("Yes")
	else:
		print("No")
		
		
#Driver Function		
if __name__=='__main__':
	string1=input("Input first string")			#Input first string from user
	string2=input("Input second string")		#Input second string from user
	checker(string1,string2)					#calling the 'checker' function
	
