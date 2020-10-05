def valid(bo, num, pos):
    for i in range(len(bo[0])):
        if bo[pos[0]][i] == num and pos[1] != i:
            return False

    for i in range(len(bo)):
        if bo[i][pos[1]] == num and pos[0] != i:
            return False

    box_x = pos[1] // 3
    box_y = pos[0] // 3

    for i in range(box_y*3, box_y*3 + 3):
        for j in range(box_x * 3, box_x*3 + 3):
            if bo[i][j] == num and (i,j) != pos:
                return False

    return True 

def solve(bo,pos): 
    if(pos == 81):
        return True 
    row = pos // 9
    col = pos %  9 
    if(bo[row][col] != 0) : 
        return solve(bo,pos+1) 
    else : 
        for i in range(1,10) : 
            if(valid(bo, i, (row,col))) : 
                bo[row][col] = i; 
                if(solve(bo,pos+1)) : 
                    return True
                bo[row][col] = 0 

        return False


def print_board(bo):
    for i in range(len(bo)):
        if i % 3 == 0 and i != 0:
            print("- - - - - - - - - - - - - ")

        for j in range(len(bo[0])):
            if j % 3 == 0 and j != 0:
                print(" | ", end="")

            if j == 8:
                print(bo[i][j])
            else:
                print(str(bo[i][j]) + " ", end="")


board = [] 
print("All empty cells of the board should be entered as 0 \n")
for i in range(9): 
    row = list(map(int,input("\nEnter Row "+str(i+1)+" : ").strip().split()))[:9]
    board.append(row)
print("\n")
ans = solve(board,0)
if ans == False : 
    print("Sorry !! Invalid Sudoku board. ")
else :
    print("The solved Sudoku board is : \n")
    print_board(board)