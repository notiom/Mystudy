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
//结论：通过

//2.官方题解
//直接对二叉树进行变形
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        TreeNode* node = root;
        //当node指向null时说明所有交换已经完成
        while(node != nullptr)
        {
            //当node左子树为空时，直接考虑下一个节点
            if(node->left == nullptr) node = node->right;
            else
            {
                //找到node左子树的最右节点
                TreeNode* pre = node->left;
                while(pre->right!= nullptr)
                {
                    pre = pre->right;
                }
                //将原来的右子树接到左子树的最右边节点
                pre->right = node->right;
                //将左子树插入到右子树的地方
                node->right = node->left;
                node->left = nullptr;
                //考虑下一个节点
                node = node->right;
            }
        }
    }
};
//结论：很牛

//3.官方题解解法2
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        //使用先序遍历会造成当使1的right指向left时，right孩子丢失的问题
        //但题主完美的利用后序遍历
        //先遍历右孩子，这样之后在使其右跟节点指向的时候就不会出现孩子丢失的问题
        //使用pre全局变量存放上一个指针

        if(root == nullptr) return;
        //遍历顺序为6 5 4 3 2 1 
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
private:
    TreeNode* pre = nullptr;
};
//使用后序遍历完美的解决了孩子丢失的问题
