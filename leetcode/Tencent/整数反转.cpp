// 1.我自己的解
// 本题对于c++而言要处理号整型相乘
class Solution 
{
public:
    int reverse(int x) 
    {
        stack<int> arr;
        bool isFu = false;
        if(x < 0) isFu = true;
        int temp = x;
        while(temp != 0)
        {
            int a = temp % 10;
            temp /= 10;
            arr.push(a);
        }

        long long res = 0;
        long long multi = 1;
        while(!arr.empty())
        {
            // 如果arr不为空,则继续循环
            int top = abs(arr.top());
            res += top * multi;
            if(res > INT_MAX) return 0;
            multi *= 10;
            arr.pop();
        }
        return isFu? -(int)res : (int)res;
    }
};
// 结论:时间复杂度和空间复杂度都为o(logn).
