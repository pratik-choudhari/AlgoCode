# Problem Statement
We are given an array of n points in the plane, and the problem is to find out the closest pair of points in the array. 
For example, in air-traffic control, you may want to monitor planes that come too close together, since this may indicate a possible collision
Divide and Conquer approach is used for the solution .

### Time Complexity
T(n) = 2T(n/2) + O(n) + O(n) + O(n)
T(n) = 2T(n/2) + O(n)
T(n) = T(nLogn)

### Samaple Input 
{{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}

### Sample Output 
The smallest distance is 1.41421

##### Contributed by 
[Nishit Khaitan](https://github.com/Nishitk-20)
