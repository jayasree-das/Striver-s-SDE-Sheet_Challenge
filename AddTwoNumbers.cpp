//Using extra space
T.C:-O(max(m,n))
S.C:-O(max(m,n))
Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* dummy=new Node();
    Node* temp=dummy;
    int carry=0;
    while(num1!=NULL || num2!=NULL || carry){
        int sum=0;
        if(num1!=NULL){
            sum+=num1->data;
            num1=num1->next;
        }
        if(num2!=NULL){
            sum+=num2->data;
            num2=num2->next;
        }
        sum+=carry;
        carry=sum/10;

        Node* newNode=new Node(sum%10);
        temp->next=newNode;
        temp=temp->next;
    }
    return dummy->next;
}


//Without extra space
T.C:-O(max(m,n))
S.C:-O(1)
Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* n1=num1;
    Node* n2=num2;
    int sum=0,carry=0;
    Node* temp=NULL;
    while(n1!=NULL && n2!=NULL){
        sum=n1->data+n2->data+carry;
        n1->data=sum%10;
        carry=sum/10;
        temp=n1;
        n1=n1->next;
        n2=n2->next;
    }
    if(n1!=NULL || n2!=NULL){
        if(n2!=NULL){
            temp->next=n2;
        }
        n1=temp->next;
        while(n1!=NULL){
            sum=n1->data+carry;
            n1->data=sum%10;
            carry=sum/10;
            temp=n1;
            n1=n1->next;
        }
    }
    if(carry>0){
        temp->next=new Node(carry);
    }
    return num1;
}
