// 1.彬弟的解
// 使用动态规划两个容器保存偷与不偷的最大值
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> res1(n + 1,0);
        vector<int> res2(n + 1,0);
        // 动态规划方程
        // res1[i] = nums[i - 1] + res2[i - 1];
        // res2[i] = max(res1[i - 1], res2[i - 1])
        for(int i = 1; i <= n; i++)
        {
            res1[i] = nums[i - 1] + res2[i - 1];
            res2[i] = max(res1[i - 1], res2[i - 1]);
        }
        return max(res1[n], res2[n]);
    }
};
// 结论:时间复杂度和空间复杂度o(n).

//2.空间优化

//3.官方题解


// 4.我自己的解
// 打家劫舍2
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> res1(n + 1,0);
        vector<int> res2(n + 1,0);
        // 动态规划方程
        // res1[i] = nums[i - 1] + res2[i - 1];
        // res2[i] = max(res1[i - 1], res2[i - 1])
        for(int i = 2; i <= n; i++)
        {
            res1[i] = nums[i - 1] + res2[i - 1];
            res2[i] = max(res1[i - 1], res2[i - 1]);
        }
        int res = max(res1[n], res2[n]);

        res1.clear();
        res2.clear();
        for(int i = 1; i < n; i++)
        {
            res1[i] = nums[i - 1] + res2[i - 1];
            res2[i] = max(res1[i - 1], res2[i - 1]);
        }

        return max(res,max(res1[n - 1],res2[n - 1]));
    }
};
