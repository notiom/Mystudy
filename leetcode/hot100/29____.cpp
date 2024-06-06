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
