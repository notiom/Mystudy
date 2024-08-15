// 1.我自己的解
// 动态规划方程为dp[j] += dp[j - coins[i]]
// 因为新一轮可能的选择为当前上一轮的状态加上这一轮如果选了的状态
class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        // 零钱兑换
        // 本题是一个完全背包问题

        int n = coins.size();

        vector<int> dp(amount + 1,0);
        dp[0] = 1;
        for(int i = coins[0];i <= amount;i++)
        {
            if(i % coins[0] == 0) dp[i] = 1;
        }
        for(int i = 1;i < n;i++)
        {
            for(int j = coins[i];j <= amount;j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// 结论:通过 时间复杂度和空间复杂度都为o(n * amount).

// 2.省去给dp[0]赋值
class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        // 零钱兑换
        // 本题是一个完全背包问题

        int n = coins.size();

        vector<int> dp(amount + 1,0);
        dp[0] = 1;
        for(int i = 0;i < n;i++)
        {
            for(int j = coins[i];j <= amount;j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// 结论:通过

// 3.复习回溯算法
class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        // 零钱兑换
        // 本题也可以使用回溯
        n = coins.size();
        sort(coins.begin(), coins.end()); // 排序硬币以便于剪枝
        backtrack(coins,amount,0,0);
        return res;
    }
private:
    int res = 0;
    int n = 0; // 容器长度
    void backtrack(vector<int>& coins,int amount,int sum,int index)
    {
        // 递归终止条件
        if(sum >= amount)
        {
            if(sum == amount) res++;
            return;
        }

        for(int i = index;i < n;i++)
        {
            if(sum + coins[i] > amount) break;

            backtrack(coins,amount,sum + coins[i],i);
        }
    }
};
// 结论:超时
