// 1.我自己的解
// 先使用哈希表记录每个元素出现的个数
// 之后按照第二个元素的值进行比较按最小堆排列进优先队列
// 最后输出优先队列中k个元素的first
struct Compare
{
    bool operator()(pair<int, int>&a, pair<int, int>&b) const
    {
        return a.second > b.second; // 反转排序，让后者（元素个数）小的在前面
    }
};

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        //思路:使用优先队列存放pair元素，前者为元素值，后者为元素个数，比较方式为后者，按最小堆排列
        unordered_map<int, int> count;
        for(int num : nums) count[num]++;
        //按照哈希表的最后一个元素的大小进入优先队列
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> que;
        for(const auto& single : count)
        {
            que.push(single);
            if(que.size() > k) que.pop();
        }
        vector<int> res;
        while(!que.empty())
        {
            res.push_back(que.top().first);
            que.pop();
        }
        return res;
    }
};
// 结论：通过 时间复杂度o(n * logk),空间复杂度 o(n)
