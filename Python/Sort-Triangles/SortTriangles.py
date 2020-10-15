import math

# method to ask the 1st question of how many triangles we will be working with
def num_of_triangles():
    triangles = input('How many triangles will be sorted?(Please enter a int value)')

    # checks if the the input is a int, and if not keeps asking the same questions till a int is provided
    while triangles.isdigit() is False:
        print('That is a invalid entry, please try again')
        triangles = input('How many triangles will be sorted?(Please enter a int value)')

    return int(triangles)

# method to ask the user for the sides of a triangle
def side_of_triangles(triname):

    # cleans up the console messages
    print('\n')

    side_1 = input (f'For {triname}, please enter the number for side 1 (Please enter a int value):')

    # checks if the the input is a int, and if not keeps asking the same questions till a int is provided
    while side_1.isdigit() is False:
        print('That is a invalid entry, please try again')
        side_1 = input(f'For {triname}, pPlease enter the number for side 1 (Please enter a int value):')

    side_2 = input(f'For {triname}, please enter the number for side 2 (Please enter a int value):')

    # checks if the the input is a int, and if not keeps asking the same questions till a int is provided
    while side_2.isdigit() is False:
        print('That is a invalid entry, please try again')
        side_2 = input(f'For {triname}, please enter the number for side 2 (Please enter a int value):')

    side_3 = input(f'For {triname}, please enter the number for side 3 (Please enter a int value):')

    # checks if the the input is a int, and if not keeps asking the same questions till a int is provided
    while side_3.isdigit() is False:
        print('That is a invalid entry, please try again')
        side_3 = input(f'For {triname}, please enter the number for side 3 (Please enter a int value):')


    # puts the sides into a list to be returned
    sides = [int(side_1), int(side_2), int(side_3)]

    return sides

# simple method to calculate the area of the 3 sides provided
def calcArea(sides):

    # print(f'side1: {sides[0]} side2: {sides[1]} side3: {sides[2]}')
    s = (sides[0] + sides[1] + sides[2])/2
    # print(f's is {s}')
    area = math.sqrt(s*(s - sides[0])*(s - sides[1])*(s - sides[2]))
    # print(f'area is {area}')
    return area

# method to take the triangle dictionary and order them based on their calculated area
def triOrderList(tris):
    triKeys = list(tris.keys())

    # double loop that takes one area to compare to another in the list
    running = True
    i = 0
    while running:
        key = triKeys[i]
        # print(f'triKeys in position {i} is {key}')

        # breaks the loop
        tri_len = len(triKeys) - 1
        # print(f'i is {i} and tri_len is {tri_len}')
        if i == tri_len:
            break

        for compare in triKeys[i + 1:]:
            # print(f'comparing {key} to {compare}')
            # if one is found to be greater than the other it is then switched
            if key > compare:
                # print('making the switch')
                compareIndex = triKeys.index(compare)

                triKeys[i], triKeys[compareIndex] = triKeys[compareIndex], triKeys[i]

                # resets the list to make sure nothing is missed in the comparision
                i = -1
                break

        i += 1
        # print(f'List is now {triKeys}')

    # returns the keys in a ordered list
    return triKeys

# where the code starts by asking the user how many triangles and for their sides
print('Welcome! to SortTriangles python code')
triangleQuantity = num_of_triangles()

count = 0
triangles = {}

# loops to assign sides to a key which is going to be it's area (of all 3 sides)
while count < triangleQuantity:

    triName = f'triangle{count + 1}'
    triSides = side_of_triangles(triName)

    area = calcArea(triSides)
    triangles.update({area:triSides})

    # print(f'triangles dict {triangles}')
    count += 1

# after the sides of a triangles are set in the dictionary, this next part will be to compare them and order them
tri_ordered_list = triOrderList(triangles)

print('\nOrdered list of sides are:')
for keys in tri_ordered_list:
    print(f'{triangles[keys]} ')
