// 1.我自己的解
// 思路:选用一个从后向前遍历的容器
// 使用回溯向前遍历每个数据
// 并记录最小的count
class Solution 
{
public:
    int numSquares(int n) 
    {
        // 先选择一个最接近但不超过n的完全平方数
        // 判断只用他是否可以到达n并记录现有的次数
        // 如果不行,在设计其他的搭配方式
        // 有点像回溯
        int maxsquare = (int)sqrt(n); //相当于向下取整
        for(int i = 1;i <= maxsquare;i++)
        {
            nums.push_back(i * i);
        }
        dfs(nums.size(),0,n);
        return count;
    }
private:
    int count = INT_MAX; //记录可能的最小值结果
    // 存放可用元素的容器
    vector<int> nums;

    void dfs(int n,int curcount,int target)
    {
        for(int i = n - 1;i >= 0;i--)
        {
            if(nums.at(i) > target) continue;
            curcount++;
            if(curcount >= count) // 剪枝，如果当前计数已经大于等于现有最小计数，直接返回
            {
                curcount--;
                return;
            }
            if(nums.at(i) == target)
            {
                // 已经找到目标值
                // 但不确定是不是最小
                count = min(count, curcount);
                curcount--; //回溯
                return;;
            }
            dfs(n,curcount,target - nums.at(i));
            curcount--;
        }
    }
};
// 结论:通过，时间复杂度o(2 * sqrt(n))，空间复杂度o(sqrt(n))
// 注意，回溯需要自己手动去撤销选择的值，而不能使程序自己撤销，因为自增会不准确
