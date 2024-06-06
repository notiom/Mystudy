#include "sort.h"

using namespace std;
void sortInsert(std::vector<int> &nums)
{

    //插入排序保证了前面的数一定比当前的数要小如果没有，则依次查找该数到底位于哪个位置
    int n = nums.size();
    for(int i = 1;i < n;i++)
    {
        int key = nums[i];
        int j = i - 1;
        while(j >=0 && key < nums[j])
        {
            //元素依次向后移动，为前面的元素腾出位置
            nums[j+1] = nums[j];
            j--;
        }
        //循环结束后即找到了它适合的位置
        nums[j + 1] = key;
    }
}