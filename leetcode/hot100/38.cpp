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
//先将根节点放到一个队列中，计算当前层队列的长度S_size，再将子树翻转，将其已经翻转好的子树入队，当S_size == 0时，上一层结束，当总队列长度为0时，结束循环
//注意不能删除交换节点，因为拷贝并不是深拷贝
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == nullptr) return nullptr;
        stack<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int S_size = que.size();
            while(S_size > 0)
            {   
                //取出队列顶部的元素
                TreeNode* temp = que.top();
                que.pop();
                
                //交换左右数
                TreeNode* swapNode = nullptr;
                swapNode = temp->left;
                temp->left = temp->right;
                temp->right = swapNode;
                if(temp->left != nullptr)
                {
                    que.push(temp->left);
                }
                if(temp->right != nullptr)
                {
                    que.push(temp->right);
                }
                S_size--;
            }        
        }
        return root;
    }
};
//结论：通过

//2.官方题解
//递归交换
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        //1. 递归终止条件
        if(root == nullptr) return nullptr;

        //2.递归函数体
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        //递归执行
        //交换左子树
        invertTree(root->left);
        //交换右子树
        invertTree(root->right);
      	//函数返回时就表示当前这个节点，以及它的左右子树
		    //都已经交换完了
        return root;
    }
};

