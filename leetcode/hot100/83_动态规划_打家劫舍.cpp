// 1.彬弟的解
// 使用动态规划两个容器保存偷与不偷的最大值
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> res1(n + 1,0);
        vector<int> res2(n + 1,0);
        // 动态规划方程
        // res1[i] = nums[i - 1] + res2[i - 1];
        // res2[i] = max(res1[i - 1], res2[i - 1])
        for(int i = 1; i <= n; i++)
        {
            res1[i] = nums[i - 1] + res2[i - 1];
            res2[i] = max(res1[i - 1], res2[i - 1]);
        }
        return max(res1[n], res2[n]);
    }
};
// 结论:时间复杂度和空间复杂度o(n).

// 2.空间优化
// 由于该方程只使用了上一次的值,所以只需要常数级空间复杂度

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int res1 = 0;
        int res2 = 0;;
        // 动态规划方程
        // res1[i] = nums[i - 1] + res2[i - 1];
        // res2[i] = max(res1[i - 1], res2[i - 1])
        for(int i = 1; i <= n; i++)
        {
            int temp = res1;
            res1 = nums[i - 1] + res2;
            res2 = max(temp, res2);
        }
        return max(res1, res2);
    }
};

// 结论:时间复杂度o(n)空间复杂度o(1).

// 3.官方题解
// 另一种动态规划方程
// f(k)=max{f(k−1),Hk−1+f(k−2)}
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        // f(k)=max{f(k−1),Hk−1+f(k−2)} 当前房子的最大金额为（偷当前房子 + 前2个房子的金额）和 偷前一个房子的金额取最大值
        // f(0) = 0;
        // f(1) = H0;
        int pre1 = 0; // k - 2
        int pre2 = nums[0];// k - 1
        for(int i = 1;i < n;i++)
        {
            int temp = pre2;
            pre2 = max(pre2,nums.at(i) + pre1);
            pre1 = temp;
        }
        return pre2;
    }
};
// 结论:更好理解

// 4.我自己的解
// 打家劫舍2
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> res1(n + 1,0);
        vector<int> res2(n + 1,0);
        // 动态规划方程
        // res1[i] = nums[i - 1] + res2[i - 1];
        // res2[i] = max(res1[i - 1], res2[i - 1])
        for(int i = 2; i <= n; i++)
        {
            res1[i] = nums[i - 1] + res2[i - 1];
            res2[i] = max(res1[i - 1], res2[i - 1]);
        }
        int res = max(res1[n], res2[n]);

        res1.clear();
        res2.clear();
        for(int i = 1; i < n; i++)
        {
            res1[i] = nums[i - 1] + res2[i - 1];
            res2[i] = max(res1[i - 1], res2[i - 1]);
        }

        return max(res,max(res1[n - 1],res2[n - 1]));
    }
};
