// 1.我自己的解
// 使用哈希表进行计数
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> count;
        for(int num : nums)
        {
            count[num]++;
            if(count[num] == 2)
            {
                return num;
            }
        }
        return -1;
    }
};
// 结论:通过 时间复杂度 o(n) 空间复杂度o(n)
// 但是需要设计空间复杂度为o(1)的算法

// 2. 官方题解
// 龟兔赛跑算法
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        // 弗洛伊德龟兔赛跑算法
        int slow = 0,fast = 0;
        slow = nums.at(slow);
        fast = nums.at(nums.at(fast));
        // 寻找交点
        while(slow != fast)
        {
            slow = nums.at(slow);
            fast = nums.at(nums.at(fast));
        }

        // 寻找循环的起点
        fast = 0;
        while(slow!= fast)
        {
            slow = nums.at(slow);
            fast = nums.at(fast);
        }
        return slow;
    }
};
// 结论:通过 空间复杂度o(1).

