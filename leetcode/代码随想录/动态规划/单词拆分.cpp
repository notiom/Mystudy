// 1.我自己的思路加tabnine的一点辅助
// 主要要知道什么条件下dp[i] == true
// 只有当前面的字符串满足条件时,才会将当前的dp置为true.
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = s.length();
        vector<bool> dp(n + 1,false);
        dp[0] = true;   //如果字符串为0，直接不选即为true
        // 该问题应该是一个排列问题，所以应该先遍历背包，在遍历物品
        for(int i = 1; i <= n;i++)
        {
            // 遍历背包
            for(const string & str : wordDict)
            {
                // 遍历物品
                int len = str.length();
                if(i >= len && dp[i - len] && s.substr(i - len,len) == str)
                {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};
// 结论:时间复杂度o(m * n * k),空间复杂度o(n).
