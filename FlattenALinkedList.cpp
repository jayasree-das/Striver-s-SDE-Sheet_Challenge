//Brute Force(Taking extra space)
T.C:-O(n*k)+O((n*k)log(n*k))
S.C:-O(n*k)
#include <bits/stdc++.h>
Node* flattenLinkedList(Node* head) 
{
	vector<int>ans;
	while(head!=NULL){
		ans.push_back(head->data);
		Node *temp=head;
		while(temp->child!=NULL){
			ans.push_back(temp->child->data);
			temp=temp->child;
		}
		head=head->next;
	}
	sort(ans.begin(),ans.end());
		Node* root=NULL;
		Node *tail=NULL;
		for(int i=0;i<ans.size();++i){
			Node* newNode=new Node(ans[i]);
			if(root==NULL){
				root=newNode;
			}
			else{
				tail->child=newNode;
			}
			tail=newNode;
		}
		return root;
}


//Recursive
T.C:-O(n)
S.C:-O(1)
Node *merge(Node *a,Node *b){
	if(a==NULL) return b;
	if(b==NULL) return a;
	Node *temp=new Node(0);
	Node *res=temp;
	while(a!=NULL && b!=NULL){
		if(a->data < b->data){
			temp->child=a;
			a=a->child;
			temp=temp->child;
		}
		else{
			temp->child=b;
			b=b->child;
			temp=temp->child;
		}
	}
	if(a) temp->child=a;
	else temp->child=b;
	return res->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next==NULL) return head;
	Node *L2=flattenLinkedList(head->next);
	head->next=NULL;
	Node *newHead=merge(head,L2);
	return newHead;
}
