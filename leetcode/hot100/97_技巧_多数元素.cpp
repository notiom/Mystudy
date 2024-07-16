// 我自己的解
// 使用哈希表进行计数
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> mps;
        for(const int num : nums)
        {
            mps[num]++;
            if(mps[num] > nums.size() / 2)
                return num;
        }
        return -1;
    }
};
// 结论:时间复杂度和空间复杂度都为o(n).

//2.官方题解 排序

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());3
        // 其返回的索引值一定在中间位置
        return nums[nums.size() / 2];
    }
};

//3.官方题解 设计时间复杂度为o(n),空间复杂度为o(1).

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        // 随机化
        // 因为有一半的概率为众数，所以可以随机抽样来验证其是否是结果
        int n = nums.size();
        while(true)
        {
            int candidate = nums.at(rand() % n);
            int count = 0;
            for(const int num : nums)
            {
                if(num == candidate) count++;
            }
            if(count > n / 2) return candidate;
        }
        return -1;
    }
};
// 其期望值的时间复杂度为o(2 * n),空间复杂度为o(1).

// 4.官方题解，使用投票方法，最终的count值一定大于0，那么选出的候选者一定是最终结果
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        // 使用一种相消的思路，即众数一定是最多的
        // 在最后的结果值一定大于0，那么只需要判断一个候选者是否结果大于0，如果小于0
        // 说明他有可能不是众数，将当前数看作众数，并清空计数器
        int candidate = -1;
        int count = 0;
        for (int num : nums) 
        {
            if (num == candidate)
                count++;
            else if (--count < 0) 
            {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
// 结论:时间复杂度 o(n) 空间复杂度o(1).
