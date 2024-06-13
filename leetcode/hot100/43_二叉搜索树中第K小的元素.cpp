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
//1.我自己的解，使用前序遍历，加入的元素未必是升序排列，再循环结束后，还需要进行一个快速排序
//所以算法不够严谨
vector<int> operator+(const vector<int> &nums1,const vector<int> &nums2)
{
    vector<int> res = nums1;
    res.insert(res.end(),nums2.begin(),nums2.end());
    return res;
}
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {   
        dfs(root);
        vector<int> nums = quickSort(this->res);
        return nums.at(k - 1);
    }

    void dfs(TreeNode* root)
    {
        //递归的终止条件
        if(root == nullptr) return;
        //递归的逻辑处理
        //先将当前元素加入
        //加入元素的方式应该是5,3,2,1,4,6
        this->res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> quickSort(vector<int> &nums)
    {
        int n = nums.size();
        if(n <= 1) return nums;

        int pivot = (n - 1) >> 1;
        vector<int> left{};
        vector<int> right{};
        vector<int> middle{};
        for(int i = 0; i < n;i++)
        {
            if(nums.at(i) < nums.at(pivot)) left.push_back(nums.at(i));
            if(nums.at(i) == nums.at(pivot)) middle.push_back(nums.at(i));
            if(nums.at(i) > nums.at(pivot)) right.push_back(nums.at(i));
        }
        return quickSort(left) + middle + quickSort(right);
    }
private:
    vector<int> res{}; //先初始化一个空列表
};
//结论：有改进空间，使用中序遍历，可以保证一定是升序排列

// 深度优先遍历（DFS）：

// 前序遍历
// 中序遍历
// 后序遍历
// 广度优先遍历（BFS）：

// 层次遍历

//2.使用中序遍历
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {   
        dfs(root);
        return res.at(k - 1);
    }

    void dfs(TreeNode* root)
    {
        //递归的终止条件
        if(root == nullptr) return;
        //递归的逻辑处理
        //先将当前元素加入
        //加入元素的方式应该是1，2，3，4，5，6
        dfs(root->left);
        this->res.push_back(root->val);
        dfs(root->right);
    }
private:
    vector<int> res{}; //先初始化一个空列表
};
//结论：提出思考，如果想要实现从大到小排列应该使用什么遍历

//先遍历右子树，在遍历根节点，最后再遍历左子树

// dfs(root->right);
// res.push_back(root->val);
// dfs(root->left);


//3.官方题解
