#include <stdio.h>
int main(){
    int ch,n,i,m=0;
    while(1){
        printf("\n\nOptions to choose:-\n");
        printf("1.Finding Factorial Using Recursion\n2.Finding fibonacci series using recursion\n3.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("Enter the number to find its factorial: ");
            scanf("%d",&n);
            fact();
            printf("Factorial of %d is %d",n,fact(n));
            break;
        case 2:
           printf("Enter the number to find the fibonacci series: ");
           scanf("%d",&n);
           for(i=0;i<n;i++){
                printf("%d ",fib(m));
                m++;
           }
           break;
        case 3:
            exit(1);
        }
    }
    return 0;
}
int fact(int n){
    if(n>0)
        return(n*fact(n-1));
    else
        return(1);
}
int fib(int n){
    if(n==0 || n==1)
        return n;
    return(fib(n-1)+fib(n-2));
}
