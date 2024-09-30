// 1.我自己的解
// 使用动态规划
public class Solution 
{
    public int MaxSubArray(int[] nums) 
    {
        // 子数组必须连续
        // 可以使用动态规划
        int n = nums.Length;
        // dp数组的含义是以他结束的最大的子数组的和
        int []dp = new int[n + 1];
        int res = int.MinValue;
        for(int i = 1;i <= n;i++)
        {
            dp[i] = Math.Max(dp[i - 1] + nums[i - 1],nums[i - 1]);
            res = Math.Max(res,dp[i]);
        }
        return res;
    }
}
// 结论:通过 时间复杂度和空间复杂度都为o(n).

// 2.动态规划优化空间复杂度
public class Solution 
{
    public int MaxSubArray(int[] nums) 
    {
        // 子数组必须连续
        // 可以使用动态规划
        int n = nums.Length;
        // dp的含义是以他结束的最大的子数组的和
        int dp = 0;
        int res = int.MinValue;
        for(int i = 0;i < n;i++)
        {
            dp = Math.Max(dp + nums[i],nums[i]);
            res = Math.Max(res,dp);
        }
        return res;
    }
}
// 结论:通过 时间复杂度o(n),空间复杂度o(1).

// 3.贪心算法
// 和动态规划一致
// 核心思想是通过局部最优推出整体最优
public class Solution 
{
    public int MaxSubArray(int[] nums) 
    {
        // 子数组必须连续
        // 可以使用贪心算法
        int n = nums.Length;
        // curSum的含义为当前前面元素的和
        int curSum = 0;
        int res = int.MinValue;
        for(int i = 0;i < n;i++)
        {
            curSum += nums[i];
            if(nums[i] > curSum) 
            {
                // 从当前位置开始重新计数
                curSum = nums[i];
            }
            // 记录当前最大的元素总和
            res = Math.Max(res,curSum);
        }
        return res;
    }
}
// 结论:通过 时间复杂度o(n),空间复杂度o(1).
