// 1.我自己的解
// 如果去重的话就只需要跳过相同元素且不是首元素的回溯层即可
class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        // 排序之后听过startindex控制回溯即可去重
        sort(nums.begin(),nums.end());
        vector<int> path;
        int n = nums.size();
        backtrack(nums,path,0,n);
        return res;
    }
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums,vector<int>& path,int startIndex,int n)
    {
        res.push_back(path);

        for(int i = startIndex;i < n;i++)
        {
            if(i != startIndex && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtrack(nums,path,i + 1,n);
            path.pop_back();
        }
    }
};
// 结论:时间复杂度为o(2 ^ n),空间复杂度为o(N * 2 ^ n).
