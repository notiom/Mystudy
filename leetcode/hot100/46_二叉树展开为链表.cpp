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
//使用一个队列保存前序遍历的结果，之后在选取一个新的节点去赋值root
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        //执行完后vector中存放了先序遍历的树
        dfs(root);
        ProcessList(root);
    }

    void dfs(TreeNode* root)
    {
        //使用先序遍历
        if(root == nullptr) return;

        this->res.push(root);
        dfs(root->left);
        dfs(root->right);
    }

    void ProcessList(TreeNode* root)
    {
       //这里要使用一个构造函数，使其右节点指向root或者指向空，因为队列中的第一个元素是root
        TreeNode* node = new TreeNode(-1,nullptr,nullptr);
        while(!this->res.empty())
        {
            node->left = nullptr;
            node->right = this->res.front();
            this->res.pop();
            node = node->right;
        }
    }

private:
    queue<TreeNode*> res;
};
