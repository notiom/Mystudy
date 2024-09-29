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

// 2.动态规划
// 选取一个波峰和波谷
class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        // 和分发饼干稍微有点类似,贪心的本质就是从第一个不满足的地方开始重新计数,如果有大于前面res的,就替换
        int n = nums.size();
        // 使用动态规划
        // dp[i][0]表示当前作为波峰的最大值
        // dp[i][1]表示当前作为波谷的最大值
        vector<std::pair<int,int>> dp(n);
        dp[0].first = 1;
        dp[0].second = 1;
        for(int i = 1;i < n;i++)
        {
            dp[i].first = dp[i].second = 1; // 先将1赋值

            for(int j = 0;j < i;j++)
            {
                // 将波峰赋值,为上一次迭代的最大值或者当前元素为波谷时的最大值
                if(nums[j] < nums[i]) dp[i].first = max(dp[i].first,dp[j].second + 1);
                // 将波谷赋值,为上一次迭代的最大值或者当前元素为波峰时的最大值
                if(nums[j] > nums[i]) dp[i].second = max(dp[i].second,dp[j].first + 1);
            }

        }
        return max(dp[n - 1].first,dp[n - 1].second);
    }
};
// 结论:通过 时间复杂度o(n  * n),空间复杂度o(n).
