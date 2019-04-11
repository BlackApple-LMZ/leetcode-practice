ListNode* swapPairs(ListNode* head) {
    ListNode* node = new ListNode(0);
    node->next = head;
    ListNode* pre = node;
    while(pre->next && pre->next->next){
        ListNode* cur = pre->next;
        ListNode* next = cur->next;

        pre->next = next;
        cur->next = next->next;
        next->next = cur;

        pre = cur;
    }
    return node->next;
}
