# 1.String Length
# 2..Check if the string is Palindrome
# 3.Count number of vowels
# 4.Remove Vowels from the string
# 5.Replace substring in a string
# 6.Capitalize the first and last character of each word in the string
# 7.Count the sum of numbers in a string
# 8.Concatenate with another input string


# 1. Performing String Length
String = "Hello Good Evening"

print(len(String))



# 2. String is Palindrome

String1 = "malayalam"

String2 = String1[::-1]


if String1 == String2:
	print("True")
else:
	print("False")


# 3. number of vowels

String3 = "ghanender"


string5 = []

vowels = ["a","e","i","o","u"]

y = vowels

a = 0
for y in vowels:
	for x in String3:
		if x == y:
			a= a+1

print(a)
# 4.remove vowels from string

string4 = "Honey"

vowels2 = ["a","e","i","o","u"]

def rem_vowel(string4):
	for x in string4: 
		if x in vowels2: 
			string4 = string4.replace(x, "") 

			print(string4) 

rem_vowel(string4) 


# 5. Replace Substring of a String

String = "Hello , Good Evening"

x1 = String.replace("Hello","Hii")

print(x1)


# 6.Captalise first and last character of each word in the string.

def capitalize_first_last_letters(str1):
	str1 = result = str1.title()
	result =  ""
	for word in str1.split():
		result += word[:-1] + word[-1].upper() + " "
	return result[:-1]  
     
print(capitalize_first_last_letters("hello good evening all"))

#7. Count Sum Of numbers in a string


str1 = "10b5c20sc"

def findSum(str1): 
  
    Empty = "" 
    Sum = 0

    for ch in str1:
        if (ch.isdigit()):
            Empty += ch 
        else:
            Sum += int(Empty)
            Empty = "0"

    return Sum + int(Empty) 
 
print(findSum(str1)) 


 # 8.Concanate with another input sring

Str11 = "fanta"

Str22 = "stic"

print(Str11 + Str22)