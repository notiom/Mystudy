// 1.我自己的解
// 先对前m个元素初始化，再将m + 1个元素将前几m个元素累加
class Solution 
{
public:
    int clibStair(int m,int n)
    {
        // 爬楼梯进阶版
        // 先初始化前m阶楼梯的值
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        // 完成初始化
        for(int i = 1;i <= m;i++)
        {
            for(int j = 0;j < i;j++)
            {
                dp[i] += dp[j];
            }
        }
        for(int i = m + 1;i <= n;i++)
        {
            for(int j = i - m;j < i;j++)
            {
                dp[i] += dp[j];
            }
        }
        return dp[n];
    }
};

// 2.思路:完全背包问题,每个元素都可以重复拿，看装满背包有几种情况。
class Solution 
{
public:
    int clibStair(int m,int n)
    {
        // 爬楼梯进阶版
        // 如果利用完全背包的思想
        // 既然是求排列，需要先遍历背包在遍历物品

        vector<int> dp(n + 1,0);
        dp[0] = 1;

        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                // 遍历物品时将可走的步数看作物品
                if(i - j >= 0) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};
