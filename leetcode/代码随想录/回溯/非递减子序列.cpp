// 1.我自己的解
// 使用集合去除重复元素
class Solution 
{
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        // 原理为如果当前元素大于等于path中的-1元素,就可以添加到res
        vector<int> path;
        backtrack(nums,path,0);
        vector<vector<int>> result;
        for(const vector<int> num : res)
        {
            result.push_back(num);
        }
        return result;
    }
private:
    set<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int>& path,int start)
    {
        if(path.size() >= 2) 
        {
            res.insert(path);
        }
        
        for(int i = start;i < nums.size();i++)
        {
            // 该处不能通过这种方式continue
            // 因为并不是排序数组
            // if(i > start && nums[i] == nums[i - 1]) continue;
            if(path.empty() || 
            (!path.empty() && nums[i] >= path.back()))
            {
                path.push_back(nums[i]);
                backtrack(nums,path,i + 1);
                path.pop_back();
            } 
        }
    }
};
// 结论:通过 时间复杂度o(N * 2 ^ n)和空间复杂度o(n).

// 2.使用unset集合去重法
class Solution 
{
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        // 原理为如果当前元素大于等于path中的-1元素,就可以添加到res
        vector<int> path;
        backtrack(nums,0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<int>& nums,int start)
    {
        if(path.size() >= 2) 
        {
            res.push_back(path);
        }
        unordered_set<int> uset;
        for(int i = start;i < nums.size();i++)
        {
            // 该处不能通过这种方式continue
            // 因为并不是排序数组
            // if(i > start && nums[i] == nums[i - 1]) continue;
            if((!path.empty() &&  nums[i] < path.back()) ||
                uset.find(nums[i]) != uset.end())
                {
                    continue;
                } 
                uset.insert(nums[i]); // 记录这个元素在本层使用过，后续不能再使用
                path.push_back(nums[i]);
                backtrack(nums,i + 1);
                path.pop_back();
        }
    }
};
// 结论:通过
