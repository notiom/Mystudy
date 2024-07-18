// 1.毫无头绪，因为计算面积没有思路
// 2.官方题解，按行求面积
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int res = 0;//返回的总和
        int maxheight = maxnum(height);
        int n = height.size();
        for(int i =1;i <=maxheight;i++)
        {
            //大循环是层数，分别求每层的雨水量
            bool isupdate = false;
            int temp = 0;
            for(int j = 0;j < n;j++)
            {
                if(isupdate && height[j] < i)
                {
                    //height等于层数就没有必要更新了
                    temp++;
                }
                if(height[j] >= i)
                {
                    res = res + temp;
                    temp = 0;
                    isupdate = true;
                }
            }
        }
        return res;
    }

private:
    int maxnum(vector<int> &height)
    {
    // 使用 std::max_element 获取最大元素的迭代器
    auto max_it = std::max_element(height.begin(), height.end());
    // 检查我们是否找到了一个有效的迭代器
    if (max_it != height.end()) 
    {
        return *max_it;
    } 
    else 
    {
        return 0;
    }
    }
};

// 结论:利用每行的面积分别求，设置一个isupdate变量来确定是否需要更新temp，只要开始更新，后面的数都可以继续累加，因为害怕因为开始全是0，那么这些地方没法接雨水，需要找到第一堵墙，而到最高层时，如果找不到height[j] > i,那么累加的temp也没有意义
	
// 3.按列求解
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0; //定义输出的结果
        int leftmax = 0; //定义左边最高的列
        int rightmax = 0;//定义右边最高的列
        int boolupdate = 0; //i为第一个不是0的索引值
        bool isright = true; //判断右边的最大墙是否被覆盖
        int n = height.size(); //容器列数
        //剔除最左边为0的情况，即设置一个开始标志位
        while(boolupdate < n)
        {
            if(height[boolupdate]!= 0)
            {
                break;
            }
            boolupdate++;
        }
        if(boolupdate == n) return res;
        
        for(int i = boolupdate;i < n;i++)
        {
            isright = true;  //每轮都要isright
            int k = (i == boolupdate)? boolupdate:leftmax; //在更新之后每一次都要重新取新的k值
            //大循环遍历为当前列左边列取出最高的墙,因为程序一直向右走，所以此处要改变起始的位置
            if(i == boolupdate)
            {
                leftmax = i;
            }
            for(;k <= i;k++)
            {
                if(height[k] >=height[leftmax])
                {
                    leftmax = k; //leftmax是索引值
                }
            }
            //大循环遍历为当前列右边列取出最高的墙,因为程序一直向右走，所以此处要改变起始的位置
            int z = (i == boolupdate)? boolupdate:rightmax;
            // 如果当前列数小于z，说明右边的最大墙并未被覆盖，直接break
            if(i < rightmax)
            {
                isright = false;
            }
            else
            {
                if((i + 1) >= n)
                {
                    return res;
                }
                rightmax = i + 1;
            }
            for(z = i + 1; z < n; z++)
            {
                if(!isright)
                {
                    break;
                }
                if(height[z] >= height[rightmax])
                {
                    rightmax = z; //选出右边的最大列
                }
            }
            //选出左右两边的最小墙，木桶效应
            int minheight = min(height[leftmax],height[rightmax]);
            //如果当前列的墙高于左右两边的最小墙，说明可以装水
            if(height[i] < minheight)
            {
                //累加结果
                res = res + (minheight - height[i]);
            }
        }
        return res;
    }
};
// 结论：有点屎山代码，仍然有改进空间
																		 
																		 
// 4.动态规划
class Solution
{
public:
    int trap(vector<int> &height)
    {
        //动态规划通过定义容器选出每个位置左边最高和右边最高
        int n = height.size();
        vector<int> left_max(n, 0); //用来存放左边的最高墙
        vector<int> right_max(n, 0); //用来存放右边的最高墙
        int res = 0; //用来存放结果
        //循环遍历左边最高,第一个不需遍历，最后一个也不用遍历，开始到结束为1 - > n - 1
        for(int i = 1;i < n - 1;i++)
        {
            left_max[i] = max(left_max[i - 1], height[i - 1]); //左边墙最高的墙和左边的墙取max
        }
        //循环遍历右边最高,最后一个不需遍历，第一个也不用遍历，开始到结束为n - 1 - > 1
        for(int k = n - 2;k >0;k--)
        {
            right_max[k] = max(right_max[k + 1], height[k + 1]); //右边墙最高的墙和右边的墙取max
        }
        //循环遍历每个位置的水量
        for(int q = 1; q < n - 1; q++)
        {
            int minx = min(left_max[q],right_max[q]);
            if(minx > height[q])
            {
                res += minx - height[q]; //将结果累加
            }
        }
        
        return res;

    }
};
// 结论：空间复杂度o（n），时间是o（3n）

// 5.解法双指针法

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;//最终的结果
        int left = 1; //定义左指针,不需要看第一个元素
        int n = height.size(); //定义容器长度
        int right = n - 2;//右指针最后一个元素索引为n - 1,去除最后一个元素
        int max_left = 0;//用来记录在左边的最大值
        int max_right = 0;//用来记录在右边的最大值
        for(int i = 1;i < n - 1;i++)
        {
            //在我的理解中只需要看第二个元素到倒数第二个元素即可
                if(height[left - 1] < height[right + 1])
                {
                    //若左边的元素小于右边的元素，说明最大的元素一定在右边产生,由木桶效应应该看左边          
                    max_left = max(height[left - 1],max_left);
                    if(height[left] < max_left)
                    {
                        res += (max_left - height[left]);
                    }
                    left++; //更新当前所在位置

                }
                else
                {
                    //从右边更新
                    max_right = max(max_right,height[right + 1]);
                    if(height[right] < max_right)
                    {
                        res += (max_right - height[right]);
                    }

                    right--;

                }
        }
        return res;
    }
};

//结论:只要确定更新方向即可，保证left+right = n - 2，总循环次数即可，这样就可以使除边界外的所有值都被覆盖到
// 6.栈的先进后出的思想进行括号匹配

class Solution
{
public:
    int trap(vector<int> &height)
    {
        //用栈的思路，即括号匹配，先进后出的思想
        int res = 0;
        int idx = 0;//定义当前的指针的指向
        int n = height.size();
        vector<int> stack;
        // 第一层循环是使当前可能有水的指针位于索引以内
        while(idx < n)
        {
            // 第二层循环是计算水量
            while(!stack.empty() && height[idx] > stack.back())
            {
                //满足该情况时才会进行括号匹配
                int top = stack.back();
                stack.pop_back();
                if(stack.empty())
                {
                    break;
                }
                int distance = idx - stack.back() - 1;
                int bounded_height = min(height[idx], height[stack.back()]) - height[top];
                res += distance * bounded_height;
            }
            stack.push_back(idx++);
        }
        return res;
    }

};
// 结论：该解法的难点在于计算每一个当前索引值的积水，当前元素出栈时，栈的最后一个元素是其左边的元素，而当前遍历到的索引值就是比他高的墙，而左边的墙要不等于当前所求的墙，要不大与当前所求的墙，此时会产生积水
