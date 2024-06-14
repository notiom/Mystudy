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
//广度优先遍历层序遍历
class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        //层序遍历
        vector<int> res;
        queue<TreeNode*> que;
        if(root == nullptr) return res;
        que.push(root);
        while(!que.empty())
        {
            int S_size = que.size();
            for(int i = 0;i < S_size;i++)
            {
                if(i == 0)
                {
                    //当第一次进入这个队列时，最后一个元素就是本层的最后一个元素
                    res.push_back(que.back()->val);
                }
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left != nullptr)
                {
                    que.push(temp->left);
                }
                if(temp->right != nullptr)
                {
                    que.push(temp->right);
                }
            }
        }
        return res;

    }
};
//结论：通过
