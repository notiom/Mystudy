 struct TreeNode 
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//1.我自己的解
//利用队列将每一层的节点加入到队列中，然后在利用一个容器接住这个队列中的所有数据
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* node = root;
        //定义输出结果
        int res = 1;
        while(!que.empty())
        {
            vector<TreeNode*> parents;
            while(!que.empty())
            {
                node = que.front();
                que.pop();
                parents.push_back(node);
            }
            int n = parents.size(); // 父节点的个数
            for(int i = 0; i < n;i++)
            {
                if(parents.at(i)->left!=nullptr)
                {
                    que.push(parents.at(i)->left);
                }
                if(parents.at(i)->right!=nullptr)
                {
                    que.push(parents.at(i)->right);
                }
            }
            if(!que.empty()) res++;
        }
        return res;
    }
};
//结论：通过

//2.递归的深度优先遍历
// 知道递归的计算公式为 max(l,r)+1 终止条件为当前子数都为空
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
        }
};
//结论：代码量极少

3.//广度优先遍历
//我自己的解的改进版本，使用了Q_size代替vector的使用
  class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* node = root;
        //定义输出结果
        int res = 0;
        while(!que.empty())
        {
            int Q_size = que.size();
            while(Q_size > 0)
            {
                node = que.front();
                que.pop();
                if(node->left!=nullptr)
                {
                    que.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    que.push(node->right);
                }
                Q_size--;
            }
            res++;
        }
        return res;
    }
};
//结论：通过，利用了一个q_size变量存储当前层的大小，节省了空间复杂度
