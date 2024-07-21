// 1.我自己的解
// 动态规划计算回文串和使用回溯进行分割
class Solution 
{
public:
    vector<vector<string>> partition(string s) 
    {
        // 生成回文判断数组
        generateDp(s);
        vector<string> path;
        // 通过回溯的方式判断一个字符串是否是回文串
        backtrack(s,0,path);
        return res;

    }
private:
    vector<vector<string>> res;
    vector<vector<bool>> dp;

    // 使用动态规划来判断其是否是回文子串
    void generateDp(const string& s)  
    {
        int n = s.length();
        dp.resize(n,vector<bool>(n,false));
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i;j < n;j++)
            {
                if(s.at(i) == s.at(j) && (j - i <= 1 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                }
            }
        }
    }

    void backtrack(const string& s,int start,vector<string>& path)
    {
        int n = s.length();
        if(start == n) 
        {
            // 找到一种可行的方案
            res.push_back(path);
            return;
        }

        for(int end = start; end < n; end++)
        {
            if(dp[start][end])
            {
                path.push_back(s.substr(start,end - start + 1));
                backtrack(s,end + 1,path);
                path.pop_back(); // 撤销上一步的操作
            }
        }
    }
};
// 结论:时间复杂度 o(n * n) 空间复杂度o(n * n).
