//brute force 
T.C:-O(n*k)
S.C:-O(1)
Node *rotate(Node *head, int k) {
     if(head==NULL || head->next==NULL) return head;
     while(k--){
          Node* temp=head;
          while(temp->next->next!=NULL){
               temp=temp->next;
          }
          Node *end=temp->next;
          temp->next=NULL;
          end->next=head;
          head=end;
     }
     return head;
}

//Optimal solution
T.C:-O(n)+O(n-(n%k)) -~ O(n)
S.C:-O(1)
Node *rotate(Node *head, int k) {
     if(head==NULL || head->next==NULL) return head;
     Node* temp=head;
     int len=1;
     //measuring the length
     while(temp->next!=NULL){
          len++;
          temp=temp->next;
     }
     //connecting the last node to head
     temp->next=head;
     //when k is more than length
     k=k%len;
     //find the node where we need to break the list
     int end=len-k;
     while(end--){
          temp=temp->next;
     }
     head=temp->next;
     temp->next=NULL;
     return head;
}
