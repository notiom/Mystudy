// 1。经代码随想录之后的解
// 求不相交的线,其实就是在不改变相对位置的情况下选择最长的公共子序列
public class Solution 
{
    public int MaxUncrossedLines(int[] nums1, int[] nums2) 
    {
        // 相交意味着上面数组的元素在右，而下面的元素在左
        // 经代码随想录分析,就是求最长的公共子序列
        int m = nums1.Length;
        int n = nums2.Length;

        int[,] dp = new int[m + 1,n + 1];
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(nums1[i] == nums2[j])
                {
                    dp[i + 1,j + 1] = dp[i,j] + 1;
                }
                else
                {
                    dp[i + 1,j + 1] = Math.Max(dp[i,j + 1],dp[i + 1,j]);
                }
            }
        }
        return dp[m,n];
    }
}
// 结论:时间复杂度和空间复杂度都为o(m * n)


// 可以利用滚动数组简化空间复杂度.
