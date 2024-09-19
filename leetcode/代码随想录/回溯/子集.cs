// 1.我自己的解
// 回溯
public class Solution 
{
    private IList<IList<int>> res;
    public IList<IList<int>> Subsets(int[] nums) 
    {
        // 由于元素顺序不同,所以只需要顺序递归过去即可
        List<int> path = new List<int>();
        res = new List<IList<int>>();
        backtrack(nums,path,0);
        return res;
    }

    private void backtrack(int[] nums,List<int> path,int start)
    {
        res.Add(new List<int>(path));
        for(int i = start;i < nums.Length;i++)
        {
            path.Add(nums[i]);
            backtrack(nums,path,i + 1);
            path.RemoveAt(path.Count - 1);
        }
    }
}
// 结论:时间复杂度为o(2 ^ n)，空间复杂度为o(N * 2 ^ n).

// 2.迭代法
// 使用c#迭代法
public class Solution 
{
    private IList<IList<int>> res;
    public IList<IList<int>> Subsets(int[] nums) 
    {
        // 由于元素顺序不同,所以只需要顺序递归过去即可
        res = new List<IList<int>>();
        res.Add(new List<int>()); // 添加空集
        foreach(int i in nums)
        {
            int count = res.Count;
            for(int j = 0;j < count;j++)
            {
                List<int> temp = new List<int>(res[j]);
                temp.Add(i);
                res.Add(new List<int>(temp));
            }
        }
        return res;
    }
}
// 结论:通过
