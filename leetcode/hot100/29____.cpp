/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//1.我自己的解
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //需要先找到倒数第n个结点
        //先控制其中一个节点，出发走n个单位，之后在令第二个节点出发，当第一个节点到达结尾时，第二个节点就位于倒数第n个位置
        //假设链长为a 有a = n + b  倒数第n个就是b个位置

        ListNode* p = head;
        ListNode* q = head;

        for(int i = 0; i < n; i++)
        {
            q = q->next;
        }
        // 如果 q 指向空，则说明要删除的是头节点
        if (!q) 
        {
            head = head->next;
            delete p;
            return head;
        }
        while(q->next)
        {
            p = p->next;
            q = q->next;
        }
        // 1 2 3 4 5此时p指向3
        p->next = p->next->next;
        return head;
    }
};
//2.官方题解栈
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //栈的思想
        stack<ListNode*> stc;
        ListNode* dummy = new ListNode(0,head);
        ListNode* p = dummy;
        while(p!=nullptr)
        {
            stc.push(p);
            p = p->next;
        }
        //执行出栈n次，由先进后出知道第n个就是进去的倒数n
        for(int i = 0; i < n; i++)
        {
            stc.pop();
        }
        //当前要删除节点的前驱节点
        ListNode* pre = stc.top();
        pre->next = pre->next->next;
        return dummy->next;
        //如果要删除头节点

        return head;
    }
};

//3.神之一手，递归
class Solution 
{
    int count = 0;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //递归
        if(head == nullptr)
        {
            return nullptr;
        }
        head->next = removeNthFromEnd(head->next,n);
        count++;
        return count==n ? head->next : head;
    }
};
//结论：通过

