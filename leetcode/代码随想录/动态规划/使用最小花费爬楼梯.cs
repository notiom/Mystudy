// 1.我自己的解
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
// 2.使用另一种思路的动态规划
// 对比上一个方法的动态规划着一个思路是到达本层时的最小花费
// 而上一个方法是在本层向上蹦是需要的最小花费，所以在n - 1层可以向上蹦，n层可以向上蹦，所以在最终结果中需要进行一个min
public class Solution 
{
    public int MinCostClimbingStairs(int[] cost) 
    {
        int n = cost.Length;
        List<int> dp = new List<int>(new int[n + 1]);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2;i <= n;i++)
        {
            dp[i] = Math.Min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[n];
    }
}
// 结论:通过
