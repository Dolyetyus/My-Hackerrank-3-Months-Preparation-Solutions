SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
	SinglyLinkedListNode* insert = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* ret = head;
    
    if (head==nullptr) return insert;
    
    while (head->next!=nullptr){
        head=head->next;
    }
    
    head->next = insert;
    
    return ret;
}
