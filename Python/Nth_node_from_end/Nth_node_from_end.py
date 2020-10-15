class Node:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_end(self, data):
        if self.head is None:
            self.head = Node(data, None)
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = Node(data, None)

    def length(self):
        count = 0
        temp = self.head
        while temp:
            count += 1
            temp = temp.next
        return count

    def nth_node_from_last(self, n):
        if n <= 0 or n > self.length():
            return
        required_index = self.length() - n
        temp = self.head
        i = 0
        while i < required_index:
            temp = temp.next
            i += 1
        
        return temp.data

if __name__ == '__main__':  
    ll = LinkedList() 
    ll.insert_at_end(1) 
    ll.insert_at_end(2) 
    ll.insert_at_end(3)
    ll.insert_at_end(4)
    print("Enter the node number you want to find out from the end")
    n = int(input())
    ans = ll.nth_node_from_last(n)
    if ans is None:
        print("Invalid Input")
    else:
        print("Required node from the last is :", ans)
        