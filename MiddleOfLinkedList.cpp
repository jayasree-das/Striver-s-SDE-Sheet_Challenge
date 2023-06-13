//optimal approach1
T.C:-O(n+n/2) -~ O(n)
S.C:-O(1)
Node *findMiddle(Node *head) {
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    int mid=cnt/2;
    Node *temp2=head;
    while(mid--){
        temp2=temp2->next;
    }
    return temp2;
}


//Optimal Approach2
T.C:-O(n)
S.C:-O(1)
Node *findMiddle(Node *head) {
    if(head==NULL) return head;
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

