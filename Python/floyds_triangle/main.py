def main():
    while True:
        try:
            rows = int(input("> Please Enter number of rows: "))
        except:
            continue
        break
    
    number = 1
    for i in range(rows):
        for j in range(i + 1):
            print(number, end=" ")
            number += 1
        print("")
    pass

if __name__ == "__main__":
    main()