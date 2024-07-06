// 1.我自己的解
// 通过递归调用，会超出时间限制 
class Solution 
{
public:
    int climbStairs(int n) 
    {
        // 第一思路:通过递归计算爬到n阶的方法
        // 只需要计算爬到n - 1阶的方法和n - 2阶的方法
        // 然后将两者相加得到n阶的方法
        if (n <= 2) return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
// 结论：超时
// 总结：因为在每次递归的时候都重复的计算以前已经计算过的结果

//2. 我自己的改进版本
// 从前往后计算，将前面每次计算后的结果都保存下来，之后可以直接相加

class Solution 
{
public:
    int climbStairs(int n) 
    {
        // 第二思路:通过两个变量保存之前计算的值
        if(n <= 2) return n;
        int left = 1, right = 2; //保存了第0个位置和第1个位置的值
        for(int i = 3;i < n;i++)
        {
            if(i%2 != 0)
            {
                // 此时应该只更新奇数个位置
                left = left + right;
            }
            else
            {
                // 此时更新偶数个位置
                right = left + right;
            }
        }
        return left + right;
    }
};
// 结论:通过 时间复杂度o(n) 空间复杂度o(1).
// 需要区别当前遍历的位置是奇数还是偶数，因为每次只更新一个位置即可

// 3.官方题解改进动态规划.
// 取消了if判断是奇数还是偶数，每次都更新左边的块
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};
// 结论:通过

//4.递推公式
// x^2 = x + 1
// 任何线性关系式都可以通过递推公式求解
// f(n)=c1 * x1^n + c2 * x2^n
// f(1) = 1, f(2) = 2

​
