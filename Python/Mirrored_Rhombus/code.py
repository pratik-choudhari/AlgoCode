#Function to print a rhombus based on number of rows
def printRhombus(height) :
    for row in range (0,height):
        # print the first row
        # print spaces and do not move to new line
        for i in range (0,height - row):
            print (end=" ")
        # print stars and do not move to new line
        for i in range (0,height):
            print ("*",end="")
        # go to next row
        print()

#Input method
if __name__=='__main__':
    height = int(input("Enter number rows : "))
    printRhombus(height)

