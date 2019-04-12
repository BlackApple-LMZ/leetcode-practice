struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int add(0);
    ListNode node(0);
    ListNode* temp = &node;
    while(l1 || l2){
        int x = l1?l1->val:0;
        int y = l2?l2->val:0;
        int sum = x + y + add;
        add = sum/10;

        temp->next = new ListNode(sum % 10);
        temp = temp->next;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if(add){
        temp->next = new ListNode(1);
    }
    return node.next;
}
