#include <stdio.h>
#include <stdlib.h>
void autonum(long int number) // making the function for automorphic number
{
    long int flag = 1, num = number, n;
    long int squared = number * number;
    long int s = squared; // finding square of the input value
    if (num < 0)
    {
        num = num * (-1);
    }
    n = num;
    while (num > 0)
    {
        if ((num % 10) != (squared % 10)) //checking for automorphic number
        {
            flag = 0;
            break;
        }
        num = num / 10;
        squared = squared / 10;
    }
    if (flag == 0)
    {
        printf("%ld is not an automorphic number.(Since, square of %ld is %ld and it does not end with %ld)\n", number, number, s, n);
    } // printing the corresponding statement
    else
    {
        printf("%ld is an automorphic number.(Since, square of %ld is %ld and it ends with %ld)\n", number, number, s, number);
    }
}
int main()
{
    int ch;
    while (1)
    {
        long int number;
        printf("\n1.Checking for automorphic number\n2.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("\nEnter a valid number\n");
            scanf("%ld", &number); // user input
            autonum(number);
        }
        else if (ch == 2)
        {
            break;
        }
        else
        {
            printf("Enter a valid choice\n");
        }
        printf("\nIf you want to exit enter 2\n"); //if the user wants to continue or end the program
        int c;
        scanf("%d", &c);
        if (c == 2)
            break;
    }
    return 0;
}
/* SAMPLE OUTPUT
1.Checking for automorphic number
2.Exit

Enter your choice
1

Enter a valid number
25
25 is an automorphic number.(Since, square of 25 is 625 and it ends with 25)

If you want to exit enter 2
3

1.Checking for automorphic number
2.Exit

Enter your choice
1

Enter a valid number
4
4 is not an automorphic number.(Since, square of 4 is 16 and it does not end with 4)

If you want to exit enter 2
2
Exit.*/