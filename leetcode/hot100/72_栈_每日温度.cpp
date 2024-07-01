// 1.我自己的解
// 暴力解法,依次向后遍历直到找到后续有元素大于当前的索引号

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        // 利用递减栈的思路，保证栈中所有元素都是递减的
        int n = temperatures.size();
        stack<int> stk;
        vector<int> res(n, 0);
        for(int i = 0;i < n;i++)
        {
            while(!stk.empty() && temperatures.at(stk.top()) < temperatures.at(i))
            {
                int index = stk.top();
                stk.pop(); //出栈
                res.at(index) = i - index;
            }
            stk.push(i);
        }
        return res;
    }
};
// 结论:未通过，超出时间限制
// 时间复杂度,o(n * n) 

// 2.官方题解
// 单调递减栈,栈中元素始终是递减排列，这样在循环n此结束后栈中还剩的索引值就表示后续没有比他更高的温度出现了
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        // 利用递减栈的思路，保证栈中所有元素都是递减的
        int n = temperatures.size();
        stack<int> stk;
        vector<int> res(n, 0);
        for(int i = 0;i < n;i++)
        {
            while(!stk.empty() && temperatures.at(stk.top()) < temperatures.at(i))
            {
                int index = stk.top();
                stk.pop(); //出栈
                res.at(index) = i - index;
            }
            stk.push(i);
        }
        return res;
    }
};
// 结论:通过，单调递减栈，
// 时间复杂度: o(n)
