// 1.我自己的解
// 使用动态规划
// 动态规划方程为利用上一行的元素相累加
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        // 动态规划的思路应该是对于每个元素选或者不选,他使某个值为target的个数
        // 比如dp[i][j]表示选择前i个元素时,可以构成target的总数

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, 0)); // 因为target在-1000 - 1000之间
        // 1000是0的索引，即偏移量
        dp[0][1000 + nums[0]] += 1;
        dp[0][1000 - nums[0]] += 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0;j <= 2000;j++)
            {
                // 因为为0的情况也要遍历，有可能无法组成target为0
                // 每个元素都要选
                if (j - nums[i] >= 0)
                {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
                
                if(j + nums[i] <= 2000)
                {
                    dp[i][j] += dp[i - 1][j + nums[i]];
                }
            }
        }
        // 偏移量为1000
        return dp[n - 1][1000 + target];
    }
};
时间复杂度和空间复杂度都为o(2000 * n)
