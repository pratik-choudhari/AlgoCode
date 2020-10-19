# Problem Task
Give rating of two people - Person A and Person B as triplet a = (a[0], a[1], a[2]) for A, and b = (b[0], b[1], b[2]) for B.  
The task is to find their comparison points by comparing a[0] with b[0], a[1] with b[1], and a[2] with b[2].

If a[i] > b[i], then A is awarded 1 point.  
If a[i] < b[i], then B is awarded 1 point.  
If a[i] = b[i], then neither A nor B receives a point.  

Given a and b, determine their respective comparison points, returning it as an array of their scores respectively - [A, B]

# Input
The first line contains 3 space-separated integers, a[0], a[1], and a[2], the respective values in triplet a.  
The second line contains 3 space-separated integers, b[0], b[1], and b[2], the respective values in triplet b.

# Sample
## Input
```
A = [1, 2, 3]
B = [3, 2, 1]
```
## Output
```
[1, 1]
```
## Explanation
For element 0, Person B is awarded a point because b[0] > a[0].  
For element 1, no points are earned because a[1] = b[1].  
For element 2, Person A receives a point because a[2] > b[2].  
The returned array is [1, 1] with Person A’s score first and Person B's second.

<br>

**Contributor:** [sawzedong](github.com/sawzedong)