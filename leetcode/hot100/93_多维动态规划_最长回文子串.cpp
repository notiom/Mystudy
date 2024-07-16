// 1.我自己的解
// 暴力解法
// 逐一循环判断是否是回文子串并进行一些剪枝
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        // 直观思路:使用双循环循环最一开始的字符串,双指针去判断是否满足回文

        int n = s.length();
        // 只有满足回文的字符串出现并大于当前res的长度时，才会更新res
        string res = "";
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int left = i;
                int right = j;
                bool flag = true;
                // 利用双指针判断是否是回文
                while(left < right)
                {
                    if(s.at(left) != s.at(right))
                    {
                        // 说明不是回文
                        flag = false;
                        break;
                    }
                    left++;
                    right--;
                }
                if(flag && j - i + 1 > res.length())
                {
                    res = s.substr(i, j - i + 1);
                }
            }
        
        }
    return res.length() == 0 ? string(1,s.at(0)) : res;
    }
};

// 结论:通过 时间复杂度 o(n * n * n) 空间复杂度 o(1).

// 2.官方题解动态规划
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        // 使用动态规划
        // 使用倒序遍历的动态规划
        int n = s.length();
        string res = "";
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i = n - 1;i >= 0;i--)
        {
            for(int j = i;j < n;j++)
            {
                // 使用正序排列会出现前面用到后面的数据但并未被初始化
                if(s.at(i) == s.at(j) && (j - i <= 1 || dp.at(i + 1).at(j - 1)))
                {
                    // 当只有一个数或者两个数时并且这两个数相同,dp赋值为true
                    dp.at(i).at(j) = true;
                    if(res.size() < j - i + 1)
                    {
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return res;

    }
};
// 结论:通过 时间复杂度和空间复杂度都为o(n * n).
