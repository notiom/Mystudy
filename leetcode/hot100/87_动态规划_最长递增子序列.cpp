// 1.我自己的解
// 使用动态规划存放之前的每一个地方的最大值
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        // 思路:使用动态规划记录max子序列的最大长度
        int n = nums.size();
        // 使用一个dp数组
        vector<int> dp(n + 1,1);
        dp[0] = 0;
        dp[1] = 1;
        if(n == 0) return 0;
        for(int i = 2; i <= n; i++)
        {
           for(int j = 1;j < i;j++)
           {
                if(nums.at(i - 1) > nums.at(j - 1)) dp[i] = max(dp[i],dp[j] + 1);
           }
           maxcount = max(dp[i],maxcount);
        }
        return maxcount;
    }
private:    
    int maxcount = 1;
};
// 结论:通过 时间复杂度o(n * n),空间复杂度o(n)
// 在dp数组初始化时一定要初始化为1，因为每一个元素起始点都为1

// 2. 官方题解
// 单调栈
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        // 单调栈
        // 使用二分查找查找当前元素应该插入到vector中的位置，如果当前元素大于最后的索引，直接push
        // 否则 替换到该插入的位置，因为后续有可能出现比这串更长的串

        vector<int> stk;
        for(const int& num : nums)
        {
            auto it = lower_bound(stk.begin(), stk.end(),num);

            if(it == stk.end())
            {
                stk.push_back(num);
            }
            else
            {
                *it = num;
            }
        }
        return stk.size();
    }
};
// 结论:通过 时间复杂度o(n * logn) ,空间复杂度o(n * logn)
// 二分查找当前位置应该插入栈中的元素

// 3. 另一种写法
// 利用二分法
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        // 单调栈
        // 使用二分查找查找当前元素应该插入到vector中的位置，如果当前元素大于最后的索引，直接push
        // 否则 替换到该插入的位置，因为后续有可能出现比这串更长的串
        vector<int> tails;
        for(int num : nums)
        {
            int i = 0,j = tails.size();
            while(i < j)
            {
                int mid = i + (j - i) / 2;
                if(tails[mid] < num) i = mid + 1;
                else j = mid;
            }
            if(j == tails.size()) tails.push_back(num); //说明是在末端插入元素
            else tails.at(j) = num;

        }
        return tails.size();
    }
};
// 结论:通过 
