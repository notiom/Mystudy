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
