// 1.我自己的解
// 该题和股票III类似,只需要设置多维度并找到III的规律即可
class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        // 本题与III类似
        // 需要设置2 * k个维度的动态规划数组
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(2 * k + 1,0));
        for(int i = 1;i < 2 * k;i += 2)
        {   
            dp[1][i] = -prices[0];
        }

        for(int i = 2;i <= n;i++)
        {
            dp[i][1] = max(dp[i - 1][1],-prices[i - 1]);
            for(int j = 2;j <= 2 * k;j++)
            {
                if(j % 2 != 0)
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1] - prices[i - 1]);
                else
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1] + prices[i - 1]);
            }
        }
        return dp[n][2 * k];
    }
};
// 结论:时间复杂度和空间复杂度o(n * k)。

// 2.简化空间复杂度位o(2 * k).
class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        // 本题与III类似
        // 需要设置2 * k个维度的动态规划数组
        int n = prices.size();
        vector<int> dp(2 * k + 1,0);
        for(int i = 1;i < 2 * k;i += 2)
        {   
            dp[i] = -prices[0];
        }

        for(int i = 2;i <= n;i++)
        {
            dp[1] = max(dp[1],-prices[i - 1]);
            for(int j = 2;j <= 2 * k;j++)
            {
                if(j % 2 != 0)
                    dp[j] = max(dp[j],dp[j - 1] - prices[i - 1]);
                else
                    dp[j] = max(dp[j],dp[j - 1] + prices[i - 1]);
            }
        }
        return dp[2 * k];
    }
};

