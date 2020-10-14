#include <stdio.h>
#include <stdbool.h>

bool check(int array[], int k, int n) //function to check if the array can be sorted under given conditions
{
    int i, x, y, j;
    for (i = 0; i < k; i++)
    {
        int temp[100]; //initialize a temporary array for storing the values at jth positions
        x = 0;
        y = 0;
        for (j = i; j < n; j = j + k)
        {
            temp[x] = array[j];
            x++;
        }
        int a, b, c; // variables for sorting the array using bubble sort
        for (a = 0; a < x - 1; a++)
        {
            for (b = 0; b < x - a - 1; b++)
            {
                if (temp[b] > temp[b + 1])
                {
                    c = temp[b]; //c variable is a temporary variable
                    temp[b] = temp[b + 1];
                    temp[b + 1] = c;
                }
            }
        }
        for (j = i; j < n; j = j + k) //replacing the values of sorted array with the values of original array at jth positions
        {
            array[j] = temp[y];
            y++;
        }
    }
    for (i = 0; i < n - 1; i++) //checking if the array is sorted or not
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

//driver code
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int array[1000], i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    if (check(array, k, n)) //printing the answer according to the condition being true or false
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}
/* SAMPLE OUTPUT
6 2 
4 2 7 1 3 6
False*/
