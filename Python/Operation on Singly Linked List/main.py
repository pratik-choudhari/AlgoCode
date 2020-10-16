class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.start = None
        self.nodecount = 0

    def insertlast(self, data):
        newnode = Node(data)
        self.nodecount += 1
        if self.start == None:
            self.start = newnode
        else:
            temp = self.start
            while temp.next != None:
                temp = temp.next
            temp.next = newnode

    def insertfirst(self, data):
        newnode = Node(data)
        self.nodecount += 1
        if self.start == None:
            self.start = newnode
        else:
            newnode.next = self.start
            self.start = newnode

    def insertatindex(self, index, data):
        if index == 0:
            self.insertfirst(data)
        else:
            newnode = Node(data)
            i = 0
            temp = self.start
            while i != index - 1 and i < self.nodecount - 1:
                temp = temp.next
                i += 1
            newnode.next = temp.next
            temp.next = newnode
            self.nodecount += 1

    def delbeg(self):
        if self.start == None:
            print("List is empty ")
        else:
            self.start = self.start.next
            self.nodecount -= 1

    def delend(self):
        if self.start == None:
            print("List is empty ")
        else:
            node = self.start
            prnode = self.start
            while node.next != None:
                prnode = node
                node = node.next
            prnode.next = None
            self.nodecount -= 1

    def deleteatindex(self, index):
        if self.start == None:
            print("List is empty ")
        elif index == 0:
            self.delbeg()
        else:
            i = 0
            temp = self.start
            while i != index - 1:
                temp = temp.next
                i += 1
            temp2 = temp.next
            temp.next = temp2.next
            temp2 = None
            self.nodecount -= 1

    def search(self, val):
        if self.start == None:
            print("List is empty ")
        else:
            temp = self.start
            pos = 0
            while temp.data != val and temp.next != None:
                temp = temp.next
                pos += 1
            if temp.data == val:
                print("value found at index {}".format(pos))
            else:
                print(val, "is not present")


l = LinkedList()
l.insertfirst(23)
l.insertfirst(62)
l.insertlast(84)
l.search(23)
l.insertlast(9)
l.insertlast(21)
l.insertatindex(2, 34)
print(l.nodecount)
l.delbeg()
l.delend()
l.deleteatindex(2)
print(l.nodecount)
