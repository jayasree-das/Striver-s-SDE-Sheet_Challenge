//Brute force approach
T.C:-O(n2)
S.C:-O(1)
bool detectCycle(Node *head)
{
	Node *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
        Node *temp2=head;
        int d=len;
        while(d--){
            if(temp==temp2) return true;
            temp2=temp2->next;
        }
    }
    return false;
}

//Better Solution
T.C:-O(n)
S.C:-O(n)
#include<bits/stdc++.h>
bool detectCycle(Node *head)
{
    //keep track of the nodes present
    unordered_set<Node*>seen;
    while(head!=NULL){
        if(seen.count(head)){
            return true;
        }
        else{
            seen.insert(head);
        }
        head=head->next;
    }
    return false;
}


//optimal solution
T.C:-O(n)
S.C:-O(1)
bool detectCycle(Node *head)
{
	Node *slow=head,*fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
