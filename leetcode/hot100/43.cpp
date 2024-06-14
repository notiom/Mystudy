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
//我以为是要判断其是否是一颗二叉树，有效二叉树BST必须左边所有元素都小于上一个节点，右边所有元素必须大于
class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        //使用递归的方式判断是否是有效二叉树
        //递归终止条件
        if(root == nullptr)
        {
            return true;
        }
        bool leftflag = false;
        bool rightflag = false;
        if(root->left == nullptr)
        {
            leftflag = true;
        }
        if(root->right == nullptr)
        {
            rightflag = true;
        } 
        if((leftflag || root->left->val < root->val) && (rightflag || root->right->val > root->val))
        {
            //说明当前节点满足二叉树的条件
            return isValidBST(root->left) && isValidBST(root->right);   
        }
        else
        {
            return false;
        }

        return true;

    }
};
//结论：错误

//2.改进BST
class Solution 
{
public:

    bool isValidBST(TreeNode* root) 
    {
        return isValidHelper(root,nullptr,nullptr);
    }
    bool isValidHelper(TreeNode* root,TreeNode* minnode,TreeNode* maxnode) 
    {
        //使用递归的方式判断是否是有效二叉树
        //递归终止条件
        if(root == nullptr)
        {
            return true;
        }
        //在这里的判断是，如果是左边的节点，那么minnode就等于nullptr，不会判断第一个条件
        //反之只判断第一个条件,只要有一个孩子大于最小或最大，直接结束
        if((minnode != nullptr && root->val <= minnode->val) ||
            maxnode != nullptr && root->val >= maxnode->val)
        {
            return false;
        }
        return isValidHelper(root->left,minnode,root) && isValidHelper(root->right,root,maxnode);
    }
};
//结论：通过
