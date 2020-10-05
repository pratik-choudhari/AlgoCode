#include <stdio.h>
int main()
{
int a=0,b=1,c,n;
printf("Enter a number to search in fibonacci series\n");
scanf("%d",&n);
while(1)
{
c=a+b;
a=b;
b=c;
if(c==n)
{
printf("\ntrue");
break;
}
if(c>n)
{
printf("\nfalse");
break;
}

}

return 0;
}
