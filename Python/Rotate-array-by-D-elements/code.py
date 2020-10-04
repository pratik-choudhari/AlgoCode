def rotateByd(lst):
    lst[0:d] = reversed(lst[0:d])
    lst[d: ] = reversed(lst[d: ])
    lst.reverse()
    print(lst)


print("enter the array of numbers:", end=" ")
lst = [int(i) for i in input().split()]
print()
print("enter the value of d:", end=" ")
d = int(input())
rotateByd(lst)
