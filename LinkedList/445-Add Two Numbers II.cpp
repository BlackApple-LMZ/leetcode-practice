ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    stack<int> s1, s2;
    while(l1)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while(l2)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }
    ListNode* dummy = new ListNode(INT_MAX);
    ListNode* p = dummy;
    int carry = 0, curSum = 0;
    while(s1.size() || s2.size())
    {
        curSum = carry;
        if(s1.size())
        {
            curSum += s1.top();
            s1.pop();
        }    
        if(s2.size())
        {
            curSum += s2.top();
            s2.pop();
        }
        carry = curSum > 9? 1: 0;
        curSum %= 10;
        ListNode* temp = new ListNode(curSum);
        temp->next = dummy->next;
        dummy->next = temp;
    }
    if(carry)
    {
        ListNode* temp = new ListNode(1);
        temp->next = dummy->next;
        dummy->next = temp;
    }
    return dummy->next;
}
