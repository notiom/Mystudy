// 1.我自己的解
// 这次含手续费其实就是买卖股票最佳时机II的变种
// 在卖出股票的方程中加入费用的扣除
class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        // 无限次交易只需要在卖出股票的动态规划方程中加入费用即可
        int n = prices.size();

        vector<pair<int,int>> dp(n,make_pair<int>(0,0));
        dp[0].first = -prices[0];
        dp[0].second = 0;

        for(int i = 1;i < n;i++)
        {
            dp[i].first = max(dp[i - 1].first, dp[i - 1].second - prices[i]);
            // 卖出要加入股票 - 2
            dp[i].second = max(dp[i - 1].second, dp[i - 1].first + prices[i] - fee);
        }
        return dp[n - 1].second;
    }
};
// 结论: 通过 时间复杂度和空间复杂度都是o(n).

// 2.空间复杂度优化
class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        // 无限次交易只需要在卖出股票的动态规划方程中加入费用即可
        int n = prices.size();

        pair<int,int> dp;
        dp.first = -prices[0];
        dp.second = 0;

        for(int i = 1;i < n;i++)
        {
            int temp = dp.first;
            dp.first = max(dp.first, dp.second - prices[i]);
            // 卖出要加入股票 - 2
            dp.second = max(dp.second, temp + prices[i] - fee);
        }
        return dp.second;
    }
};
// 结论: 通过 时间复杂度是o(n)，空间复杂度是o(1).
