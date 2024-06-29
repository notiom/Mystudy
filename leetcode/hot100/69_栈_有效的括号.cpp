//1.我自己的解
// 思路:利用栈实现括号匹配
class Solution 
{
public:
    bool isValid(string s) 
    {
        // 思路:使用stack存储，如果匹配的不满足，直接return false
        stack<char> stk;
        for(const char& single : s)
        {
            // 如果是左括号入栈，并跳过本轮循环
            if(single == '(' || single == '{' || single == '[')
            {
                stk.push(single);
                continue;
            }
            // 如果是右括号且前面没有左括号，直接return false
            if(stk.empty()) return false;
            char curchar = stk.top();

            // 如果前面有左括号，但不匹配，return false
            if(    curchar == '(' && single != ')'
                || curchar == '{' && single != '}'
                || curchar == '[' && single != ']' )        
            {
                return false;
            }    
            stk.pop(); //出栈
        }
        // 循环结束后,判断栈是否为空，如果不为空则可能是((()) 有些左括号没有与之匹配的右括号，返回false
        if(stk.empty()) return true;
        return false;
    }
};
// 结论：通过
