//1.思路
//保存当前遍历节点的前驱节点和后继节点，并将当前节点的下一个next指向pre
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        //1 -> 2 -> 3 -> 4 -> 5
        if(head == nullptr) return nullptr;
        //思路,将原先的next指针的指向指向pre
        ListNode* node = head;
        //寻找下一个节点的下一个节点
        ListNode* upper = node->next; //起始指向2
        while(upper!=nullptr)
        {
            ListNode* pre = node;
            if(pre == head)
            {
                pre->next = nullptr;
            }
            //寻找当前节点的下一个节点
            node = upper;  //2
            //寻找下一个节点的下一个节点
            upper = node->next;
            //现在开始重连指向
            node->next = pre;//2->1
            //但是node还是指向2此时
        }
        return node;
        
    }
};
//结论：通过，空间复杂度较低

//2.官方题解
//同上，我结合做了个小改动
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        //1 -> 2 -> 3 -> 4 -> 5
        if(head == nullptr) return nullptr;
        //思路,将原先的next指针的指向指向pre
        ListNode* node = head;
        //前驱节点
        ListNode* pre = head;
        //寻找下一个节点的下一个节点
        ListNode* upper = node->next; //起始指向2
        pre->next = nullptr;
        while(upper!=nullptr)
        {
            //寻找当前节点的下一个节点
            node = upper;  //2
            //寻找下一个节点的下一个节点
            upper = node->next;
            //现在开始重连指向
            node->next = pre;//2->1
            //但是node还是指向2此时
            //初始化pre
            pre = node;
        }
        return node;
        
    }
};
//结论：通过，时间降低

// 3.使用递归翻转链表
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        // 尝试使用递归翻转链表
        return reverseListHelper(head,nullptr);

    }

    ListNode* reverseListHelper(ListNode* head,ListNode* pre)
    {
        if(head == nullptr)
        {
            // 当最后一个元素为空时,就返回他的结果就好
            return pre;
        }
        ListNode* next = head->next;
        head->next = pre;
        return reverseListHelper(next,head);
    }
};
