#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

void insert(struct node** head, int a){
	struct node* temp= new node();
	temp->data=a;
	temp->next=NULL;
	if (*head==NULL){
		*head=temp;
		return;
	}
	struct node* temp1 = *head;
	while (temp1->next!=NULL){
		temp1=temp1->next;
	}
	temp1->next=temp;
	return;
}

void printlist(struct node* temp){
	while (temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}

bool detectloop (struct node** head){
	struct node* temp = *head;
	unordered_set<node*> seen;
	while (temp!=NULL){
		if (seen.find(temp)!=seen.end()){
			return true;
		}
		else{
			seen.insert(temp);
		}
		temp=temp->next;
	}
	return false;
}

int main(){
	struct node* head= NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,2);
	insert(&head,2);
	insert(&head,4);
	insert(&head,4);
	insert(&head,5);
	printlist(head);
	head->next->next->next->next->next=head->next; //making a loop in our linked list
	cout<<detectloop(&head);
	return 0;
}