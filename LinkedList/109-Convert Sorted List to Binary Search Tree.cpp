TreeNode* sortedListToBST(ListNode* head) {
    if(!head){
        return NULL;
    }
    if(!head->next){
        TreeNode* root = new TreeNode(head->val);
        return root;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    ListNode* pre;
    while(fast && fast->next){
        pre = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    slow = slow->next;
    pre->next = NULL;

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow);
    return root;
}
