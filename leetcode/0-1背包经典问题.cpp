//  0-1背包是一个经典的动态规划问题,给定一个容量为W的背包和n个物品,每个物品有一个重量weight[i]和价值为value[i],在满足背包容量的限制下，使得这些物品的价值最大

// 使用状态转移方程dp[i][w],dp[i][w]表示前i个物品在背包容量为w时的最大价值

// 1. 选该物品为:dp[i][w] = dp[i - 1][w - weight[i - 1]] + value[i - 1] i-1是因为第i个物体其实是索引为i - 1
//    不选该物体为dp[i][w] = dp[i - 1][w]

class Solution 
{
public:
    int knapspack(int w,const vector<int>& weight,const vector<int>& value)
    {
        int n = weight.size();
        vector<vector<int>> dp(n + 1,vector<int>(w + 1,0));
        // 前i个物体时dp必为0
        for(int i = 1;i <= n;i++)
        {
            for(int k = 1;k <= w;k++)
            {
                if(k >= weight[i - 1]) // 当前背包容量还大于当前物体的质量
                {
                    dp[i][k] = max(dp[i - 1][k],dp[i - 1][k - weight[i - 1]] + value[i - 1]);
                }
                else
                {
                    dp[i][k] = dp[i - 1][k];
                }
            }
        }
        // 当循环结束后，返回前i个背包容量为w的位置值
        return dp[n][w];
    }
};

int main()
{
    Solution s;
    vector<int> weight = {2, 3, 4, 5}; //物品重量
    vector<int> value = {3, 4, 5, 6}; //物品质量
    int w = 10; //背包容量
    cout << s.knapspack(w, weight, value) << endl; // 12
    return 0;
}

// 结论:时间复杂度和空间复杂度都为o(nw)

// 2.通过一维数组将空间复杂度优化为o(w)

// 使用倒序遍历
// 因为倒序遍历中前面已经更新过的值不会影响后面
class Solution 
{
public:
    int knapspack(int w,const vector<int>& weight,const vector<int>& value)
    {
        int n = weight.size();
        vector<int> dp(w + 1,0);
        // 前i个物体时dp必为0
        for(int i = 0;i < n;i++)
        {
            for(int k = w;k >= weight[i];k--)
            {
                dp[k] = max(dp[k],dp[k - weight[i]] + value[i]);

            }
        }
        // 当循环结束后，返回前i个背包容量为w的位置值
        return dp[w];
    }
};
//结论:优化空间复杂度

