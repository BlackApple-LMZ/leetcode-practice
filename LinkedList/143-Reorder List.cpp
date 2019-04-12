void reorderList(ListNode* head) {
    if(!head || !head->next) return;
    ListNode *slow = head, *fast = head, *p=head, *q=head;
    while(fast->next && fast->next->next)
        slow = slow->next, fast = fast->next->next;
    fast = slow->next, slow->next = NULL;
    p = fast, q = fast->next, fast->next = NULL;
    while(q)
    {
        auto tem = q->next;
        q->next = p;
        p = q, q = tem;
    }
    q = head;
    while(q && p)
    {
        auto tem1 = q->next, tem2 = p->next;
        p->next = q->next;
        q->next = p;
        q = tem1, p = tem2;
    }
}
