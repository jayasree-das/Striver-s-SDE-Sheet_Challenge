//Recursion
T.C:-O(n) where n=length of linked list
S.C:-O(n/k) where k is the size of array
Node *reverseKElements(Node *head,int n,int b[],int ind){
	if(head==NULL || ind>=n) return head;
	int k=b[ind];
	if(k==0) return reverseKElements(head, n, b, ind+1);
	
	Node *curr=head,*prev=NULL,*nxt=NULL;
	int cnt=0;
	while(curr!=NULL && cnt<k){
		nxt=curr->next;
		cnt++;
		curr->next=prev;
		prev=curr;
		curr=nxt;
	}
	head->next=reverseKElements(nxt,n,b,ind+1);
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	if(head==NULL) return head;
	head=reverseKElements(head,n,b,0);
	return head;
}


//iterative solution (space optimization)
T.C:-O(n)
S.C:-O(1)
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	if(head==NULL) return NULL;
	int ind=0;
	Node *prev=NULL,*curr=head,*nxt=NULL;
	Node *join=NULL,*tail=NULL;
	bool isHeadUpdated=false;
	while(ind<n && curr!=NULL){
		int k=b[ind];
		if(k==0){
			ind++;
			continue;
		}
		join=curr;
		prev=NULL;
		while(curr!=NULL && k--){
			nxt=curr->next;
			curr->next=prev;
			prev=curr;
			curr=nxt;
		}
		if(isHeadUpdated==false){
			head=prev;
			isHeadUpdated=true;
		}
		if(tail!=NULL){
			tail->next=prev;
		}
		tail=join;
		ind++;
	}
	if(tail!=NULL){
		tail->next=curr;
	}
	return head;
}
