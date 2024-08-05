// 1.官方题解
// 要知道公式中dp[j - 1]表示左边有多少个数可以排列 * dp[i - j]右边有多少个数
class Solution 
{
public:
    int numTrees(int n) 
    {
        // 卡特兰数公式
        // f(i)=G(i−1) * G(n−i)

        vector<int> dp(n + 1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            for(int j = 1;j <= i;j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// 结论:时间复杂度o(n * n),空间复杂度o(n).
