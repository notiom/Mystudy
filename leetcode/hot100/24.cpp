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
//1.我的思路
// 利用容器将元素放到vector中，比较首尾元素是否相等，若不等，直接break
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        //思路：利用容器，将链表元素依次放到vector中
        vector<int> res;
        while(head!=nullptr)
        {
            res.push_back(head->val);
            head=head->next;
        }
        int right = res.size() - 1; //右指针
        int left = 0;
        while(left < right)
        {
            if(res.at(left)!=res.at(right))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
//结论：通过，但是时间复杂度和空间复杂度都是o(n),题目要求o(1)的空间复杂度
//2利用栈的思想，无需双指针
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        //思路：利用容器，将链表元素依次放到vector中
        stack<int> res;
        ListNode* p = head;
        while(p!=nullptr)
        {
            res.push(p->val);
            p=p->next;
        }
        while(head)
        {
            if(head->val != res.top())
            {
                return false;
            }
            head = head->next;
            res.pop();
        }
        return true;
    }
};
//结论时间复杂度o(n)和空间复杂度
o(n)									
	//3.递归比较最后一个和第一个，递归是从函数的最后一层逐层向上比较
class Solution {
    ListNode* frontPointer;
public:
    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) {
                return false;
            }
            if (currentNode->val != frontPointer->val) {
                return false;
            }
            //该循环只要有一个返回false程序会一直返回false直到结束
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
}；
	
//4.快慢指针
//思路，找到最中间的位置，将后半部分反转，之后再比较它们的值，但是我自己的思路无法将其链表复原
	class Solution {
    ListNode* frontPointer;
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head->next == nullptr) return true;
        ListNode* tail = head;
        ListNode* middle = head;
        //控制步数使middle恰好指向最中间
        while(tail->next != nullptr)
        {
            tail = tail->next;
            //这里要先进行判断以确保没有访问空内存
            if(tail->next!= nullptr)
            {
                tail = tail->next;
                middle = middle->next;
            }
        }
        tail = middle->next; //使用tail进行跌倒
        ListNode* p = head; //使其重新指向
        middle->next = reverseList(tail,nullptr);
        ListNode* q = middle->next; //1 2 ---1--- 2
        while(q!= nullptr)
        {
            if(p->val != q->val)
            {
                return false;
            }
            p = p->next;
            q = q->next;
        }    
        return true;
    }
private:
    ListNode* reverseList(ListNode* start,ListNode* end)
    {
        ListNode* pre = start;
        ListNode* cur = start->next;
        pre->next = end;
        while(cur!= end)
        {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
//结论：实现空间复杂度为o(1).但是未复原原链表
	
//5.官方题解复原
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        if (head == nullptr) return true;
        ListNode* frontList = searchHalf(head); // 2 1
        ListNode* behindList = reverseList(frontList->next); //1 2
        //定义两个临时变动的链表
        ListNode* p = head;
        ListNode* q = behindList;
        while(q != nullptr)
        {
            if(p->val != q->val)
            {
                frontList->next = reverseList(behindList); // 2 2 1
                return false;
            }
            p = p->next;
            q = q->next;
        } 
        frontList->next = reverseList(behindList);
        return true;    
    }
private:
    ListNode* searchHalf(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            //快慢指针
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; //1 1 2 1 返回 1 2 1(要包含中心点，因为后续会用到这个的下一个节点)
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur!= nullptr)
        {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre; //返回反转的链表
    }
};
//结论：一个存放前半段链表，一个存放后半段链表，之后只需要反转后半段链表就行。
