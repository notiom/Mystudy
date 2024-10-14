// 1.代码随想录的解
// 巧妙地使用dp[i - 1][j - 1]和dp[i - 1][j]表示匹配成功和未成功的情况 
public class Solution 
{
    public int NumDistinct(string s, string t) 
    {
        // 使用动态规划算法
        int m = s.Length;
        int n = t.Length;
        int res = 0;
        int [,] dp = new int[m + 1,n + 1];

        // 当s字串长度为0时,匹配结果一定为0 dp[0][i] = 0,但是dp[0][0]为1
        // 当t字串长度为0时，匹配结果一定为1 dp[i][0] = 1
        for(int i = 0;i <= m;i++)
        {
            dp[i,0] = 1;
        }

        for(int i = 1;i <= m;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(s[i - 1] == t[j - 1])
                {
                    // 当前位置匹配成功
                    // 有两种情况,1.使用匹配成功的上一层结果
                    // 2.不使用匹配成功的结果

                    dp[i,j] = dp[i - 1,j - 1] + dp[i - 1,j];
                }
                else
                {
                    dp[i,j] = dp[i - 1,j]; // 使用匹配不成功的结果
                }
            }
        }
        return dp[m,n];
    }
}
// 结论:时间复杂度和空间复杂度都为o(m * n).
