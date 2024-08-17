// 1. 在hot100中刷过并在这里用cs复现
// 贪心算法
public class Solution 
{
    public int MaxProfit(int[] prices) 
    {
        int MaxProfit = 0;
        int n = prices.Count(); // 当前数组的大小
        int minPrice = int.MaxValue;
        foreach(int price in prices)
        {
            minPrice = Math.Min(minPrice,price);
            MaxProfit = Math.Max(MaxProfit,price - minPrice);
        }
        return MaxProfit;
    }
}
// 结论：通过 时间复杂度o(n)，空间复杂度o(1).

//2. 代码随想录动态规划算法

// dp[i][0]中i表示前i个元素，0表示当前的最小股票，dp[i][1] 1表示当前的最大利润

public class Solution 
{
    public int MaxProfit(int[] prices) 
    {
        int n = prices.Count(); // 当前数组的大小
        int [,] dp = new int[n,2];
        dp[0,0] = -prices[0];
        dp[0,1] = 0;
        for(int i = 1;i < n;i++)
        {
           dp[i,0] = Math.Max(dp[i - 1,0],-prices[i]);
           dp[i,1] = Math.Max(dp[i - 1,1],prices[i] + dp[i - 1,0]);
            
        }
        return dp[n - 1,1];
    }
}
// 结论：通过 时间复杂度o(n)，空间复杂度o(n).

// 3.优化空间复杂度

public class Solution 
{
    public int MaxProfit(int[] prices) 
    {
        int n = prices.Count(); // 当前数组的大小
        int [] dp = new int[2];
        dp[0] = -prices[0];
        dp[1] = 0;
        for(int i = 1;i < n;i++)
        {
           dp[0] = Math.Max(dp[0],-prices[i]);
           dp[1] = Math.Max(dp[1],prices[i] + dp[0]);
            
        }
        return dp[1];
    }
}
// 结论：通过 时间复杂度o(n)，空间复杂度o(1).

