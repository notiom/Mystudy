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

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        //尝试递归
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1; //不需要判断他们是否都为0的原因是，如果都为0，那么返回值也是nullptr      
        if(list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }    
        list2->next = mergeTwoLists(list1,list2->next);
        return list2;
    }
};
//结论：递归只需要管当前我应该怎样做就可以，即对于第一个工人，我只需要看当前的链子谁小，然后告诉下一个工人，谁应该排第一，体现在代码中的
// 就是如果链子1小那么将他排在第一个，之后再将第2 - n个工人的工作量接过来，直接返回list1，同理后续也这样，只需要关注当前工作
