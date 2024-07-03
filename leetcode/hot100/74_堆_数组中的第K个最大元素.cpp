// 1.我自己的解
// 排序后返回
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
// 结论:虽然通过，但是题目要求设计时间复杂度为o(n)的算法
// 排序算法的时间复杂度为o(nlogn)

//2.结合优先队列的改进版本
struct Compare
{
    bool operator()(const int& a, const int& b) const
    {
        return a > b; // 重载 > 使得 priority_queue 按小到大排序
    }
};

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // 使用长度为k的优先队列从小往大排序，那么队列尾部元素就是第k个最大的元素
        priority_queue<int,vector<int>,Compare> res;
        // priority_queue<int,vector<int>,greater<int>> res;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            res.push(nums.at(i));
            if(res.size() > k)
                res.pop();
        }
        return res.top();
    }
};
// 结论:通过 时间复杂度o(n * log(k)),空间复杂度o(k).

