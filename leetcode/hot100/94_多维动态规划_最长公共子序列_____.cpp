// 1.GPT的动态规划
// 层层递进向上遍历
// 写出动态规划方程即可
// text1 = "abcde"，text2 = "ace"
/*''   a b c d e
  '' 0 0 0 0 0 0
  a  0 1 1 1 1 1
  c  0 1 1 2 2 2
  e  0 1 1 2 2 3
*/
// 动态规划的填充过程如图所示

class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        // 初始思路使用动态规划
        // 动态规划方程为dp[i][j] 为text1字符串长度为i，text2长度为j时的最大子串长度
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));

        for(int i = 1; i <= m;i++)
        {
            for(int j = 1;j <= n;j++)   
            {
                if(text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
// 结论:时间复杂度和空间复杂度都是o(m * n).
