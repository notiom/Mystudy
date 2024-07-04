// 1.我自己的解
// 只需要计算当前能跳到的最大距离即可，如果这个最大距离超过了索引长度，就表示可以到达最后一个索引位置。
// 与此同时，需要注意，当前可跳为0时并且maxindex为当前index时，表示无法跳出当前格子，直接返回false
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        // 不断更新可以跳到的最后格子，如果这个值大于数组长度，那么表示可以跳跃成功
        int n = nums.size();
        if(n == 1) return true;
        int maxindex = 0;
        for(int i = 0; i < n - 1;i++)
        {
            // 遍历应该不能遍历到最后一个下标
            maxindex = max(maxindex,i + nums.at(i));
            if(nums.at(i) == 0 && maxindex == i) return false;
            if(maxindex >=  n - 1)
            {
                return true;
            }
        }
        return false;
    }
};
// 结论:通过
