# Searching Algorithms Implementation

Algorithm | Link
------------ | -------------
Binary Search | [link!](https://github.com/dhrubajyoti89/AlgoCode/blob/dhrubajyoti89-searchalgo/C%20-%20C%2B%2B/Searching-Algorithms/binarysearch.cpp)
Linear Search | [link!](https://github.com/dhrubajyoti89/AlgoCode/blob/dhrubajyoti89-searchalgo/C%20-%20C%2B%2B/Searching-Algorithms/linearsearch.cpp)
Ternary Search | [link!](./ternary.cpp)
## 1. Binary Search

Binary search is another searching algorithm in C++. It is also known as half interval search algorithm. It is efficient and fast searching algorithm. If we want to search any element in the list then the only condition required is that the elements in the list must be in sorted order. It works by repeatedly dividing in half the portion of the list that could contain the item, until you’ve narrowed down the possible locations to just one.

## Algorithm for Binary Search:

```
while(low<=high)
      mid=(low+high)/2;
if(a[mid]<search_element)
      low=mid+1;
else if(a[mid]>search_element)
      high=mid-1;
If found return index
      Else return -1
```

## Advantages of binary searching technique

- Works faster then linear search.
- It is a simple algorithm.


Cases | Time Complexity | Space Complexity
------------ | ------------ | -------------
Best Case | O(1) | O(1)
Worst Case | O(log n) | O(log(n+1))
