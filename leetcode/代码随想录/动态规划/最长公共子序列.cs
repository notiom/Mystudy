// 1.我自己的解
// 二维动态规划
public class Solution
{
    public int LongestCommonSubsequence(string text1, string text2) 
    {
        // 使用动态规划
        // 使用二维dp数组
        int m = text1.Length;
        int n = text2.Length;

        int [,] dp = new int[m + 1,n + 1];

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(text1[i] == text2[j])
                    dp[i + 1,j + 1] = dp[i,j] + 1;
                else
                    dp[i + 1,j + 1] = Math.Max(dp[i,j + 1],dp[i + 1,j]);
            }
        }
        return dp[m,n];
    }
}
// 结论: 通过 时间复杂度和空间复杂度都为o(m  * n).

// 2.
