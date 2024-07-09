// 1.我自己的解
// 使用动态规划存放之前的每一个地方的最大值
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        // 思路:使用动态规划记录max子序列的最大长度
        int n = nums.size();
        // 使用一个dp数组
        vector<int> dp(n + 1,1);
        dp[0] = 0;
        dp[1] = 1;
        if(n == 0) return 0;
        for(int i = 2; i <= n; i++)
        {
           for(int j = 1;j < i;j++)
           {
                if(nums.at(i - 1) > nums.at(j - 1)) dp[i] = max(dp[i],dp[j] + 1);
           }
           maxcount = max(dp[i],maxcount);
        }
        return maxcount;
    }
private:    
    int maxcount = 1;
};
// 结论:通过 时间复杂度o(n * n),空间复杂度o(n)
// 在dp数组初始化时一定要初始化为1，因为每一个元素起始点都为1

//2. 官方题解
