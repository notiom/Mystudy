// 官方题解
// 要将所有的数输出之后比较才知道结果
public class Solution 
{
    public bool ConfusingNumber(int n) 
    {
        List<int> result = new List<int>() {0,1,-1,-1,-1,-1,9,-1,8,6};
        int m = 0;
        int x = n;
        while(n != 0)
        {
            int temp = n % 10;
            if(result[temp] == -1) return false;
            m = m * 10 + result[temp];
            n /= 10;
        }
        if(m == x) return false;
        return true; 
    }
}
// 结论:通过 时间复杂度为o(logn),空间复杂度为o(n).
