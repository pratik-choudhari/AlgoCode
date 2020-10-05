# fnumber is a function that checks if number entered is float or not.


def fnumber():
    number = input("Enter Number To Check: ")
    # number is a variable that contains user input
    try:
        check = float(number)
        # float() is a type conversion for float
        print(number + " Is A Floating Number")
    except ValueError:
        # Not A floating number
        print(number + " Is Not A Floating Number")


fnumber()
