// 对照c++版本进行提示之后写出的动态规划

using System;
using System.Collections.Generic;

namespace MainFunc
{
    public class Solution 
    
    {
        public int MaxProfit(int[] prices) 
        {
            // 设置两个dp数组,其中一个是当天持有股票所持有的现金
            // 第二个是不持有股票所持有的现金
            int n = prices.Length;
            int[] dp1 = new int[n];
            dp1[0] = -prices[0];

            int[] dp2 = new int[n];
            dp2[0] = 0;

            for(int i = 1;i < n;i++)
            {
                // 1.上一个持有股票的现金
                // 2.上一个不持有股票的现金 + 购入当前股票
                dp1[i] = Math.Max(dp1[i - 1],dp2[i - 1] - prices[i]);

                // 1. 上一个不持有股票的现金
                // 2.上一个持有股票的现金 + 当前状态卖出
                dp2[i] = Math.Max(dp2[i - 1],dp1[i - 1] + prices[i]);
            }
            // 返回值应该是不持有股票现金
            return dp2[n - 1];

        }
        
        public static void Main(string[] args)
        {
            Solution s = new Solution();
            int []prices = new int[] {7,1,5,3,6,4};
            int n = s.MaxProfit(prices);
            Console.WriteLine("n " + n);
        }
    }
}
// 结论:时间复杂度和空间复杂度都为o(n).
// 空间复杂度可以优化

public class Solution 
{
      public int MaxProfit(int[] prices) 
      {
            // 设置两个dp值,其中一个是当天持有股票所持有的现金
            // 第二个是不持有股票所持有的现金
            int n = prices.Length;

            int dp1 = -prices[0];
            int dp2 = 0;

            for(int i = 1;i < n;i++)
            {
                // 1.上一个持有股票的现金
                // 2.上一个不持有股票的现金 + 购入当前股票
                int temp = dp1;
                dp1 = Math.Max(dp1,dp2 - prices[i]);
                // 1. 上一个不持有股票的现金
                // 2.上一个持有股票的现金 + 当前状态卖出
                dp2 = Math.Max(dp2,temp + prices[i]);
            }
            // 返回值应该是不持有股票现金
            return dp2;
      }
}
// 结论:空间复杂度o(1).

  
