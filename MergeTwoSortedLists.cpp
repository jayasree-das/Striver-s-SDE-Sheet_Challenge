//Using extra space
T.C:-O(n+m)
S.C:-O(n+m)
#include <bits/stdc++.h>
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL) return second;
    if(second==NULL) return first;

    //creating a new list
    Node<int> *head=NULL;
    Node<int> *tail=NULL;

    if(first->data < second->data){
        head=first;
        tail=first;
        first=first->next;
    }
    else{
        head=second;
        tail=second;
        second=second->next;
    }
    while(first!=NULL && second!=NULL){
        if(first->data < second->data){
            tail->next=first;
            tail=first;
            first=first->next;
        }
        else{
            tail->next=second;
            tail=second;
            second=second->next;
        }
    }
    if(first!=NULL){
        tail->next=first;
    }
    if(second!=NULL){
        tail->next=second;
    }
    return head;
}


//Without using extra space
T.C:-O(n+m)
S.C:-O(1)
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL) return second;
    if(second==NULL) return first;
    //pointing first to smaller and second to greater
    if(first->data > second->data) swap(first,second);
    
    Node<int> *res=first;
    while(first!=NULL && second!=NULL){
        Node<int> *temp=NULL;
        while(first!=NULL && first->data<=second->data){
            temp=first;//storing the last sorted data
            first=first->next;
        }
        //when first becomes greater than second
        //point the temp next to second
        temp->next=second;
        //put first to smaller and second to larger
        swap(first,second);
    } 
    return res;  
}
