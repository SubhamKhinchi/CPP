int GetNth(struct node* head, int index){
  // Code here
    node* temp = head;
    while(index--){
        temp = temp->next;
    }
    return temp->data;
}