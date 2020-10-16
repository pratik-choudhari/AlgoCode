#include<stdio.h>
int main()
{
    char ch;
    printf("Enter a character\n");
    scanf("%c",&ch);
    if(ch == 'a'|| ch == 'A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')
    {
        printf("%c is a vowel.\n",ch);
    }
    else
    {
        printf("%c is not a vowel.\n",ch);
    }
    return 0;
}