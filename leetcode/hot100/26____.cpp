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
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        // 快慢指针
        // fast = 2 * slow -> f = 2s
        // 又fast比slow多走n个环,设head到第一次交汇点p的距离为a,环长为b
        // f = s + nb -> f = 2nb&&s = nb
        // 此时使f归0，然后再使这两个指针同时走a,但是a未知，但是一定知道
        // a = nb + a 一定交汇
        if(!head) return nullptr;
        ListNode* fast = head; //定义第一个比较的原指针
        ListNode* slow = head; //定义下一个移动的指针
        while(fast->next!=nullptr && fast->next->next!= nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                fast = head;
                if(fast == slow) return fast;
                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                    if(fast == slow)
                    {
                        return fast;
                    }
                }
            }
        }
        return nullptr;
    }
};
//结论：有点屎山，可以将第一次等于之后跳出在判断
//3.官方改进版
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        // 快慢指针
        // fast = 2 * slow -> f = 2s
        // 又fast比slow多走n个环,设head到第一次交汇点p的距离为a,环长为b
        // f = s + nb -> f = 2nb&&s = nb
        // 此时使f归0，然后再使这两个指针同时走a,但是a未知，但是一定知道
        // a = nb + a 一定交汇
        if(!head) return nullptr;
        ListNode* fast = head; //定义第一个比较的原指针
        ListNode* slow = head; //定义下一个移动的指针
        while(1)
        {
            if(fast == nullptr || fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
               break;
            }
        }
        fast = head; //如果在上一个循环没有返回，那么说明一定是环
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
//结论：舒服
