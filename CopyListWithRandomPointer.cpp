//Brute Force Approach
T.C:-O(2*n) -~ O(n)
S.C:-O(n)
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode<int> *,LinkedListNode<int> *>mp;
    LinkedListNode<int>  *temp=head;
    while(temp!=NULL){
        //creating deep copy of every node
        LinkedListNode<int> *newNode=new LinkedListNode<int> (temp->data);
        mp[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        //finding the deep copy of the node
        LinkedListNode<int> *node=mp[temp];
        //creating the random and next pointers
        node->next=(temp->next != NULL) ? mp[temp->next] : NULL;
        node->random = (temp->random != NULL) ? mp[temp->random]: NULL;
        temp=temp->next;
    }
    return mp[head];
}


//Better solution
T.C:-O(3*n)-~O(n)
S.C:-O(1)
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    //creating list with deep copies next to original nodes
    LinkedListNode<int>* curr=head;
    while(curr){
        LinkedListNode<int> *newNode= new LinkedListNode<int>(curr->data);
        LinkedListNode<int> *nxt=curr->next;
        curr->next=newNode;
        newNode->next=nxt;
        curr=nxt;
    }

    //marking the random pointer of deep copies
    curr=head;
    while(curr){
        if(curr->next!=NULL){
            curr->next->random=curr->random != NULL ? curr->random->next : NULL;
        }
        curr=curr->next->next;
    }

    //separating the copied list
    curr=head;
    LinkedListNode<int> *dummy=new LinkedListNode<int>(0);
    LinkedListNode<int> *tail=dummy;
    while(curr){
        tail->next=curr->next;
        tail=tail->next;
        curr->next=tail->next;
        curr=curr->next;
    }
    return dummy->next;
}
