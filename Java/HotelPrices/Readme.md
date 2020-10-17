# Hotel Prices 

A hotel has two types of room standard and luxury. Every customer mentions the number of bedrooms and bathrooms required for that particular room.

```Cost of standard room = 5 * bedrooms + 2 * bathrooms```

Cost of luxury room = cost of standard room for same bedrooms and bathrooms + 200


The task is to print the total cost of rooms requested.

### Input format
First line will be the number of test cases. Room data format `room-type bedrooms bathrooms`.
There can be any number of __standard__ and __luxury__ rooms.


#### Sample input 
2   
standard 3 1   
luxury 1 1   

#### Sample Output:
224

#### Explanation:
Standard fee: (5 * 3 + 2 * 1)   
luxury: (5 * 1 + 2 * 1) + 200   
__Total = Standard + Luxury__


# To run the code
Type the follow commands - 
- javac HotelPrices.java
- java HotelPrices
- Enter the input based on the input format