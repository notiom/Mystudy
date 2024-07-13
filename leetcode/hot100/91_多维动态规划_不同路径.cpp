// 1.我自己的解
// 排列组合
class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        // 其实本题是一个排列组合
        // 总步数中(m + n - 2)中选择出m - 1个步数去走列
        int di = m + n - 2;
        if(di == 0) return 1;
        int ni = m - 1;
        // C(di,ni)= di/1 * di-1/2 * di-n+1/n
        long long result = 1;
        for(int i = 1;i <= ni;i++)
        {
            result = result * (di - ni + i) / i;
        }
        return static_cast<int>(result);
    }
};
// 结论:通过时间复杂度o(m - 1 * log (m - 1))
// 大数一定能被小数除

// 2.动态规划
// 官方题解
class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        // 使用动态规划解题
        // 先将第一行和第第一列的数据都置为1
        vector<vector<int>> res;
        res.resize(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }
        return res[m - 1][n - 1];
    }
};
// 结论:通过 时间复杂度和空间复杂度都是o(m * n)

// 3.空间复杂度优化
// res的计算只需要上一行和当前行即可

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        // 使用动态规划解题
        // 先将第一行和第第一列的数据都置为1
        vector<int> pre(n,1);
        vector<int> res(n, 1);
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                res[j] = pre[j] + res[j - 1];
                pre = res;
            }
        }
        return res[n - 1];
    }
};
// 结论:通过
