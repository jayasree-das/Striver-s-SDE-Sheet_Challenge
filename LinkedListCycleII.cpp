//Brute Force
T.C:-O(n)
S.C:-O(n)
Node *firstNode(Node *head)
{
    unordered_set<Node *>s;
    Node* temp=head;
    while(temp!=NULL){
        if(s.count(temp)) return temp;
        s.insert(temp);
        temp=temp->next;
    }
    return NULL;
}

//optimal solution
T.C:-O(n)
S.C:-O(1)
Node *firstNode(Node *head)
{
    if(head==NULL || head->next==NULL) return NULL;
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
}
