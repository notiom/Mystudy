// 1.我自己的解
// 利用栈的先进后出思想实现括号匹配
public class Solution 
{
    private Stack stk = new Stack();
    public bool IsValid(string s) 
    {
        foreach(char single in s)
        {
            // 利用栈的思想
            if(single == '(' || single == '[' 
            || single == '{')
            {
                stk.Push(single);
                continue;
            }

            if(stk.Count == 0 && (single == ']' ||
             single == ')' || single == '}'))
            {
                // 栈为空并且single元素是右半边的元素
                return false;
            }

            if(((char)stk.Peek() == '[' && single == ']') || 
            ((char)stk.Peek() == '{' && single == '}') || 
            ((char)stk.Peek() == '(' && single == ')'))
             {
                // 移除栈顶元素
                stk.Pop();
             }

             else
             {
                // 移除栈顶元素
                return false;
             }
        }

        if(stk.Count == 0) return true;
        return false;
    }
}
// 结论: 通过 时间复杂度和空间复杂度都为o(n).
