# Problem Statement
You are given an N x N grid in which each cell is either free to pass through represented by 1 or is blocked represented by 0. You find the number of ways (modulo 10^9 + 7), to reach from the top-most left cell to the bottom-most right cell of the grid, provided that in each move you could either move 1 step down or 1 step to the right. 

### Samaple Input 1
N = 4
Grid -
1 1 1 1
1 1 0 1
0 1 0 1
1 1 1 1

### Sample Output 1
3

### Explanation
The first path starting from (0, 0) could be: Right -> Right -> Right -> Down -> Down -> Down
The second path could be: Right -> Down -> Down -> Down -> Right -> Right
The third path could be:  Down -> Right -> Down -> Down -> Right -> Right

##### Contributed by 
[Ankit Pandey](https://github.com/Ankitcode99)