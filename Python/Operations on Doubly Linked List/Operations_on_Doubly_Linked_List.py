# class to create a Node datatype
class Node: 
    def __init__(self, data): 
        self.next = None    # reference to next node in DLL, initialized to None while creating a node
        self.prev = None    # reference to previous node in DLL, initialized to None while creating a node
        self.data = data    # value contained in node

# class to create a Doubly Linked List with the required functions
class doublyLinkedList:
    def __init__(self):
        self.head = None            # initializing the DLL with a None/Null node
        self.nodecount = 0

    def insert_at_the_start(self, data):
        newnode = Node(data)        # declaring a new node with the data as given to the function
        self.nodecount += 1
        if self.head == None:
            self.head = newnode     # if DLL is empty we declare the new node as the head
        else:
            newnode.next = self.head   # if the DLL does contain a head node, the new node->next is linked to existing head node
            self.head.prev = newnode   # link the start node->prev link to the newnode
            self.head = newnode        # declare new node as the head node of the DLL

    def insert_at_the_end(self, data):
        newnode = Node(data)
        self.nodecount += 1
        if self.head == None:          
            self.head = newnode        
        else:
            temp = self.head           # else traverse the entire list as even DLLs have only one reference node which is the head
            while temp.next != None:   # search for the node whose next node is None which is the last node presently
                temp = temp.next
            temp.next = newnode        # the last node->next link is attached to the new node, which makes the new node the last node
            newnode.prev = temp        # the new node->prev link is attached to the previously existing last node      
    
    def insert_at_position(self, data, position):    
        newnode = Node(data)
        self.nodecount += 1
        if self.head == None:          
            self.head = newnode
        elif position == 1:
            newnode.next = self.head    # if the position is 1 we follow the same steps as inserting at the beginning
            self.head = newnode          
        else:
            i = 1
            temp = self.head
            while i!=position and temp.next!=None:  # else we search for the position while traversing the dll
                i += 1
                temp = temp.next
            temp.prev.next = newnode    # the node before the position must be linked to the new node
            newnode.prev = temp.prev    # the new node->prev should be linked to the previous node
            newnode.next = temp         # the new node->next must link to the node currently at the required position
            temp.prev = newnode         # the node which was in the position required should link node->prev to new node

    def delete_beginning(self):
        if self.head == None:
            print("List is empty.")     # if list is empty we do not delete 
        elif self.head.next == None:
            self.head = None            # if the list contains only one node we set head to None
            self.nodecount = 0
        else:
            self.head = self.head.next  # else we change the head to the 2nd node in the list     
            self.nodecount -= 1
    
    def delete_ending(self):
        if self.head == None:
            print("List is empty.")
        elif self.head.next == None:
            self.head = None
            self.nodecount = 0
        else:
            temp = self.head           
            while temp.next != None:   # search for the last node by checking the next link
                temp = temp.next    
            temp.prev.next = None      # change the second last nodes->next to None
            self.nodecount -= 1

    def delete_at_position(self, position):
        if self.head == None:          
            print("List is empty.")  
        elif position==1:
            self.head = self.head.next
            self.nodecount -= 1   
        else:
            i = 1
            temp = self.head            
            while i!=position and temp!=None:   # search for node number to be deleted by traversing the dll
                i += 1
                temp = temp.next
            temp.prev.next = temp.next          # the previous nodes->next link is attached to the node after the one to be deleted
            temp.next.prev = temp.prev          # the next node->prev link is attached to the node previous to the one to be deleted
            self.nodecount -= 1

    def display_dll(self):
        if self.head == None:          
            print("List is empty.") 
        else:
            temp = self.head
            while temp!=None:
                print (temp.data, "->", end=" ")    # traversing the dll and printing the data values
                temp = temp.next
            print("\n")       

l = doublyLinkedList()
l.insert_at_the_start(10)   # insert 10 at the beginning
l.insert_at_the_start(4)
l.insert_at_the_end(7)      # insert 7 at the end
l.insert_at_the_end(9)
l.insert_at_position(4, 3)  # insert 4 at position 3
l.insert_at_position(6, 2)
l.display_dll()
l.delete_beginning()
l.delete_ending()
l.delete_at_position(2)
l.display_dll()  
 