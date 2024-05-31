//1.自己的思路一直无法判断当前的p q指针是在p指针在没有环时遇到的q还是在有环时遇到的

//2.官方题解
//官方思路：只要存在环，那么快指针总会追上慢指针，如果不存在环，当快指针到达nullptr时直接返回false

struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        //利用快慢指针必会相遇来判断是否存在环
        if(head==nullptr) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};
