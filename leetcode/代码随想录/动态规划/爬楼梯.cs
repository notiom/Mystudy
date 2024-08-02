// 1.我自己的解
// 爬楼梯dp[n] = dp[n - 1] + dp[n - 2]
public class Solution 
{
    public int ClimbStairs(int n) 
    {
        if(n <= 2) return n;
        int pre1 = 1;
        int pre2 = 2;
        // 迭代 dp数组
        // 动态规划方程dp[n] = dp[n - 1] + dp[n - 2]
        for(int i = 2;i < n; i++)
        {
            int temp = pre1 + pre2;
            pre1 = pre2;
            pre2 = temp;
        }
        return pre2;
    }
}
// 结论:时间复杂度为o(n),空间复杂度为o(1).
