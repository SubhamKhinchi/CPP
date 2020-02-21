#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* NewNode(int x){
    node* Node = new node();
    Node->data=x;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}
void printinorder(node* root){
    node* temp = root;
    stack<node*> s;
    while(temp!=NULL || s.empty()==false){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    
}
int main(){
    node* root = NewNode(1);
    root->left = NewNode(2);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->right = NewNode(3);
    root->right->left = NewNode(6);
    root->right->right = NewNode(7);
    printinorder(root);
    return 0;
}
