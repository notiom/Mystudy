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

// 1.我自己的解
// 使用一个vector存放所有的元素，并对部分翻转，最后再将链表相连接即可。
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // 每k个节点进行颠倒顺序
        // 初始思路为利用k个循环将k个元素交换
        ListNode* p = new ListNode(0,head);
        int count = 0;
        vector<ListNode*> node;
        while(p->next!=nullptr)
        {
            // 计算链表长度
            p = p->next;
            node.push_back(p);
            count++;
        }
        int W_size = count / k; // 最外层大循环的循环次数
        for(int i = 0;i < W_size;i++)
        {
            // 将vector中的元素调整为所需要的元素
            reverse(node.begin() + (i * k), node.begin() + (i * k) + k);
        }

        // 连接链表即可
        p = new ListNode(0);
        ListNode* res = p;
        for(int i = 0;i < count;i++)
        {
            p->next = node[i];
            p = p->next;
        }
        p->next = nullptr;
        return res->next;
    }
};
// 结论:通过 时间复杂度 o(n) 空间复杂度 o(n).

// 2.尝试递归
// 靠自己写出了递归函数
class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // 使用递归函数
        // 先判断当前链子是否可以数出k的长度
        ListNode* tail = head;
        int count = k;
        while(tail!=nullptr)
        {
            tail = tail->next;
            if(--count <= 0) break; //说明当前链子的长度够长
        }

        if(count > 0) //返回原来的链表即可 
        return head;

        else
        {
            // 反转前k个元素
            ListNode* pre = nullptr;
            ListNode* cur = head;
            ListNode* tail = new ListNode(0);
            for(int i = 0;i < k;i++)
            {
                ListNode* nextnode = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nextnode;
                if(i == 0) tail = pre;
            }
            tail->next = reverseKGroup(cur,k);
            return pre;
        }
    }
};
// 结论:通过 时间复杂度和空间复杂度都是o(n).
