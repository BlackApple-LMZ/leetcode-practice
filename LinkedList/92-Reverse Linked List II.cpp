ListNode* reverseBetween(ListNode* head, int m, int n) {
    int length = n-m+1;
    ListNode* node = new ListNode(0);
    node->next = head;
    ListNode* pre(node);
    while(head && m-1){
        pre = head;
        head = head->next;
        m--;
    }
    ListNode* tail(head);
    ListNode* newHead(NULL);
    while(head && length){
        ListNode* temp = head->next;
        head->next = newHead;
        newHead = head;
        head = temp;
        length--;
    }
    pre->next = newHead;
    tail->next = head;
    return node->next;
}
