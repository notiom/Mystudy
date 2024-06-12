
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
//1.起初我以为需要用到左旋右旋的知识
// 使用递归的思路递归的遍历中点，递归函数体应该是将当前vector对应的中点元素添加到数，再将这棵树的left作为左边容器的中点，right
// 作为右边容器的中点
class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        // 将容器变为一颗平衡二叉树
        // 递归的方式
        return ToBSTHelper(nums,0,nums.size() - 1);
    }
private:
    TreeNode* ToBSTHelper(const vector<int> &nums,int left,int right)
    {
        //递归终止条件
        if(left > right) return nullptr;

        int mid = (left + right) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        //此处传入的左右边界不应该包含mid
        root->left = ToBSTHelper(nums,left,mid - 1);
        root->right = ToBSTHelper(nums,mid + 1, right);
        return root;
    }
};
//结论：通过

//2.官方题解

//官方使用的方式为控制mid的值，可以指向中间节点右边，也可以指向中间节点
