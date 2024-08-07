// 1.我自己的解
// 使用0 - 1背包
public class Solution 
{
    public bool CanPartition(int[] nums) 
    {
        int numsum = nums.Sum();
        if(numsum % 2 != 0) return false;
        numsum /= 2;
        // 0 - 1背包问题看是否可以将这个背包装满
        int [,] dp = new int[nums.Length,numsum + 1];
        for(int i = nums[0]; i <= numsum; i++)
        {
            dp[0,i] = nums[0];
        }

        for(int i = 1;i < nums.Length; i++)
        {
            for(int j = 1;j <= numsum;j++)
            {
                if(j < nums[i]) dp[i,j] = dp[i - 1,j];
                else dp[i,j] = Math.Max(dp[i - 1,j], nums[i] + dp[i - 1,j - nums[i]]);
            }
        }
        if(dp[nums.Length - 1,numsum] == numsum) return true;
        else return false;

    }
}
// 结论:通过 时间复杂度和空间复杂度o(n * nums.Sum / 2)


//2. 优化空间复杂度
public class Solution 
{
    public bool CanPartition(int[] nums) 
    {
        int numsum = nums.Sum();
        if(numsum % 2 != 0) return false;
        numsum /= 2;
        // 0 - 1背包问题看是否可以将这个背包装满
        int [] dp = new int[numsum + 1];
        for(int i = 1;i < nums.Length; i++)
        {
            for(int j = numsum;j >= nums[i];j--)
            {
                dp[j] = Math.Max(dp[j], nums[i] + dp[j - nums[i]]);
            }
        }
        if(dp[numsum] == numsum) return true;
        else return false;
    }
}
// 结论:通过
