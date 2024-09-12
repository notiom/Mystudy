// 1.我自己的解
// 利用回溯进行sum的计算
class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        backtrack(k,n,1);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    // start为开始的索引,而target为当前需要的目标值
    void backtrack(int k,int target,int start)
    {
        if(path.size() == k)
        {
            // 检查sum是否满足
            if(target == 0) res.push_back(path);
            return;
        }
        for(int i = start;i <= 9;i++)
        {
            // i最大就是nums.size() - k + 1
            path.push_back(i);
            backtrack(k,target - i,i + 1);
            path.pop_back();
        }
    }
};
// 结论:通过 时间复杂度: O(n * 2^n) 空间复杂度: O(n)

// 2.进行剪枝操作
class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        backtrack(k,n,1);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    // start为开始的索引,而target为当前需要的目标值
    void backtrack(int k,int target,int start)
    {
        if(path.size() == k)
        {
            // 检查sum是否满足
            if(target == 0) res.push_back(path);
            return;
        }
        for(int i = start;i <= 9;i++)
        {
            // i最大就是nums.size() - k + 1
            if(target - i < 0) continue;
            path.push_back(i);
            backtrack(k,target - i,i + 1);
            path.pop_back();
        }
    }
};
// 结论:通过 时间复杂度: O(n * 2^n) 空间复杂度: O(n)
