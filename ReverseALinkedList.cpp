//Brute Force Approach
T.C:-O(n2)
S.C:-O(n) //recursion stack space
#include <bits/stdc++.h>
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL || head->next==NULL) return head;
    LinkedListNode<int> *rest=reverseLinkedList(head->next);
    LinkedListNode<int> *temp=reverseHead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    head->next=NULL;
    temp->next=head;
    return reverseHead;
}


//Better solution
T.C:-O(n)
S.C:-O(n)
#include <bits/stdc++.h>
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    stack<LinkedListNode<int>*>s;
    while(head!=NULL){
        s.push(head);
        head=head->next;
    }
    if(s.size()!=0){
        head=s.top();
    }
    while(!s.empty()){
        LinkedListNode<int> *curr=s.top();
        s.pop();

        if(s.size()==0){
            curr->next=NULL;
        }
        else{
            curr->next=s.top();
        }
    }
    return head;
}


//Optimal solution
T.C:-O(n)
S.C:-O(1)
#include <bits/stdc++.h>
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{ 
if(head==NULL) return NULL;
    LinkedListNode<int> *dummy=NULL;
    while(head!=NULL){
        LinkedListNode<int> *next=head->next;
        head->next=dummy;
        dummy=head;
        head=next;
    }
    return dummy;
}
