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
//1.自己的解，合并列表只需要判读这两个链表的val谁大即可，因为题目已经给出严格单调不减了
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* res = new ListNode();
        ListNode* k = res;
        ListNode*p = list1; //代替1
        ListNode*q = list2; //代替2
        while(1)
        {
            if(p != nullptr && q != nullptr)
            { 
                if(p->val <= q->val)
                    {
                        //将等于的情况视为p链增加
                        k->next = p;
                        k = k->next;
                        p = p->next;
                    }
                    else
                    {
                        k->next = q;
                        k = k->next;
                        q = q->next;
                    }
            }
            else if(p == nullptr && q != nullptr)
            {
                k->next = q;
                k = k->next;
                q = q->next;
            }
            else if(p != nullptr && q == nullptr)
            {
                k->next = p;
                k = k->next;
                p = p->next;
            }
            else break;
        }
        return res->next;
    }
};
//结论：通过

//2.官方题解
