//Brute Force(using extra space)
T.C:-O(2*n) _~ O(n)
S.C:-O(n)
bool isPalindrome(LinkedListNode<int> *head) {
    vector<int>v;
    LinkedListNode<int> *temp=head;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }
    int n=v.size();
    for(int i=0;i<n/2;i++){
        if(v[i]!=v[n-i-1]) return false;
    }
    return true;
}


//Optimal Solution(without extra space)
T.C:-O(n/2)+O(n/2)+O(n/2)
S.C:-O(1)
LinkedListNode<int> *reverse(LinkedListNode<int> *head){
    if(head==NULL) return NULL;
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *curr=head;
    LinkedListNode<int> *nxt=NULL;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL) return true;
    LinkedListNode<int> *slow=head,*fast=head;
    //finding middle element
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    //reverse the list starting from slow->next
    slow->next=reverse(slow->next);
    
    //now place the slow at the starting of reversed part
    //and place another dummy node at the head of list
    slow=slow->next;
    LinkedListNode<int> *temp=head;
    while(slow!=NULL){
        if(temp->data != slow->data) return false;
        slow=slow->next;
        temp=temp->next;
    }
    return true;
}
