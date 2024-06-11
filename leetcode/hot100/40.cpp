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
//利用递归的思路，返回left和right的最大长度，一条路径的长度为该路径经过的节点数减一，
//细节：创建一个最大值的全局变量，在递归函数里不断变化这个最大值，但是返回值是当前子数的最大长度
class Solution 
{
private:
    int curmax;
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        curmax = 1;
        diameterHelper(root);
        return curmax - 1;
    }
    int diameterHelper(TreeNode *root)
    {
        //递归的终止条件
        if(root == nullptr) return 0;
        //递归函数体
        int left = diameterHelper(root->left);
        int right = diameterHelper(root->right);
        //判断长度是否大于原先的根节点
        curmax = max(curmax,left + right + 1);
        //返回值，下方的最长子节点加自己
        return max(left,right) + 1;
    }
};
//结论：通过

//2.官方题解
