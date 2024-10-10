// 1.我自己的解
// 使用一个二维数组,一个维度记录最长的长度,第二个维度记录以他结尾的元素
public class Solution 
{
    public int LengthOfLIS(int[] nums) 
    {
        // 使用动态规划确定以最后一个元素结尾时的最长子序列,之后在遍历之前的元素,看当前是否可以加1
        // dp数组应该是dp[n + 1][2]
        // 第一个维度表示最长长度,第二个维度表示当前元素
        int n = nums.Length;

        int[,] dp = new int[n + 1, 2];
        dp[0,0] = 0;
        dp[0,1] = 0;
        int res = int.MinValue;
        for(int i = 0;i < n;i++)
        {
            dp[i + 1,0] = 1;
            dp[i + 1,1] = nums[i]; 
            for(int j = 0;j <= i;j++)
            {
                if(nums[i] > dp[j,1])
                {
                    // 严格递增
                    dp[i + 1,0] = Math.Max(dp[i + 1, 0],dp[j,0] + 1); 
                }
            }
            res = Math.Max(res,dp[i + 1,0]);
        }
        return res;
    }
}
// 结论:时间复杂度o(n * n),空间复杂度o(n).

// 2.改进版本,不需要使用两个维度
public class Solution 
{
    public int LengthOfLIS(int[] nums) 
    {
        // 使用动态规划确定以最后一个元素结尾时的最长子序列,之后在遍历之前的元素,看当前是否可以加1
        // dp数组应该是dp[n]
        // 第一个维度表示最长长度
        int n = nums.Length;

        int[] dp = new int[n];
        dp[0] = 1;
        int res = 1;
        for(int i = 1;i < n;i++)
        {
            dp[i] = 1;
            for(int j = 0;j < i;j++)
            {
                if(nums[i] > nums[j])
                {
                    // 严格递增
                    dp[i] = Math.Max(dp[i],dp[j] + 1); 
                }
            }
            res = Math.Max(res,dp[i]);
        }
        return res;
    }
}
// 3.贪心算法
// 使用二分查找判断插入元素的位置
public class Solution 
{
    public int LengthOfLIS(int[] nums) 
    {
        // 使用贪心加二分查找算法
        List<int> vec = new List<int>();
        vec.Add(nums[0]);
        int n = nums.Length;
        for(int i = 1;i < n;i++)
        {
            int index = BinarySearch(vec,nums[i]);
            if(index >= vec.Count)
            {
                vec.Add(nums[i]);
            }
            else
            {
                vec[index] = nums[i];
            }
        }
        return vec.Count;
    }

    private int BinarySearch(List<int> nums,int num)
    {
        // 返回插入位置索引的二分查找算法
        int left = 0;
        int right = nums.Count - 1;
        while(left <= right)
        {
            int mid = (left + right) >> 1;
            if(num > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
}
}
// 结论:时间复杂度o(n * logn).
