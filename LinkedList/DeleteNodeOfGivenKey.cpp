#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};

void insert(Node** head, int k){
    Node* temp = new Node();
    temp->data = k;
    temp->next = *head;
    *head = temp;
}
Node* deletenode (Node** head,  int key){
    //if head has to be deleted.
    if((*head)->data == key){
        Node* temp = (*head)->next;
        *head = temp;
    }
    Node* curr, *prev ;
    curr = *head;
    prev = NULL;
    while(curr){
        if(curr->data == key){
            prev->next = curr->next;
            return *head;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return *head;
}
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
	deletenode(&head , 2);
	cout<<"Linked list after deletion : ";
	printlist(head);
	return 0;
}