#include<stdio.h>

int main(void)
{
    int n, c = 0;  //size of array, c = to ensure that the triplet is found
    scanf("%d", &n);
    //array
    int arr[n];
    //user-input
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //we will deal with three numbers at a time
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                //squaring the numbers
                int a = arr[i] * arr[i], b = arr[j] * arr[j], c = arr[k] * arr[k];
                //check if a set of three fulfills the pythagorean theorem
                if(a == b + c || b == a + c || c == a + b)
                {
                    c = 1;
                    printf("Pythagorean Triplet is: ");
                    printf("[%d %d %d]\n", arr[i], arr[j], arr[k]);
                }
            }
        }
    }
    //if there is no triplet
    if(c == 0)
    {
        printf("There is no Pythagorean triplet in the given array.\n");
    }
}