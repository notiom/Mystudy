// 1.我自己的解
// 排列组合
class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        // 其实本题是一个排列组合
        // 总步数中(m + n - 2)中选择出m - 1个步数去走列
        int di = m + n - 2;
        if(di == 0) return 1;
        int ni = m - 1;
        // C(di,ni)= di/1 * di-1/2 * di-n+1/n
        long long result = 1;
        for(int i = 1;i <= ni;i++)
        {
            result = result * (di - ni + i) / i;
        }
        return static_cast<int>(result);
    }
};
// 结论:大数一定能被小数除
// 通过 时间复杂度o(m - 1 * log (m - 1))
