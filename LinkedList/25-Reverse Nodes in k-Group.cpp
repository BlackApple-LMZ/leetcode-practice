ListNode* reverseKGroup(ListNode* head, int k) {
    int length(0);
    ListNode* temp = head;
    while(temp){
        length++;
        temp = temp->next;
    }
    ListNode* root = new ListNode(0);
    root->next = head;
    ListNode* pre = root;
    while(head){
        int num = k;
        ListNode* tail = head;
        ListNode* newHead(NULL);
        if(length >= k){
            while(num && head){
                ListNode* temp = head->next;
                head->next = newHead;
                newHead = head;
                head = temp;
                num--;
            }
        }
        else{
            cout<<length<<endl;
            break;
        }

        length -= k;
        tail->next = head;
        pre->next = newHead;
        pre = tail;
        cout<<length<<endl;
    }
    return root->next;
}
