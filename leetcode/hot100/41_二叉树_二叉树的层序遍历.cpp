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

//递归，利用递归深度优先遍历的性质，但是递归的加入层级元素，设置了一个index的变量,将其添加到index索引即所在层的索引然后递归的加入元素

class Solution 
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) 
    {
        if (root == NULL) 
        {
            return std::vector<std::vector<int>>();
        }

        // 用来存放最终结果
        std::vector<std::vector<int>> res;
        dfs(1, root, res);
        return res;
    }

    void dfs(int index, TreeNode* root, std::vector<std::vector<int>>& res) 
    {
        // 假设res是[ [1],[2,3] ]， index是3，就再插入一个空vector放到res中
        if (res.size() < index) 
        {
            res.push_back(std::vector<int>());
        }
        // 将当前节点的值加入到res中，index代表当前层，假设index是3，节点值是99
        // res是[ [1],[2,3] [4] ]，加入后res就变为 [ [1],[2,3] [4,99] ]
        res[index - 1].push_back(root->val);

        // 递归的处理左子树，右子树，同时将层数index+1
        if (root->left != NULL) 
        {
            dfs(index + 1, root->left, res);
        }
        if (root->right != NULL) 
        {
            dfs(index + 1, root->right, res);
        }
    }
};
//结论：这个使用深度优先遍历的方式实现了广度优先遍历
//思考，如果只想将其加入一维容器中，就需要将这个二维容器合并成一维
