// 1.代码随想录的解
// 要设置冷冻期状态和保持卖出股票和今天就卖出股票状态
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        // 本题要设置4个状态
        // 1.买入股票
        // 2.保持卖出股票状态
        // 3.今天就卖出股票
        // 4.冷冻期

        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(4,0));
        dp[0][0] = -prices[0];

        for(int i = 1;i < n;i++)
        {
            // 持有股票
            // 包括昨天就持有股票 和 今天买入股票（昨天冷冻期或者昨天保持卖出和股票的状态）
            dp[i][0] = max(dp[i - 1][0],max(dp[i - 1][3] - prices[i],dp[i - 1][1] - prices[i]));
            // 昨天就保持卖出的状态和昨天是冷冻期
            dp[i][1] = max(dp[i - 1][1],dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2]; //昨天卖出
        }
        // 最大利润为每个持股的状态取最大值（包含冷冻期）
        return max(dp[n - 1][1],max(dp[n - 1][2],dp[n - 1][3]));
    }
};
// 结论:时间复杂度和空间复杂度o(n).

// 2.只设置两个状态的动态规划
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        // 本题要设置4个状态
        // 1.持有股票
        // 2.卖出股票

        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int>(2,0));
        dp[1][0] = -prices[0];

        for(int i = 2;i <= n;i++)
        {
           /*
            dp[i][0] 第i天持有股票收益;
            dp[i][1] 第i天不持有股票收益;
            情况一：第i天是冷静期，不能以dp[i-1][1]购买股票,所以以dp[i - 2][1]买股票，没问题
            情况二：第i天不是冷静期，理论上应该以dp[i-1][1]购买股票，但是第i天不是冷静期说明，第i-1天没有卖出股票，
                则dp[i-1][1]=dp[i-2][1],所以可以用dp[i-2][1]买股票，没问题
             */
            dp[i][0] = max(dp[i - 1][0],dp[i - 2][1] - prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1],dp[i - 1][0] + prices[i - 1]);

        }
        // 最大利润为每个持股的状态取最大值（包含冷冻期）
        return dp[n][1];
    }
};


// 3.简化空间复杂度
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        // 本题要设置4个状态
        // 1.买入股票
        // 2.保持卖出股票状态
        // 3.今天就卖出股票
        // 4.冷冻期

        int n = prices.size();
        vector<int> dp(4,0);
        dp[0] = -prices[0];
        for(int i = 1;i < n;i++)
        {
            int temp = dp[0];
            int temp1 = dp[2];
            dp[0] = max(dp[0],max(dp[3],dp[1]) - prices[i]);
            dp[1] = max(dp[1],dp[3]);
            dp[2] = temp + prices[i];
            dp[3] = temp1;
        }
        // 最大利润为每个持股的状态取最大值（包含冷冻期）
        return max(dp[1],max(dp[2],dp[3]));
    }
};
// 结论:时间复杂度o(n),空间复杂度为o(1).
