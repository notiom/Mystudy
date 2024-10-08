// 1.代码随想录的解
// 加入维度
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        // 官方题解是在设置一个第二次交易的维度
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(5,0));
        dp[1][1] = -prices[0]; // 第一天第一次买入
        dp[1][3] = -prices[0]; // 第一天二次买入
        for(int i = 1;i < n;i++)
        {
            dp[i + 1][1] = max(dp[i][1],-prices[i]); // 买入
            dp[i + 1][2] = max(dp[i][2], dp[i][1] + prices[i]); // 卖出
            dp[i + 1][3] = max(dp[i][3],dp[i][2] - prices[i]); // 第二次买入
            dp[i + 1][4] = max(dp[i][4],dp[i][3] + prices[i]); // 第二次卖出
        }
        return dp[n][4];
    }
};
// 时间复杂度和空间复杂度都是o(n).

