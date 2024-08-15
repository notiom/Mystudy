// 1.自己的解
// 自己的解出问题在初始化dp数组不可能的情况应该为amount + 1，而不应该为-2，在计算最小值时不好计算
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        // 动态规划中存放的是到达此处需要的最小个数
        // 
        int n = coins.size();
        vector<int> dp(amount + 1,amount + 1);
        dp[0] = 0;
        for(const int& coin : coins)
        {
            for(int i = coin;i <= amount; i++)
            {
                dp[i] = min(dp[i],dp[i - coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// 结论:通过 时间复杂度o(n * amuount), 空间复杂度o(amount).
