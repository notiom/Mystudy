// 1.我自己的解
// dfs函数有辅助，当找到时必须要返回true
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 通过深度优先遍历将一个树的层添加到队列中
        vector<TreeNode*> pp;
        vector<TreeNode*> qq;
        dfs(root, p, pp);
        dfs(root, q, qq);
        // 找到pp和qq在同一路径上的最后一个元素
        // 找到pp和qq在同一路径上的最后一个元素
        int i = 0;
        while (i < pp.size() && i < qq.size() && pp[i] == qq[i]) {
            i++;
        }
        return pp[i - 1];
    }

private:
    bool dfs(TreeNode* children, TreeNode* p, vector<TreeNode*> &vec) {
        if(children == nullptr) return false;
        // 如果找到了这个孩子，就应该追根溯源的找到其所有的祖先
        vec.push_back(children);
        if(children == p) return true;
        if(dfs(children->left, p, vec) || dfs(children->right, p, vec)) return true;

        // 回溯时移除当前节点
        vec.pop_back();
        return false;
    }
};
//结论:通过 时间复杂度o(n) 空间复杂度o(n).

//2.官方题解

//  1.--- 当 left 和 right 同时为空 ：说明 root 的左 / 右子树中都不包含 p,q ，返回 null ；
//  2.---当 left 和 right 同时不为空 ：说明 p,q 分列在 root 的 异侧 （分别在 左 / 右子树），因此 root 为最近公共祖先，返回 root ；
//  3.---当 left 为空 ，right 不为空 ：p,q 都不在 root 的左子树中，直接返回 right 。具体可分为两种情况：
//  p,q 其中一个在 root 的 右子树 中，此时 right 指向 p（假设为 p ）；
//  p,q 两节点都在 root 的 右子树 中，此时的 right 指向 最近公共祖先节点 ；
//。当 left 不为空 ， right 为空 ：与情况 3. 同理；

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // 递归终止条件
        if(root == nullptr || root == p || root == q) return root;

        // 左子树和右子树分别找p和q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);


        // 若p, q在root的右子树中，root的右子树为LCA
        if(left == nullptr) return right;

        // 若p, q在root的左子树中，root的左子树为LCA
        if(right == nullptr) return left;

        return root; // 若p, q都查找到，root为LCA
    }
};
// 结论：通过
