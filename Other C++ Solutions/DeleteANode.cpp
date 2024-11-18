SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    SinglyLinkedListNode* ret = llist;
    
    if (position==0){
        return llist->next;
    }
    
    position--;
    while (llist->next!=nullptr){
        if (position==0) break;
        llist=llist->next;
        position--;
    }
    
    llist->next = llist->next->next;
    
    return ret;
}
