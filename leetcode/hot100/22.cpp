//自己思考许久未懂题目是什么意思
//无思路
//1.官方题解
//走到尽头见不到你，于是走过你来时的路，等到相遇时才发现，你也走过我来时的路

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        // 本题定义两个头节点，当第一次到达nullptr节点时，切换到另一条路
        // 使A和B节点走过的路程一样，那么当都走过max(A,B)时若他们相遇，则该节点是交点
        // 否则当AheB第二次为nullptr时表示链子不相遇
		if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;

        while(nodeA != nodeB)
        {
            //该判断条件并不是判断值，而是判断是否是同一个节点，如果到达最后，没有找到，说明nullptr = nullptr
            //赋值操作
            nodeA = nodeA == nullptr? headB : nodeA->next;
            nodeB = nodeB == nullptr? headA : nodeB->next;
        }
        return nodeA;
    }
};
