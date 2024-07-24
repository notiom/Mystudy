// 1.我自己的解
// 暴力解法加剪枝操作
class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            // 如果当前高度已经为0，直接跳过
            if (heights[i] == 0) continue;

            int minHeight = heights[i];
            for(int j = i; j < n; j++)
            {
                // 有0就跳过
                if(heights[j] == 0) break;

                // j == i的情况是为了将当前值也记录上
                int S_size = j - i + 1;
                // 将当前高度作为末位高度来计算
                minHeight = min(minHeight, heights[j]);
                int curmax = minHeight * S_size;
                res = max(res, curmax);

                // 剪枝：如果当前的最小高度乘以剩余的宽度小于当前的最大面积，则停止计算
                if (minHeight * (n - i) < res) break;
            }
        }
        return res;
    }
};
// 结论:通过 时间复杂度o(n * n),空间复杂度o(n).

// 2.暴力解法改进算法
// 使用遍历算法，以当前为中心向两边延伸的最大矩形面积

class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        // 当前思路是利用栈保存元素
        // 当当前元素小于栈顶元素时，将所有元素出栈并记录当前的最大交叉面积
        int n = heights.size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int left = i;
            while(left > 0 && heights[left - 1] >= heights[i])
            {
                left--;
            }
            int right = i;
             while(right < n - 1 && heights[right + 1] >= heights[i])
            {
                right++;
            }
            
            int width = right - left + 1;
            res = max(res, heights[i] * width);
        }
        return res;
    }
};
// 该暴力解法超时.

// 3.官方题解
// 单调栈

class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
       // 一左一右两个哨兵
       // 使用单调栈的思路。保证栈中元素是升序排列
        int n = heights.size();
        if(n == 1) return heights[0];

        int res = 0;
        stack<int> stk;

        for(int i = 0; i < n; i++)
        {
            //遍历每个元素保证栈中元素递增
            while(!stk.empty() && heights[stk.top()] > heights[i])
            {
                int length = heights[stk.top()];
                stk.pop();
                int width = i; // 要保证他是最左边的元素时也能计算
                if(!stk.empty()) width = i - stk.top() - 1;
                res = max(res,width * length);
            }
            stk.push(i);
        }

        // 要保证栈到最后也是空的
        while(!stk.empty())
        {
            int length = heights[stk.top()];
            stk.pop();
            int width = n; // 设置一个虚拟宽度在最右边
            if(!stk.empty()) width = n - stk.top() - 1;
            res = max(res, width * length);
        }
        return res;  // 最后返回结果
    }
};
// 结论:通过 时间复杂度 o(n) 空间复杂度o(n).
