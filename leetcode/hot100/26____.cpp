/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//1.自己的解，利用集合判断当前节点是否出现过，如果第一次发现s.count == 1，那么当前节点就是入口节点
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        set<ListNode*> s;
        ListNode* p = head;
        while(p != nullptr)
        {
            if(s.count(p))
            {
                return p;
            }
            s.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};
//结论：通过，但是要求空间复杂度为o(1)

//2.尝试快慢指针
