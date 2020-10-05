
## Problem statement:

Given an array of N elements and the task is to print the elements of an array after left rotating array elements by d positions.

```
    Input:
    n = 7, d = 2
    array elements: 1 2 3 4 5 6 7

    Output: 
    3 4 5 6 7 1 2
```

The naive approach to solve this problem is to shift the all elements d times but this is a time-consuming process.

Optimised approach:

```
    Let
    i = ith iteration
    D = number of elements to rotate
    N = size of array
    Then to left rotate array we can use -
    arr[i] = arr[(i+D)%N]
```

[Click here to see the implementation!](./array-rotate.cpp)

Contributed by [Dhrubajyoti Chakraborty](https://www.github.com/dhrubajyoti89)
