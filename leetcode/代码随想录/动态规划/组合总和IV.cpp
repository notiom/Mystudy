// 1.我自己的解
// 本题的难点在于要通过动态规划找出不同的排列
// 而不是选出元素乱序即可

// 先使用回溯版本，结果超时
class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        // 使用回溯算法暴力搜索可能的结果
        n = nums.size();
        vector<int> path;
        backtrack(nums,target,path,0);
        return count;
    }
private:
    int n;
    vector<vector<int>> res;
    int count = 0;
    void backtrack(vector<int>& nums, int target,vector<int>& path,int sum)
    {
        if(sum == target)
        {
            count++;  // 找到一个解
            res.push_back(path);
            return;
        }
        if(sum > target) return;
        for(int i = 0;i < n;i++)
        {
            path.push_back(nums[i]);
            backtrack(nums, target, path, sum + nums[i]);
            path.pop_back();
        }
    }
};
// 结论:未通过 超时

// 2.官方题解使用动态规划
// 个数可以不限使用，说明这是一个完全背包。

// 得到的集合是排列，说明需要考虑元素之间的顺序。

// 本题要求的是排列，那么这个for循环嵌套的顺序可以有说法了。
// 111111 如果求组合数就是外层for循环遍历物品，内层for遍历背包。111111

// 222222 如果求排列数就是外层for遍历背包，内层for循环遍历物品。222222

class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        // 组合总和
        // 完全背包遍历的思想
        int n = nums.size();
        vector<size_t> dp(target + 1,0);
        dp[0] = 1; // 总和为0总有一种不选的方案
        for(int i = 0;i <= target;i++)
        {
            for(int j = 0;j < n ;j++)
            {
                if(i - nums.at(j) >= 0 ) dp[i] += dp[i - nums.at(j)];
            }
        }
        return dp[target];
    }
};
// 结论:通过 时间复杂度o(target * n),空间复杂度o(target).
