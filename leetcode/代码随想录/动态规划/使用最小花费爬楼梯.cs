// 我自己的解
// 使用动态规划他需要计算各个部分的dp数组
// 最终返回到达上一层的和到达本层的最小花费数组
public class Solution 
{
    public int MinCostClimbingStairs(int[] cost) 
    {
        int n = cost.Length;
        List<int> dp = new List<int>(new int[n]);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i < n;i++)
        {
            // 不需要楼顶的花费
            dp[i] = Math.Min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
        }
        return Math.Min(dp[n - 2],dp[n - 1]);
    }
}
