// 1.我自己的解
// 找到第一个不满足升序排列的数
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        //通过这个函数找到那个位置的索引
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            //返回的是索引
            if(nums.at(left) > nums.at(left + 1)) return nums.at(left + 1);
            if(nums.at(right) < nums.at(right - 1)) return nums.at(right);
            left++;
            right--;
        }
        return nums.at(0);
    }
};
/结论：通过

// 2.官方题解
// 掌握向下整除和向上整除
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        //通过这个函数找到那个位置的索引
        int left = 0;
        int right = nums.size() - 1; /* 左闭右闭区间，如果用右开区间则不方便判断右值 */ 
        while(left < right) /* 循环不变式，如果left == right，则循环结束 */
        {
           
            int mid = left + (right - left) / 2; /* 地板除，mid更靠近left */
             // 如果左边比右边小，收缩右边界，最小值在左边
             // 最小值可能是mid
              /* 明确中值 < 右值，最小值在左半边，收缩右边界 */ 
              /* 因为中值 < 右值，中值也可能是最小值，右边界只能取到mid处 */ 
            if(nums.at(mid) < nums.at(right)) right = mid;
             // 如果左边比右边大，收缩左边界，最小值在右边
             // 且最小值一定不是mid
             /* 中值 > 右值，最小值在右半边，收缩左边界 */
             /* 因为中值 > 右值，中值肯定不是最小值，左边界可以跨过mid */ 
            else if(nums.at(mid) > nums.at(right)) left = mid + 1;
        }
        return nums.at(left);
        /* 循环结束，left == right，最小值输出nums[left]或nums[right]均可 */
    }
};
//结论：通过


// 补充
// 取一个这个序列里的最大值
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) 
        {
            int mid = left + (right - left + 1) / 2;   /* 先加一再除，mid更靠近右边的right */
            if (nums[left] < nums[mid]) 
            {
                left = mid;                            /* 向右移动左边界 */
            } else if (nums[left] > nums[mid]) 
            {
                right = mid - 1;                       /* 向左移动右边界 */
            }
        }
        return nums[(right + 1) % nums.size()];    /* 最大值向右移动一位就是最小值了（需要考虑最大值在最右边的情况，右移一位后对数组长度取余） */
    }
};
