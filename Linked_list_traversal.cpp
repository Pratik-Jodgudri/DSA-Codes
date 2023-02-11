#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
//		Node(int val){
//			data = val;
//			next = NULL;
//		}
};

//void insertAtTail(Node* &head, int val){
//	Node* n = new Node(val);
//	
//	if(head == NULL){
//		head = n;
//		return;
//	}
//	
//	Node* temp = head;
//	while (temp->next != NULL){
//		temp = temp->next;
//	}
//	temp->next = n;
//}
//
//void display(Node* head){
//	Node* temp=head;
//	while(temp != NULL){
//		cout << temp->data << " -> ";
//		temp = temp->next;
//	}
//	cout << "NULL" << endl;
//}

//void insertAtHead(Node* &head, int val){
//	Node* n = new Node(val);
//	n->next = head;
//	
//	head = n;
//}

void linkedlistTraversal(Node* ptr)
{
	while(ptr != NULL)
	{
		cout << 1;
		cout << ptr->data;
		ptr = ptr->next;
	}
}

int main()
{
	Node* head;
	Node* second;
	Node* third;
	
	head->next = second;
	head->data = 7;
	second->next = third;
	second->data = 11;
	third->next = NULL;
	third->data = 22;
	
	linkedlistTraversal(head);
		
//	insertAtTail(head, 1);
//	insertAtTail(head, 2);
//	insertAtTail(head, 3);
//	display(head);
//	
//	insertAtHead(head, 4);
//	display(head);
	return 0;
}