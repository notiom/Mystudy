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
class Solution 
{
public:
    int pathSum(TreeNode* root, int targetSum)
    {
        //思路:使用前序遍历将所有可以的路径加入到vector中
        if(root == nullptr) return 0;
        //运行完之后tihs->paths中就有路径
        vector<int> nums{};
        dfs(root, nums);
        for(vector<int> &path:this->paths)
        {
            res += pathSumHelper(path,targetSum);
        }
        return res;

    }

    void dfs(TreeNode* root,vector<int> &path)
    {
        if(root == nullptr) return;

        // 添加当前节点到path中
        path.push_back(root->val);
        //判断是否是叶子节点
        if(!root->left && !root->right) 
        {
            this->paths.push_back(path);
        }
        else
        {
            dfs(root->left,path);
            dfs(root->right,path);
        }

        //回溯,移除当前节点
        path.pop_back();
    }

    //判断有相加等于targetSum的路径的条数
    int pathSumHelper(vector<int> &nums,int targetSum)
    {
        int sum = 0; //返回的最终结果
        int preSum = 0; //定义前驱和
        int n = nums.size();

        //创建哈希表
        // key = perSum, value = count
        unordered_map<int,int> maps;
        //循环计算前驱和
        for(int i = 0;i < n;i++)
        {
            preSum +=nums.at(i);
            maps[preSum]++;
        }
        for(const auto &map : maps)
        {
            if(maps.find(map.first + targetSum)!=maps.end())
            {
                //如果当前元素被找到
                sum += maps[map.first + targetSum];
            }
        }
        return sum;
    }

private:
    int res = 0;
    vector<vector<int>> paths;
};

//结论：无法处理相同分支出现的情况

//经过GPT调教我知道需要在dfs算法中判断是否和为目标值

//2.自己通过GPT改进后的自己的代码
class Solution 
{
public:
    int pathSum(TreeNode* root, int targetSum)
    {
        //思路:使用前序遍历将所有可以的路径加入到vector中
        if(root == nullptr) return 0;
        //运行完之后tihs->paths中就有路径
        vector<int> nums{};
        dfs(root, nums,targetSum);
        return res;
    }

    void dfs(TreeNode* root,vector<int> &path,int targetSum)
    {
        if(root == nullptr) return;

        // 添加当前节点到path中
        path.push_back(root->val);

        //计算当前路径中有多少子路径的和等于targetSum
        res += pathSumHelper(path,targetSum);

        //递归的遍历左右子树
        dfs(root->left,path,targetSum);
        dfs(root->right,path,targetSum);

        //回溯,移除当前节点
        path.pop_back();
    }

    //判断有相加等于targetSum的路径的条数
    int pathSumHelper(vector<int> &nums,int targetSum)
    {
        int sum = 0; //返回的最终结果.
        // 因为要避免将重复的路径多算一次，只需要找到某个特定的节点从后往前遍历，直到有个元素等于targetSum
        // 那么就是唯一的一条路径
        long long curSum = 0; //定义当前的和
        int n = nums.size();

        //循环计算当前和
        for(int i = n - 1;i >=0;i--)
        {
            curSum +=nums.at(i);
            if(curSum == targetSum)
            {
                sum++;
            }
        }
        return sum;
    }

private:
    int res = 0;
};

//3.官方题解
class Solution 
{
public:
    int pathSum(TreeNode* root, int targetSum)
    {
        //思路:使用前序遍历将所有可以的路径加入到vector中
        if(root == nullptr) return 0;

        // 该函数只能计算以当前节点为根节点的情况，需要递归的调用自身才可以实现整棵树的计算
        int res = rootSum(root,(long long)targetSum);
        res += pathSum(root->left,targetSum);
        res += pathSum(root->right,targetSum);
        return res;
    }

    int rootSum(TreeNode* root,long long targetSum)
    {
        //该函数的起始路径一定是根结点
        if(root == nullptr) return 0;

        int res = 0;
        if(root->val == targetSum) res ++;


        res+= rootSum(root->left,targetSum - root->val);
        res+= rootSum(root->right,targetSum - root->val);
        return res;
    }

};
//结论：必须要通过递归的调用每一个节点才可以计算完整，因为rootSum函数只能计算以当前节点为根节点的情况
