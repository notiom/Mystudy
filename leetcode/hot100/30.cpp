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
//结论：通过，时间复杂度为o(n),空间复杂度为o(n),通过

//2.官方题解
//思路:递归，不需要在乎下一级做了什么，只需要在乎我函数的1.返回值2.调用函数做了什么3.终止条件即可
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
        {
            //当前值为null或者当前值的下一个为null
            return head;
        } 
        ListNode* post = head->next; //指向2
        head->next = swapPairs(post->next); //让1指向3之后交换的一大堆链子
        post->next = head;
        return post; //将执行交换完成后的post链子返回
    }
};
//结论:通过
