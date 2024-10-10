// 1.我自己的解
// 使用动态规划寻找最长重复的数组
// 结果为动态规划的最大值
public class Solution 
{
    public int FindLength(int[] nums1, int[] nums2) 
    {
        // 使用动态规划
        int m = nums1.Length;
        int n = nums2.Length;

        int [,] dp = new int[m + 1,n + 1];
        int res = 0;

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(nums1[i] == nums2[j])
                    dp[i + 1,j + 1] = dp[i,j] + 1;
                res = Math.Max(res,dp[i + 1,j + 1]);
            }
        }
        return res;
    }
}
// 结论:时间复杂度和空间复杂度都为o(m * n);

//2.滚动数组
public class Solution 
{
    public int FindLength(int[] nums1, int[] nums2) 
    {
        // 使用滚动数组
        int m = nums1.Length;
        int n = nums2.Length;

        int [] dp = new int[m + 1];
        int res = 0;

        for(int i = 0;i < m;i++)
        {
            for(int j = n - 1;j >= 0;j--)
            {
                // 从后向前遍历,这样前面的改变就不会影响后面
                if(nums1[i] == nums2[j])
                    dp[j + 1] = dp[j] + 1;
                else
                    dp[j + 1] = 0; //如果不等于一定要赋值为0,下一个在用时不会受到影响
                res = Math.Max(res,dp[j + 1]);
            }
        }
        return res;
    }
}
// 结论:空间复杂度只有o(m).


