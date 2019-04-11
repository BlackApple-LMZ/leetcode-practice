//2. 链表表示的两个数求和 
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) 
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807
//
struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{ 
    ListNode *p=new ListNode(-1); 
    ListNode *q=p; 
    int carry=0; 
    while(l1||l2) { 
        int val1= l1?l1->val:0;//为空时做加法的位数为0 
        int val2= l2?l2->val:0; 
        int val3=val1+val2+carry; 
        if(val3>=10) { 
            val3=val3-10; 
            carry=1; 
        } 
        else 
            carry=0; 
        q->next=new ListNode(val3);//创建新节点 
        q=q->next; 
        l1=l1?l1->next:l1; 
        l2=l2?l2->next:l2;//当l1和l2为null时不取其next指针，一直让其保持空的状态 
    } 
    if(carry==1)//考虑最高位进位的情况 
        q->next=new ListNode(1); 
    return p->next; 
}
