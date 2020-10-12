# program to count number of
# non repeating digits in a number

# taking number input as a string
num = input("Enter the number: ")

# converting the string into list
num_list = list(num)

# creating a new list which will
# store the singly repeated numbers in
# the given  number

# this is a comman method that many programmers
# use to insert values in a list
unique = [i for i in num_list if num_list.count(i) == 1]

# printing the len of the above list which
# gives our required answer
print("Number of single digits in the given number:",len(unique))

# program by Jaya Ganesh Kumar