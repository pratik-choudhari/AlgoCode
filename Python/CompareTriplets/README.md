# Description

Give rating of two People- Person A and Person B as triplet a = (a[0], a[1], a[2]) for A, and b = (b[0], b[1], b[2]) for B.
The task is to find their comparison points by comparing a[0] with b[0], a[1] with b[1], and a[2] with b[2].
If a[i] > b[i], then A is awarded 1 point.
If a[i] < b[i], then B is awarded 1 point.
If a[i] = b[i], then neither A nor B receives a point.
Given a and b, determine their respective comparison points.
# Input

The first line contains 3 space-separated integers, a[0], a[1], and a[2], the respective values in triplet a.
The second line contains 3 space-separated integers, b[0], b[1], and b[2], the respective values in triplet b.

# Example

```
a = 1 2 3
b = 3 2 1
```

For elements 0, Person B is awarded a point because a[0] .
For the equal elements a[1] and b[1], no points are earned.
Finally, for elements 2, a[2] > b[2] so Person A receives a point.
The returned array is [1, 1] with Person A’s score first and Person B's second.

### _Contribiutor_

[Daniel Martínez](https://github.com/KompuDan)

