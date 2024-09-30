// 1.代码随想录的解
// 贪心算法
// 将这个区间中所有后面比前面大的差值累加
public class Solution 
{
      public int MaxProfit(int[] prices) 
      {
           // 贪心算法获得最多的利润
           // 就是在这个区间内可以获得的利润的总和
           // 即1 3 5 3 1 
           // 贪心算法可以计算到 3 - 1 + 5 - 3的总利润
           int res = 0;
           for(int i = 1;i < prices.Length;i++)
           {
                // 亏了就不卖
                res += Math.Max(prices[i] - prices[i - 1],0);
           }
           return res;
      }
}
// 结论:时间复杂度o(n),空间复杂度o(1).
