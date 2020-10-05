import math
print("What type to Calculation you want to do: 1. Basic Arithmetic\n\t\t\t\t\t\t\t\t\t\t 2. Trigonometric\n\t\t\t\t\t\t\t\t\t\t 3. Exit -->")
n = int(input())
if n == 1:
    print("Select one: 1. Sum\n\t\t\t2. Difference\n\t\t\t3. Multiplication\n\t\t\t4. Division\n\t\t\t5. Exit -->")
    n1 = int(input())
    if n1 == 1:
        number_1 = int(input("Enter the number 1: "))
        number_2 = int(input("Enter the number 2: "))
        print("The Sum of Numbers: ",number_1 + number_2)
    elif n1 == 2:
        number_1 = int(input("Enter the number 1: "))
        number_2 = int(input("Enter the number 2: "))
        print("The Diffference of Numbers: ", number_1 - number_2)
    elif n1 == 3:
        number_1 = int(input("Enter the number 1: "))
        number_2 = int(input("Enter the number 2: "))
        print("The Multiplication of Numbers: ", number_1 * number_2)
    elif n1 == 4:
        number_1 = int(input("Enter the number 1: "))
        number_2 = int(input("Enter the number 2: "))
        print("The Division of Numbers: ", number_1 / number_2)
    elif n1 == 5:
        print("Thanks for using",exit())
elif n == 2:
    print("Enter the Trigonometric function\n sin,cos,tan,sec,cosec,cot")
    trigo = input()
    angle = int(input("Enter the value of the angle"))
    if trigo in ["sin","cosec"]:
        sin = math.sin(angle)
        if trigo == "sin":
            print(f"sin({angle}) = {sin}")
        else:
            cosec = 1/sin
            print(f"cosec({angle}) = {cosec}")
    elif trigo in ["cos","sec"]:
        cos = math.cos(angle)
        if trigo == "cos":
            print(f"cos({angle}) = {cos}")
        else:
            sec = 1/cos
            print(f"sec({angle}) = {sec}")
    elif trigo in ["tan","cot"]:
        tan = math.tan(angle)
        if trigo == "tan":
            print(f"tan({angle}) = {tan}")
        else:
            cot = 1/tan
            print(f"cot({angle}) = {cot}")

else:
    exit()
