## Problem statement:

Given an array of N elements and the task is to print the elements of an array after left rotating array elements by d positions.

```
    Input:
    n = 6, d = 1
    array elements: "I", "am", "participating", "to", "hacktoberfest", "2020"
    Output: 
    "2020", "I", "am", "participating", "to", "hacktoberfest"
```

This is perhaps the simplest method to rotate an array. Using the method from Collections (java) class, gives the flexibility to rotate any type of non-primitive type arrays.

The first step is to convert into a list, using Arrays.asList() method, then we can pass this list to Collections.rotate() with the distance number (it can be either positive or negative)

The algorithm to rotate a primitive type of array, for example int[], is restricted to the type declared, this means that for an array of type String[] you need another method.

Using Collections.rotate() makes the code simpler, free from bugs since we're using Java standard libraries.

[Click here to see the implementation](./ArrayRotator.java)

Contributed by [Alessandro Arosio](https://github.com/AlessandroArosio)