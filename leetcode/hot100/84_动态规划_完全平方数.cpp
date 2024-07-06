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
// 代码缺点:每次从当前元素都会在看一遍原先比当前第一个元素大的元素，但其实不必要，只需要看比自己小的数即可

// 2. 改进版本
// 让其只计算不大于自己的索引
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
        dfs(nums.size() - 1,0,n);
        return count;
    }
private:
    int count = INT_MAX; //记录可能的最小值结果
    // 存放可用元素的容器
    vector<int> nums;

    void dfs(int n,int curcount,int target)
    {
        for(int i = n;i >= 0;i--)
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
            dfs(i,curcount,target - nums.at(i));
            curcount--;
        }
    }
};
// 结论:时间复杂度O(N * Sqrt(N))

// 3.官方题解
// 动态规划
// 动态规划的核心是后面的数是通过前面的数计算出来的
class Solution 
{
public:
    int numSquares(int n) 
    {
       // 动态规划
       // 动态转移方程为f(i) = 1 + min(f(i - 1),f(i - 4))...

       vector<int> f(n + 1,0); //有时会计算出f(0)的情况
       for(int i =1;i <= n;i++)
       {
            // 动态规划的核心思路为后面的数一定是用到前面的数
            int minn = INT_MAX;
            for(int j = 1;j <= sqrt(i);j++)
            {
                minn = min(minn,f[i - j * j]);
            }
            f[i] = minn + 1;
       }
       return f[n];
    }
};
// 结论：通过 和改进版本的回溯时间空间复杂度相同
