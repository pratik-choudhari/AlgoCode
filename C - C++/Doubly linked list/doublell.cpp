#include <iostream>
using namespace std;
  
// A doubly linked list node
struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};
  
//inserts node at the front of the list
void insert_beg(struct Node** head_ref, int new_data)
{
   //allocate memory for New node
   struct Node* newNode = new Node;
  
   //assign data to new node
   newNode->data = new_data;
  
   //new node is head and previous is null, since we are adding at the front
   newNode->next = (*head_ref);
   newNode->prev = NULL;
  
   //previous of head is new node
   if ((*head_ref) != NULL)
   (*head_ref)->prev = newNode;
  
   //head points to new node
   (*head_ref) = newNode;
}
/* Given a node as prev_node, insert a new node after the given node */
void insert_pos(struct Node** head_ref, int new_data,int pos)
{ int c=0;
   //check if prev node is null
   if (head_ref == NULL) {
   cout<<"Previous node is required , it cannot be NULL";
   return;
}
   //allocate memory for new node
   struct Node* newNode = new Node;
   struct Node* last= *head_ref;
   //assign data to new node
   newNode->data = new_data;
   while (last->next !=NULL ){
        last = last->next;
        c++;
        if(c==pos){
        last->next=newNode;
        newNode->prev=last;
        newNode->next=last->next->next;
        last=newNode;
        break;
}
return;
}
  
//insert a new node at the end of the list
void insert_end(struct Node** head_ref, int num)
{ 
   //allocate memory for node
   struct Node* newNode = new Node;
  
   struct Node* last = *head_ref; //set last node value to head
  
   //set data for new node
   newNode->data = num;
  
   //new node is the last node , so set next of new node to null
   newNode->next = NULL;
  
   //check if list is empty, if yes make new node the head of list
   if (*head_ref == NULL) {
   newNode->prev = NULL;
   *head_ref = newNode;
    return;
        }
  
//otherwise traverse the list to go to last node
        while(last->next!=NULL){
                last=last->next;
        }
        last->next=newNode->prev;
        last->next=newNode;
        newNode->next=NULL;
return;
}
void delete_beg(Node** head_ref, Node* del) 
{ 
    /* base case */
    if (*head_ref == NULL || del == NULL) 
        return; 
 
    /* If node to be deleted is head node */
    if (*head_ref == del) 
        *head_ref = del->next; 
 
    /* Change next only if node to be 
    deleted is NOT the last node */
    if (del->next != NULL) 
        del->next->prev = del->prev; 
 
    /* Change prev only if node to be 
    deleted is NOT the first node */
    if (del->prev != NULL) 
        del->prev->next = del->next; 
 
    /* Finally, free the memory occupied by del*/
    free(del); 
    return; 
} 

void delete_end(Node** head_ref,Node* del){
        if(*head_ref==NULL)
                return;

        while(del->next!=NULL){
                del=del->next;
        }    
        del->prev->next=NULL;
        free(del);
        return;

}  

void delete_pos(struct Node** head_ref, int pos) 
{ 
    /* if list in NULL or invalid position is given */
    if (*head_ref == NULL || pos <= 0) 
        return; 
  
    struct Node* current = *head_ref; 
    int i; 
  
    /* traverse up to the node at position 'n' from 
       the beginning */
    for (int i = 1; current != NULL && i < pos; i++) 
        current = current->next; 
  
    /* if 'n' is greater than the number of nodes 
       in the doubly linked list */
    if (current == NULL) 
        return; 
  
    /* delete the node pointed to by 'current' */
    delete_beg(head_ref, current); 
} 
bool search(struct Node** head,int nu) {
   int pos = 0;
   
   if(head==NULL) 
      return 0;

   struct Node* current = *head;
   while(current!=NULL) {
      pos++;
      if(current->data == nu) {
        return 1;
      }

      if(current->next != NULL)
        current = current->next;
      else
        break;
   }

   return 0;
}
// This function prints contents of linked list starting from the given node
void display(struct Node* node) {
   struct Node* last;
  
   while (node != NULL) {
      cout<<node->data<<"<==>";
      last = node;
      node = node->next;
   }
   if(node == NULL)
   cout<<"NULL";
   }
  
//main program
int main() {
        int num,pos,nu,o;
   /* Start with the empty list */
   struct Node* head = NULL;
   cout<<"Below are the operations you want to perform on Singly Linked List:\n";
    cout<<"1.Insert a node in the beginning\n";
    cout<<"2.Insert a node at the end\n";
    cout<<"3.Insert a node at nth position\n";
    cout<<"4.Delete first node\n";
    cout<<"5.Delete last node\n";
    cout<<"6.Delete nth node\n";
    cout<<"7.Search an element in a linked list\n";
    cin>>o;
    switch(o){
        case 1:cout<<"\nEnter data you want to insert at the beginning: ";
                cin>>num;
                insert_beg(&head,num);
                cout<<"\nLinked list after insertion: \n";		
                display(head);
                break;
        case 2:cout<<"\nEnter data you want to insert at the end: ";
                cin>>num;
                insert_end(&head,num);
                cout<<"\nLinked list after insertion: \n";		
                display(head);
                break;
        case 3:cout<<"\nEnter data you want to insert at the given value: ";
                cin>>num;
                cout<<"\nEnter the position where you want to enter the data:";
                cin>>pos;
                insert_pos(&head,num,pos);
                cout<<"\nLinked list after insertion: \n";		
                display(head);
                break;
        case 4: delete_beg(&head,head);
                cout<<"\nLinked list after deletion: \n";		
                display(head); 
                break;
        case 5: delete_end(&head,head);
                cout<<"\nLinked list after deletion: \n";		
                display(head);
                break;
        case 6:cout<<"\nEnter position at which you want to delete node in the linked list: ";
                cin>>pos;
                delete_pos(&head,pos);
                cout<<"\nLinked list after deletion: \n";		
                display(head);
                break;
        case 7:cout<<"\nEnter data you want to search in the linked list: ";
                cin>>nu;
                search(&head,nu)?cout<<"Yes data is present in linked list":cout<<"No data is not present in linked list";
                cout<<"\nLinked list after searching: \n";		
                display(head); 
                break;
        case 8: cout<<"Wrong choice";
                break;                       
    }        
   return 0;
}