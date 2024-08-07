// 1.参考了一点官方思路得出的解
// 本题的关键点在于想到最终返回的重量是两摞状态几乎相等的石头之间的差值
class Solution 
{
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        // 本题的关键点在于想到最终返回的重量是两摞状态几乎相等的石头之间的差值
        // 所以可以转化为0 - 1背包问题
        int n = stones.size();
        int stonesum = 0;
        for(int i = 0;i < n;i++)
        {
            stonesum += stones[i];
        }
        int target = stonesum >> 1;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for(int i = stones.at(0);i <= target;i++)
        {
            dp[0][i] = stones.at(0);
        }

        for(int i = 1;i < n;i++)
        {
            for(int j = 1;j <= target;j++)
            {
                if(j < stones.at(i)) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones.at(i)] + stones.at(i));

            }
        }
        
        return stonesum - 2 * dp[n - 1][target];
    }
};
// 结论:时间复杂度和空间复杂度都为o(n * sum/2).

/2.空间复杂度优化略
