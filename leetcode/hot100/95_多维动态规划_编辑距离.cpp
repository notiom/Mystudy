// 1.官方题解
// 要理解dp数组的含义来使用多维动态规划
class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        // 编辑距离
        // dp[i][j]是word1中的前i个字符转变为word2中的前j个字符需要的最小操作数
        // dp[i-1][j] 表示删除，dp[i][j-1]表示插入
        // dp[i - 1][j - 1]需要表示当前字符串是否需要替换
        // 毫无头绪的hard题目
        // 删除插入都需要使操作数加1
        // 但是替换可能出现元素相同的情况，此时dp[i][j] = dp[i - 1][j - 1]

        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 对边缘元素进行赋值
        for(int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++)
        {
            dp[0][j] = j;
        }

        // 填写动态规划表
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    // dp数组有变化
                    dp[i][j] = 1 + min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1] - 1);
                }
                else
                {
                    dp[i][j] = 1 + min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
// 结论:时间复杂度和空间复杂度都为o(m * n).

// 2.自己尝试优化空间复杂度
class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        // 编辑距离
        // 优化空间复杂度

        int m = word1.size(), n = word2.size();
        vector<int> dp1(n + 1,0); // 上一行

        for(int k = 0; k <= n; k++)
        {
            dp1[k] = k; // 初始值：在 word1 前面插入 k 个字符
        }
        vector<int> dp2 = dp1; // 当前行

        // 填写动态规划表
        for(int i = 1; i <= m; i++)
        {
            dp2[0] = i;
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    // dp数组有变化
                    dp2[j] = 1 + min(min(dp1[j],dp2[j - 1]),dp1[j - 1] - 1);
                }
                else
                {
                    dp2[j] = 1 + min(min(dp1[j],dp2[j - 1]),dp1[j - 1]);
                }
            }
            dp1 = dp2;
        }
        return dp2[n];
    }
};
// 优化之后空间复杂度为o(2 * n).
