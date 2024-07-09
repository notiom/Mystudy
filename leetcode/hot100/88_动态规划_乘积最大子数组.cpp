// 1.我自己的解
// 暴力美学
class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        // 暴力求解
        // 动态规划的思路在遇到负数时不知道如何处理
        int max_product = -INT_MAX;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            for(int j = i;j < n;j++)
            {
                int product = 1;
                for(int k = i; k <= j; k++)
                {
                    product *= nums[k];
                }
                max_product = max(max_product, product);
            }
        }
        return max_product;
    }
};
// 结论:不出意外的超时了

// 2. 官方题解
// 对于c++版本，会存在溢出的情况
class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int max_product = INT_MIN;
        int64_t imax = 1, imin = 1; // 使用 int64_t 以避免溢出
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {          
            if(nums[i] < 0)
            {
                // 存在负数时，就要交换最大值与最小值了
                int64_t temp = imax;
                imax = imin;
                imin = temp;
            }

            imax = max(mul_check(imax, nums[i]), static_cast<int64_t>(nums[i]));
            imin = min(mul_check(imin, nums[i]), static_cast<int64_t>(nums[i]));

            max_product = max(max_product, static_cast<int>(imax));
        }
        return max_product;
    }

private:
    int64_t mul_check(int64_t a, int64_t b)
    {
        if (a > 0 && b > 0 && a > INT64_MAX / b) return INT64_MAX;
        if (a < 0 && b < 0 && a < INT64_MAX / b) return INT64_MAX;
        if (a > 0 && b < 0 && b < INT64_MIN / a) return INT64_MIN;
        if (a < 0 && b > 0 && a < INT64_MIN / b) return INT64_MIN;
        return a * b;
    }
};
// 结论：通过 还需要处理数据溢出的情况 时间复杂度 o(n) 空间复杂度o(1).
