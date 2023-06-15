Constant Time Complexity
T.C:-O(1)
S.C:-O(1)
void deleteNode(LinkedListNode<int> * node) {
    LinkedListNode<int> *temp=node->next;
    node->data=temp->data;
    node->next=temp->next;
    delete temp;
}
