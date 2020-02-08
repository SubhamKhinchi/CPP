int getCount(struct Node* head){
    //Code here
    int count=0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}