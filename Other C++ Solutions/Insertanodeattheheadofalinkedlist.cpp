SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* insert = new SinglyLinkedListNode(data);
    insert->next = llist;
    
    return insert;
}
