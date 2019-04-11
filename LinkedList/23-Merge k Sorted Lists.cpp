ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode root = ListNode(0); //ListNode root(0); 这种写法更简单
    ListNode* proot = &root;
    while(l1 && l2){
        if(l1->val <= l2->val){
            proot->next = l1;
            l1 = l1->next;
        }
        else{
            proot->next = l2;
            l2 = l2->next;
        }
        proot = proot->next;
    }
    if(l1)
        proot->next = l1;
    else
        proot->next = l2;
    return root.next;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0)
        return NULL;
    if(lists.size() == 1)
        return lists[0];
    if(lists.size() == 2){
        return mergeTwoLists(lists[0], lists[1]);
    }
    int mid = lists.size()/2;
    vector<ListNode*> vec1, vec2;
    for(int i=0; i<mid; i++){
        vec1.push_back(lists[i]);
    }
    for(int i=mid; i<lists.size(); i++){
        vec2.push_back(lists[i]);
    }
    ListNode* l1 = mergeKLists(vec1);
    ListNode* l2 = mergeKLists(vec2);
    return mergeTwoLists(l1, l2);
}
