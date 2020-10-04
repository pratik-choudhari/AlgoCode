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

#In this algo we first reversed the elements upto index D (excluded)
#then we reversed the elements from Dth index to the end
#finally we reversed the entire array
#doing so, our array gets reversed by D elements clockwise
