ListNode *detectCycle(ListNode *head) {
    ListNode* slow(head);
    ListNode* fast(head);
    ListNode* meet(NULL);
    while(fast){
        slow = slow->next;
        fast = fast->next;
        if(fast){
            fast = fast->next;
        }
        if(fast == slow){
            meet = fast;
            break;
        }
    }
    if(meet){
        while(true){
            if(meet == head)
                return meet;
            meet = meet->next;
            head = head->next;
        }
    }
    return NULL;
}
