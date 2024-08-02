// 1.我自己的解
// 使用动态规划
public class Solution 
{
    public int UniquePaths(int m, int n) 
    {
        // 不同路径就是来自左边的路径加上来自上方的路径之和
        // dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        // 初始化第一行和第一列都为1
        int [,] dp = new int[m, n];
        for (int i = 0; i < m; i++)
        {
            dp[i,0] = 1;
        }
        for(int j = 0;j < n; j++)
        {
            dp[0,j] = 1;
        }
        for(int i = 1;i < m; i++)
        {
            for(int j = 1;j < n; j++)
            {
                dp[i,j] = dp[i - 1,j] + dp[i,j - 1];
            }
        }
        return dp[m - 1,n - 1];     
    }
}
/ 结论:通过
