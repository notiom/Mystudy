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
