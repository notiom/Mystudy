// 1.我自己的解
// 使用动态规划拆分
public class Solution 
{
    public int IntegerBreak(int n) 
    {
        // 整数拆分
        // 动态规划也像一个0 - 1 背包问题
        // 设dp[i] 为这个正整数为i时的最大乘积
        int [] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j < i;j++)
            {
                // 填写动态规划方程
                dp[i] = Math.Max(dp[i],Math.Max(j * (i - j),j * dp[i - j]));
            }
        }
        return dp[n];
    }
}
// 时间复杂度:o(n * n),空间复杂度o(n).

// 2.时间复杂度的优化
// 由于拆分时，不需要使用dp[0]和dp[1]，所以不需要初始化他们
// 并且在拆分时，仅需要算前一半

public class Solution 
{
    public int IntegerBreak(int n) 
    {
        // 整数拆分
        // 这样拆分的理由是一定是拆分成几个近似相同的数才可能最大
        int [] dp = new int[n + 1];
        for(int i = 2;i <= n;i++)
        {
            for(int j = 1;j <= i / 2;j++)
            {
                // 填写动态规划方程
                dp[i] = Math.Max(dp[i],Math.Max(j * (i - j),j * dp[i - j]));
            }
        }
        return dp[n];
    }
}
// 节省时间复杂度

//3. 贪心算法
// 每次只需要将其拆分为n个3即可
public class Solution 
{
    public int IntegerBreak(int n) 
    {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;

        int result = 1;
        while(n > 4)
        {
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
}
// 时间复杂度o(n),空间复杂度o(1).
