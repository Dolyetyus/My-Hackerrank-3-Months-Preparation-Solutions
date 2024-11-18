void reversePrint(SinglyLinkedListNode* llist) {
    vector<int> arr;
    while(llist!=nullptr){
        arr.push_back(llist->data);
        llist=llist->next;
    }
    
    for (int i = arr.size()-1; i>=0; i--){
        cout<<arr[i]<<endl;
    }
}
