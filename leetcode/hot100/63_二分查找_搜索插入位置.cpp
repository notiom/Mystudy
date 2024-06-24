//1.我自己的解
//使用循环遍历，在循环结束后在输出left指针的值，因为目标并不是是否找到元素，而是索引，所以只需要2个if判断
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        // 使用二分查找算法
        int left = 0; 
        int right = nums.size() - 1;
        while(left <= right)
        {
            int povit = (left + right) >> 1;
            if(nums.at(povit) < target)
            {
                left = povit + 1;
            }
            else
            {
              //就算此时元素正好等于他，也会因为左指针原因在重新指回他
                right = povit - 1;
            }
        }
        return left;
    }
};
//结论：通过

//2.官方题解
//思路:利用left < right的判断，让right可能取到该有的值，移动left指针+1，之后在返回left
// 但是要做一个判断，当所有元素都小于target时，就需要在最后一个元素插入，算特殊判断
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int len = nums.size();
        // 特殊判断
        if (nums.at(len - 1) < target) 
        {
            return len;
        }
        // 使用二分查找算法
        int left = 0; 
        int right = len - 1;
        while(left < right)
        {
            int povit = (left + right) >> 1;
            if(nums.at(povit) < target)
            {
                left = povit + 1;
            }
            else
            {
                right = povit;
            }
        }
        return left;
    }
};
//结论：通过
// 但是我觉得不如我的方法
