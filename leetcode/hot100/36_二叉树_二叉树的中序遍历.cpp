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
//利用递归实现中序遍历
class Solution 
{    
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        inorderTraverHelper(root, res);
        return res;

    }
private:
    void inorderTraverHelper(TreeNode* root, vector<int> &res)
    {
        if(root == nullptr) return;
        inorderTraverHelper(root->left,res);
        res.push_back(root->val); //访问根节点
        inorderTraverHelper(root->right,res);
    }
};
//结论：通过

//2.使用了一个白灰的枚举值，如果当前节点为白色，则说明未被访问过，如果当前节点为灰色，则当前节点被访问过，需要将其值加到输出结果中
//当栈空的时候结束循环
enum COLOR_TYPE
{
    WHITE,
    GRAY,
};

class Solution 
{    
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<std::pair<COLOR_TYPE,TreeNode*>> stk;
        stk.push(std::pair<COLOR_TYPE,TreeNode*>(WHITE, root));
        vector<int> res;

        while(!stk.empty())
        {
            auto p = stk.top();
            stk.pop(); //出栈
            //判断当前节点是否为空节点
            if(p.second == nullptr) continue;

            if(p.first == WHITE)
            {
                //当前节点为白节点，之前没遍历过
                //注意这里入栈的顺序一定是右，中，左
                stk.push(std::pair<COLOR_TYPE,TreeNode*>(WHITE,p.second->right));
                stk.push(std::pair<COLOR_TYPE,TreeNode*>(GRAY,p.second));
                stk.push(std::pair<COLOR_TYPE,TreeNode*>(WHITE,p.second->left));
            }
            else
            {
                //当前节点为灰节点，之前已经遍历过
                res.push_back(p.second->val);
            }

        }
        return res;
    }
};
结论：要注意进栈的顺序

3.//将左边的节点依次入栈，显式遍历
 //当左边节点为空时，将当前栈顶的元素放到输出结果中，并将节点指向右边的节点
class Solution 
{    
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        std::stack<TreeNode*> stk;
        TreeNode* node = root; //并不想破坏数的结构
        vector<int> res;

        while(node != nullptr || !stk.empty())
        {
            //判断当前节点是否为空节点
            while(node!=nullptr)
            {
                //将所有左边的节点全部入栈
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop(); //出栈
            res.push_back(node->val);
            node = node->right;

        }
        return res;
    }
};
//结论：通过

//4。莫里斯遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
//结论：未理解
