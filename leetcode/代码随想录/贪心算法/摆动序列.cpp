// 1.我自己的解
// 使用贪心算法坦最大的个数,从一开始就开始累加
class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        // 和分发饼干稍微有点类似,贪心的本质就是从第一个不满足的地方开始重新计数,如果有大于前面res的,就替换
        int n = nums.size();
        if(n == 1) return 1;
        int startIndex = 0;
        for(int i = 1;i < n;i++)
        {
            // 确定开始索引,如果有不同的元素,那么curres最小为2,如果没有,那就返回1
            startIndex = i + 1;
            if(nums[i] != nums[i - 1]) break;
            if(i == n - 1) return 1;
        }
        int curres = 2; // 一开始最小的子序列是2
        bool isFu = nums[startIndex - 1] - nums[startIndex - 2] > 0 ? false : true; // 从第一个位置开始累加

        for(int i = startIndex;i < n;i++)
        {
            if(((nums[i] - nums[i - 1] > 0) && isFu) || ((nums[i] - nums[i - 1] < 0) && !isFu))
            {
                // 满足当前条件,curres累加
                curres++;
                isFu = !isFu; // 取反
            }
        }
    return curres;
    }
};
// 通过 时间复杂度o(n),空间复杂度o(1).
