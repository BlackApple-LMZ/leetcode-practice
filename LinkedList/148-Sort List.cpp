ListNode* sortList(ListNode* head) {
 if (head == NULL || head->next == NULL)  return head;

 //快慢指针找到中间节点
 ListNode *fast = head, *slow = head;
 while (fast->next != NULL && fast->next->next != NULL)
 {
   fast = fast->next->next;
   slow = slow->next;
 }
 //断开
 fast = slow;
 slow = slow->next;
 fast->next = NULL;

 ListNode *l1 = sortList(head); //前半段排序
 ListNode *l2 = sortList(slow); //后半段排序
 return mergeTwoLists(l1, l2);
}

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
