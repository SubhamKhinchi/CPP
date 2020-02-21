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
void printpreorder(node* root){
    node* temp = root;
    stack<node*> s;
    s.push(temp);
    while(!s.empty()){
        temp = s.top();
        cout<<temp->data<<" ";
        s.pop();
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}
int main(){
    node *root = newNode(10); 
  root->left        = newNode(8); 
  root->right       = newNode(2); 
  root->left->left  = newNode(3); 
  root->left->right = newNode(5); 
  root->right->left = newNode(2); 
    printpreorder(root);
    return 0;
}
