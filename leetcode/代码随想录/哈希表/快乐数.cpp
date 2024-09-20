// 1.我自己的解
// 使用递归判断是否是快乐数并且是否在之前的哈希表中出现过
class Solution 
{
public:
    bool isHappy(int n) 
    {
        // 本题的原理是将一个数反复平方，能否成为快乐数的关键是没有重复的元素
        // 使用哈希表记录一个used,如果本轮结果为哈希表中已经取到的值,则返回false
        // 先检查当前数是否是快乐数
        if(n == 1) return true;
        // 判断之前出现过否
        if(used.find(n) != used.end()) return false;
        used.insert(n);
        int res = squareRes(n);
        return isHappy(res);
    }
private:
    unordered_set<int> used;
    int squareRes(int n)
    {
        int res = 0;
        // 1921 -> 1 * 1
        // 192 -> 2 * 2
        // 19 -> 9 * 9
        // 1 -> 1 * 1
        while(n != 0)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
       return res;
    }
};
// 结论: 时间复杂度o(logn),空间复杂度o(logn).

// 2.cs版本的哈希表版本(HashSet)
public class Solution 
{
    private HashSet<int> used = new HashSet<int>();
    public bool IsHappy(int n) 
    {
        if(n == 1) return true;
        if(used.Contains(n)) return false;
        used.Add(n);
        return IsHappy(getNum(n));
    }

    private int getNum(int n)
    {
        int res = 0;
        while(n != 0)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
}
