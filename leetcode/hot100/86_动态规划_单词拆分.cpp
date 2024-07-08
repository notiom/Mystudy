// 1.我自己的解
// 动态规划思路
// 内层循环必须要从0开始遍历，不排除有
// [leet cod leetcode]这样的情况，也是有可能子字符串正好满足s.length = vec.at(j).length
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        // 第一思路仍然是回溯
        // 如果使用动态规划并不知道在dp数组中应该怎样存放数据
        // 不知道目标值即dp数组的终点是多少

        // 第二思路为动态规划
        // 动态规划目标值为字符串的总长度 + 1
        // 看该数组是true or false
         // 使用unordered_set来优化查找单词的速度
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int sl = s.length();
        int n = wordDict.size();
        vector<bool> dp(sl + 1, false);
        dp[0] = true;
        for(int i = 1;i <= sl;i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(dp[j] && (wordSet.find(s.substr(j,i - j))!= wordSet.end()))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sl];
    }
};
// 结论:时间复杂度 o(n * m) 空间复杂度o(n * m)

// 2.官方题解
// dfs回溯
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        // 利用回溯的dfs深度优先遍历
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        this-> meno.resize(n + 1, -2); // 初始化备忘录
        return dfs(s,n,0,dict);
    }
private:
    vector<int> meno; //设置备忘录
    bool dfs(string s, int n,int start, unordered_set<string>& dict)
    {
        if(start >= n) return true; //数组越界说明前缀都已经满足
        if(meno[start] != -2)
        {
            // 之前已被初始化过
            // 只有在递归时才会使用备忘录，所以不能初始化备忘录的值
            return meno[start] == 1 ? true : false;
        }
        for(int i = start + 1;i <= n;i++)
        {
            string str = s.substr(start,i - start);
            // 当前字典中有该单词并且dfs后面满足条件
            if((dict.find(str) != dict.end()) && dfs(s,n,i,dict))
            {
                // 该字符串后面的可以
                meno[start] = 1;
                return true;
            }
        }
        meno[start] = -1;
        return false;
    }
};
//结论:通过 时间复杂度和空间复杂度为o(n * n)

// 3. 广度优先遍历 bfs
// 注意在遍历时i必须取到n，与substr函数有关
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        // 利用回溯的dfs深度优先遍历
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> meno(n,false); // 初始化访问矩阵
        queue<int> que; // 记录可用的索引号
        que.push(0);

        while(!que.empty())
        {
            int idx = que.front();
            que.pop();

            if(meno[idx]) continue; //已经访问过，跳过
            meno[idx] = true;

            for(int i = idx + 1; i <= n;i++)
            {
                string str = s.substr(idx, i - idx);
                if (dict.find(str) != dict.end())
                {
                    //当前字串是单词
                    if(i < n) 
                    {
                        // 还未越界，即后面还有没有计算完的子串
                        que.push(i);
                    }
                    else
                    {
                        //遍历完成，直接返回
                        return true;
                    }
                } 
            }
        }
        //循环结束后还没有返回 ，则证明没有找到
        return false;
    }
};
// 结论：通过 时间复杂度和空间复杂度都为o(n * n)
