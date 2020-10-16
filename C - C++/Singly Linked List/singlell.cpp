#include <iostream>
using namespace std;

struct node 
{
    int num;                
    node *next;             
}*stnode; //node constructed

void createList(int n);                 
void insertatBegin(int num);
void insertAtEnd (struct node *stnode, int num);	     
void insertAtValue (struct node* stnode, int num, int pos,int n); 
void deleteatBegin(struct node* stnode);
void deleteatEnd(struct node* stnode);
void deleteatValue(struct node* stnode,int pos);
bool search(struct node* stnode,int num);
void display();                          
 
int main()
{
    int n,o,num,pos,nu;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    createList(n);
    cout<<"\nLinked list data: \n";		
    display();
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
                insertatBegin(num);
                cout<<"\nLinked list after insertion: \n";		
                display();
                break;
        case 2:cout<<"\nEnter data you want to insert at the end: ";
                cin>>num;
                insertAtEnd (&stnode,num);
                cout<<"\nLinked list after insertion: \n";		
                display();
                break;
        case 3:cout<<"\nEnter data you want to insert at the given value: ";
                cin>>num;
                cout<<"\nEnter the position where you want to enter the data:";
                cin>>pos;
                insertAtValue(&stnode,num,pos,n);
                cout<<"\nLinked list after insertion: \n";		
                display();
                break;
        case 4: deleteatBegin(&stnode);
                cout<<"\nLinked list after deletion: \n";		
                display(); 
                break;
        case 5: deleteatEnd(&stnode);
                cout<<"\nLinked list after deletion: \n";		
                display();
                break;
        case 6:cout<<"\nEnter position you want to delete in the linked list: ";
                cin>>pos;
                deleteatValue(&stnode,pos);
                cout<<"\nLinked list after deletion: \n";		
                display();
                break;
        case 7:cout<<"\nEnter data you want to search in the linked list: ";
                cin>>nu;
                search(&stnode,nu)?cout<<"Yes data is present in linked list":cout<<"No data is not present in linked list";
                cout<<"\nLinked list after searching: \n";		
                display(); 
                break;
        case 8: cout<<"Wrong choice";
                break;                       
    }        

    return 0;
}
void createList(int n) //function to create linked list.
{
    struct node *frntNode, *tmp;
    int num, i;
 
    stnode = (struct node *)malloc(sizeof(struct node));
    if(stnode == NULL)        
    {
        cout<<" Memory can not be allocated";
    }
    else
    {
                                  
        cout<<"Enter the data for node 1: ";
        cin>>num;
        stnode-> num = num;      
        stnode-> next = NULL; //Links the address field to NULL
        tmp = stnode;
 
        for(i=2; i<=n; i++)
        {
            frntNode = (struct node *)malloc(sizeof(struct node)); 
 

            if(frntNode == NULL) //If frntnode is null no memory cannot be alloted
            {
                cout<<" Memory can not be allocated";
                break;
            }
            else
            {
                cout<<"Enter the data for node "<<i<<": "; // Entering data in nodes.
                cin>>num;
                frntNode->num = num;         
                frntNode->next = NULL;    
                tmp->next = frntNode;     
                tmp = tmp->next;
            }
        }
    }
} 

void insertatBegin(int num) //function to insert element at beginning
{
    struct node *frntNode;
    frntNode = (struct node*)malloc(sizeof(struct node));
    if(frntNode == NULL)
    {
        cout<<" Memory can not be allocated";
    }
    else
    {
        frntNode->num = num;         //Linkinking data
        frntNode->next = stnode; //Linking address
        stnode = frntNode; 
    }
}
void insertAtEnd (node* frntNode, int num){

        node* temp=frntNode;

        while(temp!=NULL) temp=temp->next;

        temp = (struct node*)malloc(sizeof(struct node));;
        temp->num=num;
        temp->next=NULL;

        if(frntNode==NULL) frntNode=temp;

}

void insertAtValue(node* frntNode, int num,int pos,int n){
    if (pos < 1 || pos > n + 1) 
        cout << "Invalid position!" << endl; 
    else { 
        while (pos--) { 
  
            if (pos == 0) {  
                node* temp = (struct node*)malloc(sizeof(struct node)); 
                temp->next = frntNode; 
                frntNode = temp; 
            } 
            else 
              frntNode = frntNode->next; 
        } 
        n++; 
    } 

}
void deleteatBegin(node* frntNode){
    if (frntNode == NULL) 
        cout<<"Invalid Position!\n";
  
    // Move the head pointer to the next node 
    node* temp = frntNode; 
    frntNode = frntNode->next; 
  
    delete temp;  
}
void deleteatEnd(node* frntNode){
    if (frntNode == NULL) 
        cout<<"List is empty\n"; 
  
    if (frntNode->next == NULL) { 
        delete frntNode;  
    } 
  
    // Find the second last node 
    node* second_last = frntNode; 
    while (second_last->next->next != NULL) 
        second_last = second_last->next; 
  
    // Delete last node 
    delete (second_last->next); 
  
    // Change next of second last 
    second_last->next = NULL;  

}
void deleteatValue(node* frntNode, int pos){
    if (frntNode == NULL) 
      cout<<"Invalid Position\n"; 
  
   // Store head node 
   struct node* temp = frntNode; 
  
    // If head needs to be removed 
    if (pos == 0) 
    { 
        frntNode = temp->next;   // Change head 
        free(temp);               // free old head  
    } 
  
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<pos-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of nodes 
    if (temp == NULL || temp->next == NULL) 
        cout<<"Invalid Position\n";
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct node *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;
}

bool search(node* ftrNode, int nu)  
{  
    node* current = ftrNode; // Initialize current  
    while (current != NULL)  
    {  
        if (current->num == nu)  
            return true;  
        current = current->next;  
    }  
    return false;  
}

void display() //function to print linked list
{
    struct node *tmp;
    if(stnode == NULL)
    {
        cout<<" No data found in the list";
    }
    else
    {
        tmp = stnode;
        cout<<"Linked List: ";
        while(tmp != NULL)
        {
            cout<<"\t"<<tmp->num;         
            tmp = tmp->next;         
        }
    }
} 
