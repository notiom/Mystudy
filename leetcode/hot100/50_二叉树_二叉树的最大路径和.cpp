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

// 1.官方题解
// 使用递归去计算分支的路径
class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
    {
        pathSumHelper(root);
        return maxSum;
    }

    int pathSumHelper(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int leftSum = pathSumHelper(root->left);
        int rightSum = pathSumHelper(root->right);

        int innerMaxSum = leftSum + root->val + rightSum; //节点内部最大的和
        maxSum = max(maxSum, innerMaxSum);

        // 返回当前子树对外提供的最大和
        int outputSum = root->val + max(0,max(leftSum,rightSum));

        return outputSum < 0? 0 : outputSum;
    }
private:
    int maxSum = INT_MIN;
};

// 通过 时间复杂度 o(n) 空间复杂度 o(1).
