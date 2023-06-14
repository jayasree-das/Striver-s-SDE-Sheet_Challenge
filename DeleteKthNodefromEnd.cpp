//brute force(USING EXTRA SPACE)
T.C:-O(n)
S.C:-O(n)
Node* removeKthNode(Node* head, int K)
{
    vector<Node*>list;
    Node* temp=head;
    while(temp!=NULL){
        list.push_back(temp);
        temp=temp->next;
    }
    if(K==list.size()){
        Node* curr=head->next;
        head->next=NULL;
        delete head;
        head=curr;
    }
    else{
        list[list.size()-K-1]->next=list[list.size()-K]->next;
        delete(list[list.size()-K]);
    }
    return head;
}


//optimal Approach1
T.C:-O(n)
S.C:-O(1)
Node* removeKthNode(Node* head, int K)
{
    if(head==NULL || K==0) return head;
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    if(K==len){
        Node* next=head->next;
        head->next=NULL;
        delete head;
        head=next;
    }
    else{
        int cnt=0;
        temp=head;
        while(temp!=NULL){
            cnt++;
            if(len-K == cnt){
                temp->next=temp->next->next;
                break;
            }
            else{
                temp=temp->next;
            }
        }
    }
    return head;
}

//Optimal Approach2(Using SLOW FAST Pointer)
T.C:-O(n)
S.C:-O(1)
Node* removeKthNode(Node* head, int K)
{
    if(head==NULL || K==0) return head;
    Node* slow=head;
    Node* fast=head;
    for(int i=0;i<K;i++){
        if(fast->next==NULL){
            Node *next=head->next;
            head->next==NULL;
            head=next;
            return head;
        }
        else{
            fast=fast->next;
        }
    }
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return head;
}
