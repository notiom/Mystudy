// 1.我自己的解
// 暴力枚举
// 在第一层循环中控制要查找的元素
// 第二层循环控制长串,如果最前面的元素没有找到那么后面也找不到
public class Solution 
{
    public bool IsSubsequence(string s, string t) 
    {
        // 1.暴力枚举,思路为将s子串中的每一个元素与t串的索引去看是否存在该元素

        int m = s.Length;
        int n = t.Length;

        int index = 0;
        for(int i = 0;i < m;i++)
        {
            bool flag = false;
            for(int j = index;j < n;j++)
            {
                if(s[i] == t[j])
                {
                    // 找到该元素
                    index = j + 1;
                    flag = true; // 找到本元素
                    break;
                }
            }
            if(!flag) return false;
            if(flag && i == m - 1) return true;
        }
        return true;
    }
}
// 结论: 通过 时间复杂度 o(m * n),空间复杂度o(1).

// 2.动态规划
public class Solution 
{
    public bool IsSubsequence(string s, string t) 
    {
        // 2.动态规划,和最长公共子序列相同
        int m = s.Length;
        int n = t.Length;

        int [,]dp = new int[m + 1,n + 1];
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(s[i] == t[j])
                {
                    dp[i + 1,j + 1] = dp[i,j] + 1;
                }
                else
                {
                    dp[i + 1,j + 1] = Math.Max(dp[i,j + 1],dp[i + 1,j]);
                }
            }
        }
        return dp[m,n] == m ? true : false;
    }
}
结论: 通过 时间复杂度 o(m * n),空间复杂度o(m * n).
