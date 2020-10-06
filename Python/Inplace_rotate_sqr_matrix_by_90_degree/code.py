import numpy as np
# An Inplace function to rotate
# N x N matrix by 90 degrees in
# anti-clockwise direction


def rotateMatrix(mat, N):

    # Consider all squares one by one
    for x in range(0, int(N / 2)):

        # Consider elements in group
        # of 4 in current square
        for y in range(x, N-x-1):

            # store current cell in temp variable
            temp = mat[x][y]

            # move values from right to top
            mat[x][y] = mat[y][N-1-x]

            # move values from bottom to right
            mat[y][N-1-x] = mat[N-1-x][N-1-y]

            # move values from left to bottom
            mat[N-1-x][N-1-y] = mat[N-1-y][x]

            # assign temp to left
            mat[N-1-y][x] = temp


# Function to print the matrix
def displayMatrix(mat):

    for i in range(0, N):

        for j in range(0, N):

            print(mat[i][j], end=' ')
        print("")


# Driver Code
print("please enter the dimention of your square matrix: ")
N = int(input())
print("Please type the number of the choice you want: ")
print("1) Test the code for a random input")
print("2) Test the code for personal input")
choice = int(input())

if choice == 1:
    print("The matrix is: ")
    mat = np.random.randint(N*2, size=(N, N))
    for i in range(0, N):
        for j in range(0, N):
            print(mat[i][j], end=' ')
        print("")


else:
    print("Please enter your matrix values: ")
    mat = []
    # Taking input matrix
    for i in range(N):
        row = []
        for j in range(N):
            col = int(input())
            row.append(col)
        mat.append(row)
    # Printing the input matrix
    print("The matrix is: ")
    for i in range(0, N):
        for j in range(0, N):
            print(mat[i][j], end=' ')
        print("")

# Calling function to rotate the matrix
rotateMatrix(mat, N)
print("The rotated matrix is: ")
# Print rotated matrix
displayMatrix(mat)
