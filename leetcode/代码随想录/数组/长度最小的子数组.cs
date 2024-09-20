// 1.我自己的解
// 妄图使用回溯但是失败
public class Solution 
{
    public int res = int.MaxValue;
    
    public int MinSubArrayLen(int target, int[] nums) 
    {
        backtrack(nums, target, 0, 0);
        return res == int.MaxValue ? 0 : res;
    }

    private void backtrack(int[] nums, int target, int start, int count)
    {
        if (target <= 0)
        {
            res = Math.Min(res, count);
            return; // 如果已经满足条件，停止递归
        }

        for (int i = start; i < nums.Length; i++)
        {
            backtrack(nums, target - nums[i], i + 1, count + 1); // 向后递归
        }
    }
}
// 结论:未通过 -------------------------------------

// 附录一份c#版本的快速排序,本题并未使用
private void QuickSort(int []nums,int start,int end)
    {
        if(start < end)
        {
            int middle = Partition(nums,start,end);
            QuickSort(nums,start,middle - 1);
            QuickSort(nums,middle + 1,end);
        }
    }

    private int Partition(int []nums,int start,int end)
    {
        int height = nums[end];
        int i = start - 1;
        for(int j = start;j < end;j++)
        {
            if(nums[j] > height)
            {
                i++;
                Swap(ref nums[i],ref nums[j]);
            }
        }
        // 选择出了最适合heigit的位置
        Swap(ref nums[i + 1],ref nums[end]);
        return i + 1;
    }

    private void Swap(ref int a,ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}

///2.暴力解法,双循环
public class Solution
{
    public int MinSubArrayLen(int target, int[] nums)
    {
        int sum = 0;
        int res = int.MaxValue;
        for(int i = 0;i < nums.Length;i++)
        {
            sum = 0;
            for(int j = i;j < nums.Length;j++)
            {
                sum += nums[j];
                if(sum >= target)
                {
                    res = Math.Min(res,j - i + 1);
                    break; // 直接退出
                }
            }
        }
        // 如果res没有更新过，说明没有符合条件的子数组，返回0
        return res == int.MaxValue ? 0 : res;
    }
}
// 超出时间限制

// 3.官方题解
// 使用滑动窗口遍历数组

public class Solution
{
    public int MinSubArrayLen(int target, int[] nums)
    {
        int n = nums.Length;
        int left = 0, sum = 0;
        int res = int.MaxValue;

        // 滑动窗口遍历数组
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];

            // 一旦找到符合条件的子数组，缩小窗口
            while (sum >= target)
            {
                res = Math.Min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        // 如果res没有更新过，说明没有符合条件的子数组，返回0
        return res == int.MaxValue ? 0 : res;
    }
}
// 时间复杂度o(n),空间复杂度o(1).
