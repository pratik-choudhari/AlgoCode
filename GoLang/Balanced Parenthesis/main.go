// balanced parenthesis using linked lists
package main

// imports
import (
	"fmt"
	"bufio"
	"os"
)

// defining a node for a linked list
type node struct {
	d interface{}
	next *node
}

// defining a linked list
type llist struct {
	head *node
}

// to add a new node in the list
func (l *llist) Addnode(d interface{}) {
	n := &node{d: d, next: nil}
	if l.head == nil {
		l.head = n
		return
	}

	t := l.head
	for t.next != nil {
		t = t.next
	}
	t.next = n
}

// to remove a node from a list
func (l *llist) Remove(rd interface{}) {
	t := l.head
	if t.d == rd{
		l.head = t.next
		return
	}

	for t.next != nil {
		if t.next.d == rd {
			t.next = t.next.next
			break
		}
		t = t.next
	}
}

// displaying the elements of list
func (l *llist) Display() string {
	t := l.head
	var word string
	for t != nil {
		word += t.d.(string)
		t = t.next
	}
	return word
} 

// check an element and remove it from the list if it exists
func (l *llist) CheckandRemove(cd interface{}) bool {
	if l.head == nil{
		return false
	} 
	t := l.head
	for t != nil{
		if t.d == cd {
			l.Remove(cd)
			return true
		}
		t = t.next
	}
	return false
}



// <<<<<<<<<<<<<<<<<------------------------- the main function strats here ---------------------------->>>>>>>>>>>>>>>>>>>
func main() {
	l := llist{}

	// taking input from the user
	text, _ := bufio.NewReader(os.Stdin).ReadString('\n')

	// loop through each character of the string
	for _, chr := range text{
		switch string(chr){
		case "{":
			if !l.CheckandRemove("}") {
				l.Addnode("{")
			}
		case "}":
			if !l.CheckandRemove("{") {
				l.Addnode("}")
			}
		case "[":
			if !l.CheckandRemove("]") {
				l.Addnode("[")
			}
		case "]":
			if !l.CheckandRemove("[") {
				l.Addnode("]")
			}
		case "(":
			if !l.CheckandRemove(")") {
				l.Addnode("(")
			}
		case ")":
			if !l.CheckandRemove("(") {
				l.Addnode(")")
			}
		}
	}
	

	// check for the balanced or unbalanced input
	if len(l.Display()) != 0 {
		defer fmt.Print("Unbalanced")
	}else {
		defer fmt.Print("Balanced")
	}
}
// -------------------------------------------------------------------------------------------------------------------------