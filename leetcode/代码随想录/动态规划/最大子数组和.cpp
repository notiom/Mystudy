// 1.我自己的解
// 暴力枚举求和
// 超时
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        // 若不用动态规划,那么思路就是暴力枚举
        int n = nums.size();
        int res = -INT_MAX;
        int current = 0; //当前的结果
        for(int i = 0;i < n;i++)
        {
            current = 0;
            for(int j = i;j < n;j++)
            {
                current += nums[j];
                res = max(res,current);
            }
        }
        return res;
    }
};
// 结论:时间复杂度为o(n * n)的算法时间复杂度太高，未通过

// 2.贪心算法
// 我自己的解
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        // 贪心算法
        int n = nums.size();
        int res = -INT_MAX;
        int dp = 0;
        // 如果全为负数,动态规划失效,这时返回一个最大的负数即可
        bool flag = false;
        for(const auto& single : nums)
        {
            res = max(res,single);
            if(single > 0)
            {
                flag = true;
                break;
            }

        }
        if(!flag) return res; 
        for(int i = 0;i < n;i++)
        {
            // 如果当前值current小于0,那么当前的dp值就应该为0
            if(nums[i] + dp < 0) dp = 0;
            else dp = dp + nums[i];
            res = max(res,dp);
            
        }
        return res;
    }
};
// 结论:通过 时间复杂度o(n),空间复杂度o(1).

// 3.贪心算法的改进版本
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        // 贪心算法
        int n = nums.size();
        int res = -INT_MAX;
        int count = 0; //使该值累加,使得全为负数时算法也正确
        for(int i = 0;i < n;i++)
        {
            count += nums[i];
            // 如果当前值current小于0,那么当前的dp值就应该为0
            if(count > res) res = count;

            if(count < 0) count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
            
        }
        return res;
    }
};
// 结论:通过 同上时空复杂度

// 4.动态规划
// 动态规划方程为 dp[n] = max(dp[n - 1] + nums[n,nums[n - 1]).

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        // 贪心算法
        int n = nums.size();
        int res = -INT_MAX;
        vector<int> dp(n + 1,0); //使该值累加,使得全为负数时算法也正确
        for(int i = 1;i <= n;i++)
        {
            dp[i] = max(dp[i - 1] + nums[i - 1],nums[i - 1]);
            res = max(dp[i],res);
        }
        return res;
    }
};
// 结论:通过 时间复杂度和空间复杂度都为o(n).
