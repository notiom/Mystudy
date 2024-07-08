// 1.我自己的解
// 利用回溯和一定的剪枝操作实现
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {   
        // 第一思路还是回溯
        // 但是在回溯中，需要只取出最小值
        // 设计一定的剪枝
        if(amount == 0) return 0;
        n = coins.size();
        // 反向排序
        sort(coins.begin(), coins.end(),[](const int& a, const int& b){return a > b;}); // 排序，保证取最小值
        dfs(n, coins, amount,0);
        return res == INT_MAX? -1 : res;

    }
private:
    int n; //容量
    int res = INT_MAX; // 判断最后min是否改变，如果没有被改变，则返回-1
    int curmin = 0; // 定义当前的最小次数
    void dfs(int n,vector<int>& coins,int amount,int index)
    {
        for(int i = index;i < n;i++)
        {
            if(amount < coins.at(i)) continue;
            curmin++;

            if(curmin >= res)
            {
                // 不必要的剪枝操作
                curmin--;
                return;
            }

            if(amount == coins.at(i))
            {
                // 找到可行解
                res = min(res, curmin);
                curmin--;
                return;
            }

            dfs(n, coins, amount - coins.at(i),i);
            curmin--; //回溯
        }        
    }
};
// 结论：超出时间限制

// 2.官方题解
// 动态规划法一
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {   
        // 动态规划
        // 设计一个dp数组
        int n = coins.size();
        // 可以设置为amount + 1 的原因是 假设每个硬币的面额是1，那么到达amount的次数最大为amount，设置amount可以在取最小值时默认取到
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for(const auto& coin : coins)
            {
                // 如果当前硬币大小大于金额总数，直接跳过
                if(i - coin < 0) continue;
                dp[i] = min(dp[i],dp[i - coin] + 1);
            }
        }
        return dp[amount] == (amount + 1) ? -1 : dp[amount];
        
    }
};
// 结论:通过，时间复杂度o(n * m) 空间复杂度o(n * m)
// 利用dp数组存放

// 3.动态规划的另一种变种
// 递归的玩法
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {   
        // 动态规划中的递归求解
        this->n = coins.size();
        return this->dp(coins, amount);
        
    }
private:
    int n; //容量
    int dp(vector<int>& coins,int amount)
    {
        if(amount == 0)
        {
            //说明找到一个可行解
            return 0;
        }
        if(amount < 0)
        {
            // 无解
            return -1;
        }
        int res = INT_MAX; // 判断最后min是否改变，如果没有被改变，则返回-1
        for(const auto& coin : coins)
        {
            int sub_res = this->dp(coins, amount - coin);
            if(sub_res == -1) continue;
            res = min(res, sub_res + 1);
        }
        return res == INT_MAX? -1 : res;
    } 
};
// 结论:超时

// 4.解决超时的备忘录解决方案
// 利用一个备忘录保存之前计算的值，在递归中就不需要重复计算
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {   
        // 动态规划中的递归求解
        this->n = coins.size();
        vector<int> meno(amount + 1,-2);
        return this->dp(meno,coins, amount);
        
    }
private:
    int n; //容量
    int dp(vector<int>& meno,vector<int>& coins,int amount)
    {
        if(amount == 0)
        {
            //说明找到一个可行解
            return 0;
        }
        if(amount < 0)
        {
            // 无解
            return -1;
        }
        // 该if必须放到后面，因为第二轮进入之后如果索引为负，则无法处理
        if (meno[amount]!= -2) return meno[amount];
        int res = INT_MAX; // 判断最后min是否改变，如果没有被改变，则返回-1
        for(const auto& coin : coins)
        {
            int sub_res = this->dp(meno,coins, amount - coin);
            if(sub_res == -1) continue;
            res = min(res, sub_res + 1);
        }
        meno[amount] = (res == INT_MAX? -1 : res);
        return meno[amount];
    } 
};
// 结论:通过 时间复杂度 o(n * amount)，空间复杂度o(n * amount)
