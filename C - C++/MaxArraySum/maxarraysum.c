#include <stdio.h>

void MaxSum(int array[], int n) //function to find the maximum sum of the subsets such that no two elements are adjacent
{
    int take = array[0], leave = 0, leave1, i;
    for (i = 1; i < n; i++)
    {
        if (take > leave) //finding the maximum
        {
            leave1 = take;
        }
        else
        {
            leave1 = leave;
        }
        take = leave + array[i]; //updating the values of take and leave
        leave = leave1;
    }
    if (take > leave) //printing the maximum sum
    {
        printf("%d\n\n", take);
    }
    else
    {
        printf("%d\n\n", leave);
    }
}

//Driver code
int main()
{
    int n, i;
    int array[1000];
    printf("Enter the size of array : ");
    scanf("%d", &n); //user inputs the size of array
    printf("Enter the elements of the array :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]); //user inputs the array elements
    }
    printf("\nThe maximum sum of the subsets of the array is : ");
    MaxSum(array, n);
    return 0;
}

/* SAMPLE OUTPUT
Enter the size of array : 5
Enter the elements of the array :3 7 4 6 5

The maximum sum of the subsets of the array is : 13

*/
