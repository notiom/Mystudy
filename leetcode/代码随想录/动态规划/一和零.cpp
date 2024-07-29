// 1.我自己的解
// 动态规划方程为当前的最大值就是不拿当前或者拿当前的元素
class Solution
{
public:
    int findMaxForm(vector<string>& s, int m, int n)
    {
        // 动态规划方程为dp[m][n]
        // 最多含有m个0和n个1的，新增加的子集中可能会使m和n减少,所以方程为
        // dp[0][0] = 0;
        int S_size = s.size();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        for(int i = 0;i < S_size;i++)
        {
            // 填写dp数组
            int size_0 = 0;
            int size_1 = 0;
            // 拿过之后不能在拿了
            for(auto const& ch : s.at(i))
            {
                if(ch == '0')
                {
                    size_0++;
                }
                else
                {
                    size_1++;
                }
            }
            // 转移到dp[i][j]
            for(int j = m;j >= size_0;j--)
            {
                for(int k = n;k >= size_1;k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j - size_0][k - size_1] + 1); // 如果当前子集拿，那么个数会加1
                }
            }
        }
        return dp[m][n];
    }
};
// 结论:通过 时间复杂度为o(S_size * m * n),空间复杂度为o(m * n).
