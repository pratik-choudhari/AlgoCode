
#N QUEEN PROBLEM 

-This problem is to find an arrangement of N queens on a chess board, such that no queen can attack any other queens on the board.

-The chess queens can attack in any direction as horizontal, vertical, horizontal and diagonal way.

-A binary matrix is used to display the positions of N Queens, where no queens can attack other queens.

-Concept of BACKTRACKING is used to solve this problem.

##BACKTRACKING ALGORITHM 

The idea is to place queens one by one in different columns, starting from the leftmost column. When we place a queen in a column, we check for clashes with already placed queens. In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. If we do not find such a row due to clashes then we backtrack and return false.

1) Start in the leftmost column

2) If all queens are placed
    return true

3) Try all rows in the current column. 
   Do following for every tried row.
    a) If the queen can be placed safely in this row 
       then mark this [row, column] as part of the 
       solution and recursively check if placing
       queen here leads to a solution.
    b) If placing the queen in [row, column] leads to
       a solution then return true.
    c) If placing queen doesn't lead to a solution then
       unmark this [row, column](Backtrack) and go to 
       step (a) to try other rows.

4) If all rows have been tried and nothing worked,
   return false to trigger backtracking.

I have applied backtracking with optimization approach wherein the idea is not to check every element in right and left diagonal instead use property of diagonals:

1.The sum of i and j is constant and unique for each right diagonal where i is the row of element and j is the
column of element.
2.The difference of i and j is constant and unique for each left diagonal where i and j are row and column of element respectively.


-This solution is contributed by * ![Pavleen Kaur](https://github.com/pavleen14)
