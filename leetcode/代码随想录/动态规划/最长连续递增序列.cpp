// 1.我自己的解
// 连续的最长子序列,动态规划中的每个dp取最大值
class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        // 使用动态规划
        int n = nums.size();

        vector<int> dp(n + 1,0);
        dp[1] = 1;
        int res = 1;
        for(int i = 1;i < n;i++)
        {
            if(nums[i] > nums[i - 1])
                dp[i + 1] = dp[i] + 1;
            else
                dp[i + 1] = 1;
            res = max(res,dp[i + 1]);
        }
        return res;
    }
};
// 结论:时间复杂度和空间复杂度都为o(n).

// 2.我自己的贪心算法
class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        // 使用动态规划
        int n = nums.size();

        int res = 1;
        int curres = 1;
        for(int i = 1;i < n;i++)
        {
            if(nums[i] > nums[i - 1])
                curres++;
            else
                curres = 1;
            res = max(res,curres);
        }
        return res;
    }
};
// 结论:空间复杂度o(1).
