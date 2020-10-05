# Searching Algorithms Implementation

Algorithm | Link
------------ | -------------
Binary Search | [link!](https://github.com/dhrubajyoti89/AlgoCode/blob/dhrubajyoti89-searchalgo/C%20-%20C%2B%2B/Searching-Algorithms/binarysearch.cpp)
Linear Search | [link!](https://github.com/dhrubajyoti89/AlgoCode/blob/dhrubajyoti89-searchalgo/C%20-%20C%2B%2B/Searching-Algorithms/linearsearch.cpp)
Ternary Search | [link!](./ternary.cpp)
Median Search | [link!](./mediansearch.cpp)
Fibonacci Search | [link!](./fibonacci.cpp)


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

## 2. Linear Search

Linear search is a very basic and simple search algorithm. In Linear search, we search an element or value in a given array by traversing the array from the starting, till the desired element or value is found.

## Algorithm for Linear Search:

```
LinearSearch(array, key)
  for each item in the array
    if item == value
      return its index
```

## Advantages of linear searching technique

- Linear search is the simplest searching algorithm that searches for an element in a list in sequential order.
- It is a simple algorithm.


Cases | Time Complexity | Space Complexity
------------ | ------------ | -------------
Best Case | O(n) | O(1)
Worst Case | O(n) | O(1)

## 3. Ternary Search

Like the binary search, it also separates the lists into sub-lists. This procedure divides the list into three parts using two intermediate mid values.

## Algorithm for Ternary Search:

```
Begin
   if start <= end then
      midFirst := start + (end - start) /3
      midSecond := midFirst + (end - start) / 3
      if array[midFirst] = key then
         return midFirst
      if array[midSecond] = key then
         return midSecond
      if key < array[midFirst] then
         call ternarySearch(array, start, midFirst-1, key)
      if key > array[midSecond] then
         call ternarySearch(array, midFirst+1, end, key)
      else
         call ternarySearch(array, midFirst+1, midSecond-1, key)
   else
      return invalid location
End
```

## Advantages of Ternary searching technique

- As the lists are divided into more subdivisions, so it reduces the time to search a key value.
- It is a simple algorithm.


Cases | Time Complexity | Space Complexity
------------ | ------------ | -------------
Best Case | O(log3 n) | O(1)
Worst Case | O(log3 n) | O(1)


## 4. Median Search

Median is the middle value of a set of data. To determine the median value in a sequence of numbers, the numbers must first be arranged in ascending order.

## Algorithm for Median Search:

```
findMedian 
{ 
    sort(start, start + n); 
    if (n % 2 != 0) 
        return (double)start[n / 2]; 
    return (double)(start[(n - 1) / 2] + start[n / 2]) / 2.0;
    }
```

## Advantages of median searching technique

- Works faster then linear search.
- It is a simple algorithm.


Cases | Time Complexity | Space Complexity
------------ | ------------ | -------------
Best Case | O(nlogn) | O(1)
Worst Case | O(nlogn) | O(1)


## 5. Fibonacci Search

Fibonacci Search is a comparison-based technique that uses Fibonacci numbers to search an element in a sorted array.

## Algorithm for Binary Search:

```
 while (fib < n) 
 {
 }
 off=-1
 while(off>1){
 if(array<off){
 }
 elseif(array>off){
 }
 off=last
 
  ```

## Advantages of binary searching technique

- Works faster then linear search.
- It is a simple algorithm.


Cases | Time Complexity | Space Complexity
------------ | ------------ | -------------
Best Case | O(log N) | O(1)
Worst Case | O(log N) | O(1)
