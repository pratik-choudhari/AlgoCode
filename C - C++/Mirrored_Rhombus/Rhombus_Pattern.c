#include <stdio.h>

int main(){
    int x,y,p,n;

    printf("Input: ");
    scanf("%d",&n); // Input: 4

    for(y = 1; y<=n; y++){
        for(x = y; x<n; x++){
            printf(" ");
        }
        for(p = 0; p<n; p++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}