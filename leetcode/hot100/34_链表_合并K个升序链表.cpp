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
//思路，先实现vector的去空，即通过一个迭代器如果该位置是空，就将其去除，之后判断容器是否为空，如果是，返回nullptr
// 之后通过循环使链表相连，形成一条链表
// 然后使用归并排序对其进行排序
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        //删除空的节点
        for(auto iter = lists.begin(); iter < lists.end();)
        {
            //先将链表vector去除空节点
            if(*iter != nullptr) 
            {
                iter++;
                continue;
            }
            iter = lists.erase(iter);
        }
        if(lists.empty()) return nullptr;

        //想使用递归进行排序
        //1.合并该数组
        int n = lists.size();
        ListNode* p = lists.front();
        for(int i = 0;i < n - 1;i++)
        {
            while(p->next!=nullptr)
            {
                p = p->next;
            }
            p->next = lists.at(i+1);
        }
        //当循环结束时，头节点的指针指向了所有的元素
        p = lists.front();
        ListNode* res = sortLists(p);
        return res;
    }

private:
    ListNode* sortLists(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* middle = middleLists(head);
        ListNode* left = sortLists(head);
        ListNode* right = sortLists(middle);
        //创建一个头节点前的虚拟节点
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;

        while(left!=nullptr && right!=nullptr)
        {
            if(left->val < right->val)
            {
                dummy->next = left;
                left = left->next;
            }
            else
            {
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
        }
        dummy->next =  left!=nullptr ? left : right;
        return res->next;
    
    }
    ListNode* middleLists(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }
};
//结论：通过

//2.官方题解
//优先队列，如果当前list的链表不为空，将其添加到优先队列中，之后，从优先队列中取出数，如果这个数的下一个指针不为空，就在添加到优先队列中
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // 使用优先队列,自定义优先队列的2种比较方式
        // 方式1.自定义比较函数lamada
        auto cmp = [](const ListNode* a,const ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> que(cmp);
        for(auto iter = lists.begin(); iter != lists.end(); iter++)
        {
            if(*iter!=nullptr) 
            {
                que.push(*iter);
            }
            
        }
        //定义一个虚拟的头节点
        ListNode* head = new ListNode(-1); 
        ListNode* p = head;
        while(!que.empty())
        {
            p->next = que.top();
            que.pop();
            p = p->next;
            if(p->next!=nullptr)
            {
                que.push(p->next);
            }
        }
        return head->next;
    }
};
//结论：通过

//3.优先队列的第二种比较方式
struct Compare
{
    bool operator()(const ListNode* cur,const ListNode* other) const
    {
        return cur->val > other->val;
    }
};

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // 使用优先队列,自定义优先队列的2种比较方式
        //2.自定义结构体比较函数，重载()符
        priority_queue<ListNode*, vector<ListNode*>, Compare> que;
        for(auto iter = lists.begin(); iter != lists.end(); iter++)
        {
            if(*iter!=nullptr) 
            {
                que.push(*iter);
            }
            
        }
        //定义一个虚拟的头节点
        ListNode* head = new ListNode(-1); 
        ListNode* p = head;
        while(!que.empty())
        {
            p->next = que.top();
            que.pop();
            p = p->next;
            if(p->next!=nullptr)
            {
                que.push(p->next);
            }
        }
        return head->next;
    }
};


