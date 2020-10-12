#include<stdio.h>
#include<stdlib.h>
struct node
{
int num;
struct node*next;
};
struct linked
{
struct node *start;
int size;
};
struct linked* createLinkedList()
{
struct linked *linkedlist;
linkedlist=(struct linked*)malloc(sizeof(struct linked));
linkedlist->start=NULL;
linkedlist->size=0;
return linkedlist;
}
int addInLinkedList(struct linked *linkedlist,int num)
{
struct node*t,*j;
t=(struct node*)malloc(sizeof(struct node));
t->num=num;
t->next=NULL;
if(linkedlist->start==NULL)
{
linkedlist->start=t;
linkedlist->size++;
return 1;
}
j=linkedlist->start;
while(j->next!=NULL)j=j->next;
j->next=t;
linkedlist->size++;
return 1;
}
void displayElementOfLinkedList(struct linked *linkedlist)
{
struct node*t;
t=linkedlist->start;
while(t!=NULL)
{
printf("%d\n",t->num);
t=t->next;
}
}
void mergeLinkedList(struct linked *targetlinkedlist,struct linked *sourcelinkedlist)
{
struct node *t,*j;
struct linked *list3;
list3=createLinkedList();
t=targetlinkedlist->start;
j=sourcelinkedlist->start;
while(t!=NULL&&j!=NULL)
{
if(t->num>j->num)
{
addInLinkedList(list3,j->num);
j=j->next;
}
else
{
addInLinkedList(list3,t->num);
t=t->next;
}
}
while(t!=NULL)
{
addInLinkedList(list3,t->num);
t=t->next;
}
while(j!=NULL)
{
addInLinkedList(list3,j->num);
j=j->next;
}
targetlinkedlist->start=list3->start;
}
int main()
{
int ch,num;
struct linked *list1,*list2;
list1=createLinkedList();
list2=createLinkedList();
while(1)
{
printf("1.add number in first linked list in sorted order\n");
printf("2.display the element of first  linked list\n");
printf("3.add number in second  linked list in sorted order\n");
printf("4.display the element of first linked list \n");
printf("5.merge first linked and second linked list\n");
printf("6.exit\n");
printf("enter your choice:");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("enter the number to be add in first linked list:");
scanf("%d",&num);
fflush(stdin);
if(addInLinkedList(list1,num))printf("%d is added in first linked list\n",num);
else printf("%d is not added in first linked list\n",num);
}
else if(ch==2)
{
printf("Element of first linked list\n");
displayElementOfLinkedList(list1);
}
if(ch==3)
{
printf("enter the number to be add in second linked list:");
scanf("%d",&num);
fflush(stdin);
if(addInLinkedList(list2,num))printf("%d is added in second linked list\n",num);
else printf("%d is not added in  second linked list\n",num);
}
else if(ch==4)
{
printf("Element of second linked list\n");
displayElementOfLinkedList(list2);
}
else if(ch==5)
{
mergeLinkedList(list1,list2);
displayElementOfLinkedList(list1);
break;
}
else if(ch==6)break;
}
return 0;
}