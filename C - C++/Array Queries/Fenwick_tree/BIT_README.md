#Binary Indexed Tree  
### Contributed by [Manan Shah](https://github.com/cs-mshah"cs-mshah")

This tree very efficiently calculates prefix sums and updates the array, both in **O(logn)** time.  

Here is how it is constructed:  
![BIT](BIT_diagram.jpg"source: hackerearth")  

- The BIT[i] stores the cumulative sum from index `i to i - (1<<r) + 1`, where r is the last set bit in i. (This can be seen by careful observation from the above diagram)
- the operation `x&-x` gives the last set bit in x. This can be very easily shown.  

#### Update operation to construct the BIT:  

`void update(int x, int val)
{
    for(; x <= n; x += x&-x)
    {
        BIT[x] += val;
    }
}`

- On updating an element in the array, it updates several BIT values as they are overlapping.  
- The values that need to be updated are given by the for loop. This can be seen again from the diagram of how we make the BIT.  

#### Query operation to get the prefix sum till x:  

`int query(int x)
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
    {
        sum += BIT[x];
    }
    return sum;
}`  

This gives the sum of all the BITs which cover the prefix sum till x. The observed property helps us in taking all such BITs.  

#### Other advantages:  

- We can do operations other than sum too, which satisfy associativity and which have an inverse.
- Examples :  
    + Multiplication has inverse division
    + Sum of matrices has inverse
- The space complexity is **O(n)** and time complexity is **O(logn)**.