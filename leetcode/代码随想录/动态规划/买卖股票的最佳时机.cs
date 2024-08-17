// 1. 在hot100中刷过并在这里用cs复现
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
