// 1.我自己的解
// 使用动态规划
public class Solution 
{
    public int Fib(int n) 
    {
        List<int> result = new List<int>(new int[n + 1]);
        if(n <= 1) return n;
        result[0] = 0;
        result[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            result[i] = result[i - 1] + result[i - 2];
        }
        return result[n];
    }
}
// 结论:时间复杂度o(n),空间复杂度o(n),可以优化为o(1).

// 2. 优化空间复杂度
public class Solution 
{
    public int Fib(int n) 
    {
        List<int> result = new List<int>(new int[n + 1]);
        if(n <= 1) return n;
        int pre1 = 0;
        int pre2 = 1;
        for(int i = 2;i <= n;i++)
        {
            int temp = pre2;
            pre2 = pre1 + pre2;
            pre1 = temp;
        }
        return pre2;
    }
}

// 3.
