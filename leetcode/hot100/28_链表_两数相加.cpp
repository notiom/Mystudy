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
//思路:依次将p1链 + p2链，有进位就让下一位的值初始化为1，如果没有进位，就要判断下一个的两个next指针是否同时为0，如果是，下一个直接为nullptr，如果不是，那么下一个直接为1
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* res = new ListNode(0,nullptr);
        ListNode* currentSum = res;

        while(1)
        {
            if(p1 == nullptr && p2 == nullptr)
            {
                break;
            }
            else if(p1 == nullptr)
            {
                currentSum->val += p2->val;
                if(currentSum->val >= 10)
                {
                    currentSum->val -= 10;
                    currentSum->next = new ListNode(1,nullptr);
                }
                else
                {
                    if(p2->next == nullptr) 
                    {
                        currentSum->next = nullptr;
                        break;
                    }
                    currentSum->next = new ListNode(0,nullptr);
                }
                currentSum = currentSum->next;
                p2 = p2->next;
            }
            else if(p2 == nullptr)
            {
                currentSum->val += p1->val;
                if(currentSum->val >= 10)
                {
                    currentSum->val -= 10;
                    currentSum->next = new ListNode(1,nullptr);
                }
                else
                {
                    if(p1->next == nullptr) 
                    {
                        currentSum->next = nullptr;
                        break;
                    }
                    currentSum->next = new ListNode(0,nullptr);
                }
                currentSum = currentSum->next;
                p1 = p1->next;
            }
            else
            {

                currentSum->val += p1->val + p2->val;
                if(currentSum->val >= 10)
                {
                    currentSum->val -= 10;
                    currentSum->next = new ListNode(1,nullptr);
                }
                else
                {
                    if(p1->next == nullptr && p2->next == nullptr) 
                    {
                        currentSum->next = nullptr;
                        break;
                    }
                    currentSum->next = new ListNode(0,nullptr);
                }
                currentSum = currentSum->next;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return res;
    }
};
//结论：有一点点屎山代码仍然有改进空间。

//2.结合题解改进
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
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* res = new ListNode(0,nullptr);
        ListNode* currentSum = res;

        while(p1!=nullptr || p2!=nullptr)
        {
            int x = p1 == nullptr? 0 : p1->val;
            int y = p2 == nullptr? 0 : p2->val;
            currentSum->val += x + y;

            if(currentSum->val >= 10)
            {
                currentSum->val -= 10;
                currentSum->next = new ListNode(1,nullptr);
            }
            else
            {
                
                if((!p1 || !p1->next) && (!p2 || !p2->next)) 
                {
                    currentSum->next = nullptr;
                    break;
                }
                currentSum->next = new ListNode(0,nullptr);
            }
            currentSum = currentSum->next;

            if(p1!=nullptr) p1 = p1->next;
            if(p2!=nullptr) p2 = p2->next;
        }
        return res;
    }
};

//3.递归
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        return add(l1, l2, 0);
    }

    /**
        返回两个链表相加的头部
     */
private:
    ListNode* add(ListNode* l1, ListNode* l2, int bit) 
    {
        if (l1 == nullptr && l2 == nullptr && bit == 0) 
        {
            return nullptr;
        }
        int val = bit;
        if (l1 != nullptr) 
        {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) 
        {
            val += l2->val;
            l2 = l2->next;
        }
        ListNode* node = new ListNode(val % 10);
        node->next = add(l1, l2, val / 10);
        return node;
    }
};
//结论：链表递归很方便

//4. 11.4号新递归方案
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        return addTwoNumbersHelper(l1,l2,0);
    }

    ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2,int flag)
    {
        // 除了两个链子之外,还需要传入是否进位
        // 使用链子1当作最后返回的链子
        if(!l1 && !l2 )
        {
            return flag == 1 ? new ListNode(1) : nullptr;
        }

        if(!l1)
        {
            // 如果l1的长度不如l2
            // 给l1补长度
            l1 = new ListNode(0);
        }

        if(!l2)
        {
            l2 = new ListNode(0);
        }

        if(l1->val + l2->val + flag >= 10)
        {
            l1->val = l1->val + l2->val + flag - 10;
            // 要进位
            l1->next = addTwoNumbersHelper(l1->next,l2->next,1);
            return l1;
        }
        l1->val = l1->val + l2->val + flag;
        // 不进位
        l1->next = addTwoNumbersHelper(l1->next,l2->next,0);
        return l1;
    }
};
