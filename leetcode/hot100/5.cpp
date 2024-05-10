//1.我自己的思路:
//时间复杂度O(n ** 2)
//即对第前一个元素和后一个元素依次遍历，将短边当作长，计算面积之后比较并得出最大面积

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int n = height.size();
        for(int i = 0 ;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                int chang = min(height[i],height[j]);
                int area = chang * (j - i);
                if(area > maxarea)
                {
                    maxarea = area;
                }
            }
        }
        return maxarea;
    }
};
//结论：超时，时间复杂度太高，应该需要用到动态规划。
//2.官方题解(动态规划)
定义双指针，一个向右走，一个向左走，到交汇时，即可找到最大值，原理为:当两指针向内交汇时，只有短边变大才有可能使面积变大，所以只需要向内移动短边。时间复杂度为O(n)
	
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        //双指针思路
        int n = height.size();
        //定义双指针
        int i = 0;
        int j = n - 1;
        //定义res为最终结果
        int res = 0;
        //定义area为当前面积
        int area = 0;
        //定义长
        int chang = 0;
        while(i < j)
        {
            if(height[i] <= height[j])
            {
                chang = height[i];
                area = chang * (j - i);
                i++;
            }
            else
            {
                chang = height[j];
                area = chang * (j - i);
                j--;
            }
            if(area > res)
            {
                res = area;
            }
        }
        return res;
    }
};
结论：代码略显多，比如area在两个if中都被计算
//3.官方的代码

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, res = 0;
        while(i < j) {
            res = height[i] < height[j] ? 
                max(res, (j - i) * height[i++]): 
                max(res, (j - i) * height[j--]); 
        }
        return res;
    }
};
// 改进之处为使用判断看那个变量需要++或者--，并运用max函数省去判断大小的步骤。细节为（j - i）必须放在[j++]之前，因为括号和[]优先级一样
