#include <iostream>

using namespace std;

int is_harshad_no(int number)
{
    // Creating a copy of the number to extract each digit
    int ncopy = number;
    int digit, sum_of_digits = 0;

    // Extracting each digit and computing the sum using a while loop
    while(ncopy>0)
    {
        digit = ncopy % 10;      //digit varible contains the value of the digit currently in the units place
        sum_of_digits += digit;  //Adding the digits value to the existing sum 
        ncopy /= 10;             //Dividing the copy of the number by 10 such that in the next iteration we get the current tens place
    }

    // Checking whether the number is a Harshad number by finding the reminder of the the number divided by the sum of digits
    if (number==0 || number%sum_of_digits==0)
        return 1;
    else
        return 0;
}

int main()
{
    // Declaring variables for the integer and taking it as input from the user
    int number;
    cout<<"Enter an integer: ";
    cin>>number;
    
    // Checking whether the number is a Harshad Number using a function
    if (is_harshad_no(number))
        cout<<number<<" is a Harshad number.";
    else
        cout<<number<<" is not a Harshad number.";
    
    return 0;
}
