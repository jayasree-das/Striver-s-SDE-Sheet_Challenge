//Brute Force
T.C:-O(m*n)
S.C:-O(1)
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    while(secondHead!=NULL){
        Node *temp=firstHead;
        while(temp!=NULL){
            if(temp==secondHead) return secondHead;
            temp=temp->next;
        }
        secondHead=secondHead->next;
    }
    return NULL;
}

//better solution
T.C:-O(m+n)
S.C:-O(m)
#include<bits/stdc++.h>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node *temp=firstHead;
    unordered_set<Node*>s;
    while(temp!=NULL){
        s.insert(temp);
        temp=temp->next;
    }
    Node* temp2=secondHead;
    while(temp2!=NULL){
        if(s.find(temp2)!=s.end()){
            return temp2;
        }
        temp2=temp2->next;
    }
    return NULL;
}


//Optimal Approach
T.C:-O(max(m,n))+O(abs(l1-l2))
S.C:-O(1)
int length(Node* head){
    int len=0;
    Node* tmp=head;
    while(tmp!=NULL){
        len++;
        tmp=tmp->next;
    }
    return len;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int diff=0;
    Node* temp=firstHead;
    Node* temp2=secondHead;
    int l1=length(firstHead),l2=length(secondHead);
    if(l1>l2){
        diff=l1-l2;
        while(diff--){
            temp=temp->next;
        }
    }
    else{
        diff=l2-l1;
        while(diff--){
            temp2=temp2->next;
        }
    }
    while(temp!=temp2){
        temp=temp->next;
        temp2=temp2->next;
    }
    return temp;
}


//Optimal Approach2
T.C:-O(2*max(m,n))
S.C:-O(1)
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* d1=firstHead;
    Node* d2=secondHead;
    while(d1!=d2){
        d1= d1==NULL ? secondHead : d1->next;
        d2= d2==NULL ? firstHead : d2->next;
    }
    return d1;
}
