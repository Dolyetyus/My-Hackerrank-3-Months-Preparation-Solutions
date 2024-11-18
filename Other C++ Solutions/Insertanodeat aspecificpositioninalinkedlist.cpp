SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* insert = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* ret = llist;
    
    if (position==0){
        insert->next = llist;
        return insert;
    }
    
    position--;
    while (llist->next!=nullptr){
        if (position==0) break;
        llist=llist->next;
        position--;
    }
        
    SinglyLinkedListNode* temp = llist->next;
    llist->next = insert;
    insert->next = temp;
    
    return ret;
}
