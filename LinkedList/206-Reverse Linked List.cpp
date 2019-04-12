ListNode* reverseList(ListNode* head) {
    ListNode* newHead(NULL);
    while(head){
        ListNode* temp = head->next;
        head->next = newHead;
        newHead = head;
        head = temp;
    }
    return newHead;
}
