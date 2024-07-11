// 1.我自己的解
// 思路使用排序数组使得左指针和右指针的和一样

vector<int> operator+(const vector<int>& nums1,const vector<int>& nums2)
{
    vector<int> res(nums1);
    res.insert(res.end(),nums2.begin(),nums2.end());
    return res;
}
class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        // 思路,先排序，之后在比较元素是否可以被切分
        // 比较方法为两个指针，左指针记录前面的前缀和，右指针记录后面的元素和
        if(nums.size() <= 1) return false;
        nums = quickSort(nums); 
        int left = 0,right = nums.size() - 1;
        int preSum = 0,postSum = 0;

        while(left < right)
        {
            postSum += nums.at(right);

            while(preSum < postSum)
            {
                // 表明当前前缀和还没有大于后缀
                preSum += nums.at(left);
                left++;
            }
            right--;
            if(left == right) return false;
        }
        if(preSum == postSum) return true;
        return false;
    }
    vector<int> quickSort(vector<int>& nums)
    {
        int n = nums.size();
        if(n <= 1) return nums;

        // 进行中点的排序
        int pivot = (n - 1) >> 1;
        vector<int> left;
        vector<int> right;
        vector<int> middle;
        for(int i = 0; i < n;i++)
        {
            if(nums.at(i) < nums.at(pivot))
            {
                // 应该放到左容器中
                left.push_back(nums.at(i));
            }
            else if(nums.at(i) > nums.at(pivot))
            {
                // 应该放到右容器
                right.push_back(nums.at(i));
            }
            else
            {
                middle.push_back(nums.at(i));
            }
        }
        return quickSort(left) + middle + quickSort(right);
    }
};
// 结论: 思路错误 和可以是不连续的元素

// 根据题解思路改进，可以将问题优化为找到等于数组和一半的元素子集

// 2.结合思路改进
// 要选择一个元素是选择还是不选择
// 动态规划的核心就是要保证写出动态规划方程
class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        // 找到nums.sum / 2的 元素子集
        // 经典的0 - 1 背包问题
        int n = nums.size();
        int numsSum = 0;
        for(int i = 0; i < n; i++)
        {
            numsSum += nums.at(i);
        }
        if (numsSum % 2 != 0 || n <= 1) return false; // 奇数直接返回

        int target = numsSum / 2;
        // 最终只需要返回dp[n][target]的值即可
        vector<vector<bool>> dp(n,vector<bool>(target + 1,false)); // 定义dp数组，dp[i][j]表示前i个元素是否可以组成和为j
        dp[0][0] = true;
        if(nums.at(0) <= target) dp[0][nums.at(0)] = true;
        for(int i = 1;i < n;i++)
        {
            dp[i][0] = true;

            for(int j = 1;j <= target;j++)
            {
                // 此处需要判断索引值是否取正数
                dp[i][j] = dp[i - 1][j];
                if(j  >= nums.at(i)) dp[i][j] = dp[i - 1][j] || dp[i  - 1][j - nums.at(i)];
            }
        }
        return dp[n - 1][target];     
    }
};

// 结论: 时间复杂度 o(n * target) 空间复杂度 o(n * target)

// 3.剪枝化之后的代码
class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        // 找到nums.sum / 2的 元素子集
        // 经典的0 - 1 背包问题
        int n = nums.size();
        int numsSum = 0;
        for(int i = 0; i < n; i++)
        {
            numsSum += nums.at(i);
        }
        if (numsSum % 2 != 0 || n <= 1) return false; // 奇数直接返回

        int target = numsSum / 2;
        // 最终只需要返回dp[n][target]的值即可
        vector<bool> dp(target + 1,false); // 定义dp数组，dp[i][j]表示前i个元素是否可以组成和为j
        dp[0] = true;
        if(nums.at(0) <= target) dp[nums.at(0)] = true;
        for(int i = 1;i < n;i++)
        {
            for(int j = target;j >= nums.at(i);j--)
            {
                // 如果不是逆序遍历就会导致当前某个元素的dp[j]直接被之前的值更新掉
                // 利用正整数剪枝
                dp[j] = dp[j] || dp[j - nums.at(i)];

            }
        }
        return dp[target];     
    }
};
// 结论:通过
