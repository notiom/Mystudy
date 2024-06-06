#include "sort.h"

using namespace std;

void sortBubble(std::vector<int> &nums)
{
    int n = nums.size();
    for(int i =0;i < n;i++)
    {
        //设置一个提前退出标志，如果没有被交换过，则提前退出
        //可以把最大的数提前到最后面
        bool flag = false;
        for(int j = 0;j < n-i-1;j++)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums[j],nums[j+1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}