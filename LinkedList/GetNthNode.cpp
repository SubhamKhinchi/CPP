#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
void insert (Node** head, int key){
    Node* temp = new Node();
    temp->data = key;
    temp->next = *head;
    *head = temp;
}
int getnthnode(Node** head, int x){
    Node* temp = *head;
    int i=1;
    while(i<x){
        temp= temp->next;
        i++;
    }
    return temp->data;
}
int main() {
	Node* head = NULL;
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);
	cout<<getnthnode(&head,3);
	return 0;
}