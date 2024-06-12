/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//1.我自己的解

//层序遍历，使用一个队列，当下一次进入循环时，记录当前队列的大小，并将遍历到的元素依次push进vector，当本层结束时，再将vector<int> push
// 进结果容器中
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {   
        //使用队列进行层序遍历
        if(root == nullptr) return vector<vector<int>>();
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res; //定义输出结果
        while(!que.empty())
        {
            //当队列不为空时
            int S_size = que.size();
            //当前层的vector
            vector<int> ans;
            while(S_size > 0)
            {
                TreeNode* node = que.front();
                que.pop();
                ans.push_back(node->val);
                if(node->left != nullptr)
                {
                    que.push(node->left);
                }
                if(node->right != nullptr)
                {
                    que.push(node->right);
                }
                S_size--;
            }
            res.push_back(ans);
        }
    return res;
    }
};
//结论：通过，思考过递归的思路，但是觉得不可行

//2.官方题解
