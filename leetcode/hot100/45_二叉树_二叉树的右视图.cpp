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


//2.二叉树的题一定有递归的解法
//官方题解
class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        dfs(root,0);
        return res;
    }
    void dfs(TreeNode* root, int depth)
    {
        // 思路是先调用右子树，如果右子树不存在才会调用左子树，这时就需要设计一个size变量
        // 用来记录是否他是最右边的元素，如果右边有元素，push进去之后当前容器元素个数等于深度

        if(root == nullptr) return;
        if(depth == res.size())
        {
            //说明首次遇到这个深度
            res.push_back(root->val);
        }
        //先递归的调用右子树
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);

    }
private:
    vector<int> res;
};
//结论：通过
