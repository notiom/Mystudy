// 1.GPT的解
// 控制了一个索引来判断上一个还在匹配的元素位于哪个位置
class Solution
{
public:
    int longestValidParentheses(string s) 
    {
        // 本题有一种暴力枚举的方式,先将所有元素放入进去，如果已经匹配到的子串就删除
        // 要不匹配类型为()(),要不为(())

        // 从遇到第一个)开始向左寻找，如果是),直接将其元素去掉
        // 如果遇到的(,那么在向下遍历,如果该元素是)，那么应该在向左寻找，知道不满足既定条件

        int n = s.length();
        int maxLen = 0; // res
        int curLen = 0;
        stack<int> stk;
        stk.push(-1); //栈顶元素始终是最长的一开始索引
        for (int i = 0; i < n; i++)
        {
            if(s.at(i) == '(')
            {
                // 匹配遇到的(
                stk.push(i);
            }
            else
            {
                // 当前匹配成功
                stk.pop();
                if(stk.empty())
                {   
                    // 说明}多了 
                    // 将当前位置索引push进去，作为一个新的开始最大的长度开始的位置
                    stk.push(i);
                }
                else
                {
                    // 说明可能匹配的最大长度
                    maxLen = max(maxLen,i - stk.top());
                }
            }
        }
        return maxLen;
    }
};
// 结论:时间复杂度和空间复杂度都是o(n).
