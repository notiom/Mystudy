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
// 使用另一个容器构造排序算法，但是使用快速排序，如果在c++中想使用快速排序必须重载加号运算符如下
// 满足了题意的时间复杂度为o(nlogn),但是空间复杂度为o(n)

template<typename T> 
vector<T> operator+(const vector<T> &nums1,const vector<T> &nums2)
{
    vector<T> res = nums1;
    res.insert(res.end(),nums2.begin(),nums2.end());
    return res;
}
class Solution 
{
public:

    ListNode* sortList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
        return head;

        vector<ListNode*> vec;
        ListNode* p = head;
        while(p!=nullptr)
        {
            vec.push_back(p);
            p = p->next;
        }
        //对容器进行排序
        vector<ListNode*> sorted = sortVecList(vec,0,vec.size() - 1);
        ListNode* res = new ListNode(-1);
        p = sorted.at(0);
        res->next = p;
        int n = sorted.size();
        for(int i = 1; i < n; i++)
        {
            p->next = sorted.at(i);
            p = p->next;
        }
        p->next = nullptr;
        return res->next;
    }

    vector<ListNode*> sortVecList(vector<ListNode*> &nums,int start,int end)
    {
        if(nums.size() <= 1) return nums;
        int pointmiddle = start + end >> 1;
        vector<ListNode*> left;
        vector<ListNode*> right;
        vector<ListNode*> middle;
        for(int i = start; i <= end;i++)
        {
            //左右都是闭区间
            if(nums.at(i)->val < nums.at(pointmiddle)->val)
            {
                left.push_back(nums.at(i));
            }
            else if(nums.at(i)->val > nums.at(pointmiddle)->val)
            {
                right.push_back(nums.at(i));
            }
            else
            {
                middle.push_back(nums.at(i));
            }
        }
        return sortVecList(left,0,left.size() - 1) + middle + sortVecList(right,0,right.size() - 1);
    }
};
//结论：通过，并且使用重载加号运算符，重载加号运算符🪨必须写在类外才可以使用
//2.官方题解
//通过递归的思想分治，不需要增加空间复杂度
class Solution 
{
public:

    ListNode* sortList(ListNode* head) 
    {
        if(head ==nullptr || head->next ==nullptr) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast->next !=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow的下一级会将其分为两个,
        ListNode* temp = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(temp);
        ListNode* dummy = new ListNode(-1); //一直移动的指针
        ListNode* res = dummy; //输出的返回结果
        while(left!=nullptr && right!=nullptr)
        {
            if(left->val < right->val)
            {
                //左边小于右边
                dummy->next = left;
                left = left->next;
            }
            else
            {
                dummy->next = right;
                right = right->next;
            }
            //每次结束后都让dummy向右移动
            dummy = dummy->next;
        }
        //将剩余的链表接上
        dummy->next = left != nullptr ? left : right;
        return res->next;
    }
};
