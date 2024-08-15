// 1.我自己的解
// 动态规划遍历背包
class Solution 
{
public:
    int numSquares(int n) 
    {
        // 完全平方数
        // dp数组中存放的是
        vector<int> dp(n + 1,n + 1);
        dp[0] = 0;
        for(int i = 1;i <= sqrt(n);i++)
        {
            // 先遍历物品
            for(int j = i * i;j <= n;j++)
            {
                // 再遍历背包
                dp[j] = min(dp[j],dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};
// 结论:时间复杂度o(n * sqrt(n))

//2. 回溯
class Solution 
{
public:
    int numSquares(int n) 
    {
        // 完全平方数
        // 使用回溯
        backtrack(n,0,0,1);
        return res;

    }
private:
    int res = INT_MAX;
    void backtrack(int n,int sum,int cnt,int index)
    {
        // 遍历只需要达到根号n即可
        if(sum >= n)
        {
            if(sum == n)
            {
                res = min(res, cnt);
            }
            return;
        }

        for(int i = index;i <= sqrt(n);i++)
        {
            if(sum + i * i > n) break;
            backtrack(n,sum + i * i,cnt + 1,i);
        }
    }
};
// 超出时间限制的回溯
