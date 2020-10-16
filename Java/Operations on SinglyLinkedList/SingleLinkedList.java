import java.util.*;

public class SingleLinkedList {
	static Node head;
	
	//Node is basic unit in LinkeList
	static class Node{
		int data;
		Node next;
		Node(int data){
			this.data  = data;
			next = null;
		}
	}
	//Insert at the beginning of the LinkedList
	private void insertAtBeginning(int data) {
		Node new_node = new Node(data);
		Node temp = head;
		head = new_node;
		head.next = temp;
	}
	//Insert at the end of the LinkedList
	private void insertAtEnd(int data) {
		Node new_node = new Node(data);
		new_node.next = null;
		if(head == null) {
			head = new_node;
		}
		else {
			Node temp = head;
			while(temp.next != null) {
				temp = temp.next;
			}
			temp.next = new_node;
		}
	}
	//Insert at a position in the LinkedList
	private void insertAtPosition(int position,int data) {
		Node new_node = new Node(data);
		int count = 1;
		Node temp = head;
		while(count != position-1) {
			temp = temp.next;
			count++;
		}
		new_node.next = temp.next;
		temp.next = new_node;
	}
	//Delete at the beginning of the LinkedList
	private void deleteAtBeginning() {
		head = head.next;
	}
	//Delete at the end of the LinkedList
	private void deleteAtEnd() {
		Node temp = head;
		while(temp.next.next != null) {
			temp = temp.next;
		}
		temp.next = null;
	}
	//Delete at a position in the LinkedList
	private void deleteAtPosition(int position) {
		int count = 1;
		Node temp = head;
		while(count != position-1) {
			temp = temp.next;
			count++;
		}
		temp.next = temp.next.next;
	}
	//Search for an element in LinkedList
	private void searchElement(int element) {
		Node temp = head;
		int count = 1;
		while(temp.data != element) {
			temp = temp.next;
			count++;
		}
		System.out.println("Element is at " + count +" position");
	}
	private static void printList(SingleLinkedList list) {
		if(list.head == null) {
			System.out.println("Empty list");
		}
		else {
			System.out.println("LinkedList:");
			Node temp = head;
			while(temp.next != null) {
				System.out.print(temp.data + " ");
				temp = temp.next;
			}
			System.out.print(temp.data);
		}
	}
	public static void main(String args[]) {
		Scanner scan = null;
		try {
			scan = new Scanner(System.in);
		}catch(Exception e) {
			System.out.println(e);
		}
		SingleLinkedList list = new SingleLinkedList();
		System.out.println("0 => Exit\n1 => insert at Beginning\n2 => insert at End\n3 => insert at particular position\n4 => delete at Beginning\n5 => delete at End\n6 => delete at particular position\n7 => Search element\nSpecify the data along with the operation:");
		int input;
		while((input = scan.nextInt())!= 0) {
			switch(input) {
				case 1 : list.insertAtBeginning(scan.nextInt());
						 break;
				case 2 : list.insertAtEnd(scan.nextInt());
						 break;
				case 3 : list.insertAtPosition(scan.nextInt(),scan.nextInt());
						 break;
				case 4 : list.deleteAtBeginning();
						 break;
				case 5 : list.deleteAtEnd();
						 break;
				case 6 : list.deleteAtPosition(scan.nextInt());
						 break;
				case 7 : list.searchElement(scan.nextInt());
						 break;
			}
		};
		printList(list);
	}
}
