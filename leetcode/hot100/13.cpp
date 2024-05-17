// 1.思路:先由一个容器表示前1，2，3，n项和
// 之后找到在左边的最小值和在最右边的最大值之间的差与两个边界的最大值
// 但是在实现找左边最小值和右边最大值时无法实现
// 解决方案,两层for循环

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> sumvec;
        int n = nums.size();
        int currentsum = 0;
        for(auto const &num : nums)
        {
            currentsum += num;
            sumvec.push_back(currentsum);
        }
        int left = 0;  // 左指针
        int right = n - 1;  // 右指针
        int res = -INT_MAX; //左边最小的值
        for(int i = 0;i < n;i++)
        {
            if(sumvec[i] > sumvec[left])
            {
                continue;
            }
            int maxdis = 0; //两个差值
            for(int j = i + 1;j < n;j++)
            {
                sumvec[left] = sumvec[i];
                maxdis = sumvec[j] - sumvec[left];
                res = max(res,maxdis);
            }
        }
        return max(res,max(sumvec[0],sumvec[n - 1]));
    } 
};
//结论：算法思路错误，错例 [1,2,-1]错误
																				
//2.官方题解
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res = nums[0]; //先将结果定义为第一个元素，如果后面元素都是最大的
        int sum = 0; //计算当前和
        for(auto const &num : nums)
        {
            if(sum > 0)
                sum += num;
            else
            {
                sum = num;
            }
            res = max(res,sum);
        }
        return res;
    }
};
//结论：
