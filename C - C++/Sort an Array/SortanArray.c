#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    //create array of size n
    int a[n];
    //Reading array elements
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int m=n/2;
    int temp;
    //Sorting first half of the array in ascending order
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    //Sorting second half of the array in descending order
    for(int i=m;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]<a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Resulting array:");
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf(" ");
    }
    return 0;
}
