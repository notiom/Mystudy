// 1.我自己的解
// 注意在c#中添加Add时要new出一个新对象,如果传入引用，后续在path更新时会被覆盖
// 先进行排序,就可以进行合理的剪枝了
public class Solution 
{
    private IList<IList<int>> res = new List<IList<int>>(); 
    public IList<IList<int>> CombinationSum(int[] candidates, int target) 
    {
        // 与组合总和差别是这个元素可以无限制的被重复选取
        int n = candidates.Length;
        IList<int> path = new List<int>();
        Array.Sort(candidates);
        backtrack(candidates,path,target,0);
        return res;

    }

    private void backtrack(int[] candidates, IList<int> path,int target,int start)
    {
        // 在回溯中需要声明start变量
        // 不然每次循环都是从0开始

        if(target == 0)
        {
            res.Add(new List<int>(path));
            return;
        }

        for(int i = start;i < candidates.Length;i++)
        {
            if(target - candidates[i] < 0)
            {
                // 因为数组已排序，后续的数更大，直接剪枝
                break;
            } 
            path.Add(candidates[i]);
            backtrack(candidates,path,target - candidates[i],i);
            path.RemoveAt(path.Count - 1);
        }
    }
}
// 结论:通过 时间复杂度o(n * 2 ^ n) 空间复杂度o(target)
