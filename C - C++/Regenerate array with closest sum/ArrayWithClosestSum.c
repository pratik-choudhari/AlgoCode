//we first include the header file we need for standard input/output functions
#include<stdio.h>
//this is the main method 
void main()
{
    //we take input for the no. of elements the user intends to input in the array
    int n;
    printf("Enter the no. of elements you would like to input:");
    scanf("%d",&n);

    printf("\n");

    //array to take the input 
    int a[n];
    //variable to store the sum
    long sum=0;

    for(int i=0; i<n; i++)
    {
        printf("Enter element %d:",(i+1));
        scanf("%d",&a[i]);
        //we parallely calculate the sum as we would require it later
        sum+=a[i];
    }//for ends

    printf("\n");
    //we output (sum/n)+1 as its the solution to the problem we are solving
    printf("The minimum value to be assigned to the elements so that sum becomes greater than initial sum is: %d",((sum/n)+1));
}//main ends


