choice = 0
while(choice!=13):
    print("MENU\n")
    print("1.Decimal to Binary\n2.Decimal to Hexadecimal\n3.Decimal to octal \n4.Binary to Decimal \n5.Binary to Hexadecimal \n6.Binary to octal\n7.Hexadecimal to Decimal \n8.Hexadecimal to Binary \n9.Hexadecimal to Octal \n10.Octal to Decimal \n11.Octal to Binary \n12.Octal to Hexadecimal \n13.Exit\n")
    choice = int(input("Enter your choice:\n"))
    if choice==1:
        n = int(input("Enter a decimal number: "))
        print("The Decimal number is: ", bin(n))
    elif choice == 2:
        n = int(input("Enter a decimal number: "))
        print("The Hexadecimal number is: ", hex(n))
    elif choice == 3:
        n = int(input("Enter a decimal number: "))
        print("The Octal number is: ", oct(n))
    elif choice == 4:
        n = str(input("Enter a binary number: "))
        print("The Decimal number is: ", int(n,2))
    elif choice == 5:
        n = str(input("Enter a binary number: "))
        print("The Hexadecimal number is: ", hex(int(n,2)))
    elif choice == 6:
        n = str(input("Enter a binary number: "))
        print("The Octal number is: ", oct(int(n,2)))
    elif choice == 7:
        n = str(input("Enter a hexadecimal number: "))
        print("The Decimal number is: ", int(n,16))
    elif choice == 8:
        n = str(input("Enter a Hexadecimal number: "))
        print("The Binary number is: ", bin(int(n,16)))
    elif choice == 9:
        n = str(input("Enter a Hexadecimal number: "))
        print("The Octal number is: ", oct(int(n,16)))
    elif choice == 10:
        n = str(input("Enter a Octal number: "))
        print("The Decimal number is: ", int(n,8))
    elif choice == 11:
        n = str(input("Enter a Octal number: "))
        print("The Binary number is: ", bin(int(n,8)))
    elif choice == 12:
        n = str(input("Enter a Octal number: "))
        print("The Hexaecimal number is: ", hex(int(n,8)))
    else:
        exit
    print()