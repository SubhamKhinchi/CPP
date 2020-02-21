#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* newNode(int x){
    node* Node = new node();
    Node->data=x;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}
void printpostorder(node* root){
    node* temp = root;
    stack<node*> s1;
    stack<node*> s2;
    s1.push(temp);
    while(!s1.empty()){
        temp = s1.top();
        s2.push(temp);
        s1.pop();
        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        node* x = s2.top();
        cout<<x->data<<" ";
        s2.pop();
    }
}
int main(){
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    printpostorder(root);
    return 0;
}
