#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
//Insert Function to make a linked list on which we are gonna apply below three insert functions
void insert(Node** head, int k){
    Node* temp = new Node();
    temp->data = k;
    temp->next = *head;
    *head = temp;
}

//Inserting a Node at the beginning of the Linked List.
void insertatstart(Node** head, int k){
    Node* temp = new Node();
    temp->data = k;
    temp->next = *head;
    *head = temp;
}

//Inserting a Node at the end of a Linked List.
void insertatend (Node** head, int k){
    Node* temp = *head;
    Node* temp1 = new Node();
    temp1->data = k;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=temp1;
    temp1->next = NULL;
}

//Inserting a Node at the given nth postion of a Linked List.
void insertatgiven (Node** head,int n, int k){
    Node* temp = new Node();
    temp->data = k;
    Node* temp1 = *head;
    int i=1;
    while(i<n-1){
        temp1=temp1->next;
        i++;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

//Function to print the Linked List.
void printlist(Node* head){
    Node* t = head;
    while(t){
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<"\n";
}
int main() {
	Node* head = NULL;
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);
	cout<<"original linked list : ";
	printlist(head);
	
	insertatstart(&head, 5);
	printlist(head);
	
	insertatend(&head, 6);
	printlist(head);
	
	insertatgiven(&head,2, 7);
	printlist(head);
	return 0;
}