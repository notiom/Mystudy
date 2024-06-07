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
//思路:创建一个容器用来存放ListNode，并且判断该链表长度为奇数还是偶数，如果长度是奇数，需要让倒数第3个节点指向倒数第二个节点
//如果为偶数，只需要判断是i + 3 个元素是否存在，如果不存在，那么该元素调换顺序后只需要使调换后的right指向nullptr
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
        {
            //说明链表长度小于等于1
            return head;
        }
        vector<ListNode*> vec;
        ListNode*p = head;
        while(p!=nullptr)
        {
            vec.push_back(p);
            p = p->next;
        }
        ListNode* res = head->next;
        int n = vec.size();
        ListNode* q = head;
        if(n % 2 != 0) 
        {
            q = vec.at(n - 3);
        }
        for(int i = 0; i < n; i+=2)
        {
            ListNode* left = vec.at(i);
            ListNode* right = vec.at(i+1);
            right->next = left;
            if(i + 3 < n)
            {
                left->next = vec.at(i + 3);
            }

            else if(i + 2 == n - 1)
            {
                //处理奇数的情况
                q->next = vec.at(i + 2);
                vec.at(i + 2)->next = nullptr;
                break;
            }
            else if(i + 2 == n)
            {
                //处理偶数的情况
                left->next = nullptr;
                break;
            }
        }
    return res;
    }
};
