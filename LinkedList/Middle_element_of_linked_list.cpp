int getMiddle(Node *head)
{
   // Your code here
   if(head==NULL){
       return -1;
   }
   Node* temp = head;
   int count = 0;
   while(temp){
       temp = temp->next;
       count++;
   }
   int n = (count/2)+1;
   Node* t = head;
   int i=1;
   while(i<n){
       t=t->next;
       i++;
   }
   return t->data;
}