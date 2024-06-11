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
//使用两个队列存储元素，一个存放左子树的节点，一个存放右子树的节点
//111判断当前节点是否都为空，都为空就跳过本轮循环
//222如果有一个不为空，就退出返回false
//333比较元素时如果不相同也退出返回false

//最后如果没有退出循环，将左右子树元素反向入队
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        
        // 使用两个队列分别存储左右子树的节点
        queue<TreeNode*> leftQueue;
        queue<TreeNode*> rightQueue;
        //左右子树分别入队
        leftQueue.push(root->left);
        rightQueue.push(root->right);
        //当有任何一个对列为空时就退出循环
        while (!leftQueue.empty() && !rightQueue.empty()) {
            TreeNode* leftNode = leftQueue.front();
            TreeNode* rightNode = rightQueue.front();
            
            leftQueue.pop();
            rightQueue.pop();
            
            if (leftNode == nullptr && rightNode == nullptr) {
                continue;
            }
            if (leftNode == nullptr || rightNode == nullptr) {
                return false;
            }
            if (leftNode->val != rightNode->val) {
                return false;
            }
            
            // 对称位置入队
            leftQueue.push(leftNode->left);
            rightQueue.push(rightNode->right);
            
            leftQueue.push(leftNode->right);
            rightQueue.push(rightNode->left);
        }
        
        return leftQueue.empty() && rightQueue.empty();
    }
};
//结论：通过

//2.官方题解递归
class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        // 如果根节点为空，直接返回
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode* left, TreeNode* right)
    {
        //递归的终止条件是两个节点都为空
		//或者两个节点中有一个为空
		//或者两个节点的值不相等
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;
        if(left->val != right->val) return false;
        return isMirror(left->left,right->right) && 
        isMirror(left->right,right->left);
    }
};
//结论：通过
//总结:递归不需要知道下一层怎么做，只需要知道当前层怎么做即可
