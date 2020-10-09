### Problem Description

Given 3 integers A, B and N and an array of integars C of size N.

Element C[i] represents length of ith board.

You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.

Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.

### Sample Input
A = 2
B = 5
N = 2
C = [1, 10]

### Sample Output 1:
50

### Explanation :
Possibility 1:- same painter paints both blocks, time taken = 55units
Possibility 2:- Painter 1 paints block 1, painter 2 paints block 2, time take = max(5, 50) = 50
There are no other distinct ways to paint boards.
ans = 50%10000003


##### Contributed by 
[Aalok Chaudhary](https://github.com/aalokchaudhary)