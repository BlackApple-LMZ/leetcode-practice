ListNode* removeNthFromEnd1(ListNode* head, int n) {
    int length(0);
    ListNode root(0);
    root.next = head;
    ListNode* temp = head;
    while(temp){
        length++;
        temp = temp->next;
    }
    temp = &root;
    length -= n;
    while(length){
        length--;
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return root.next;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode root(0);
    root.next = head;

    ListNode* slow = &root;
    ListNode* fast = &root;
    while(n+1){
        n--;
        fast = fast->next;
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return root.next;
} 
