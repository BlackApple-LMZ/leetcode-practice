ListNode* partition(ListNode* head, int x) {
    ListNode small(0);
    ListNode* psmall = &small;
    ListNode large(0);
    ListNode* plarge = &large;

    while(head){
        if(head->val < x){
            psmall->next = head;
            psmall = head;
        }
        else{
            plarge->next = head;
            plarge = head;
        }
        head = head->next;
    }
    psmall->next = large.next;
    plarge->next = NULL;
    return small.next;
}
