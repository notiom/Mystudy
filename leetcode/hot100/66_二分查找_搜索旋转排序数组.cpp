// 1.我自己的解
// 思路:利用一个iscompare函数找到在哪里旋转，返回索引值
// 分别对2个区间段利用两次二分查找，只要找到就返回
// 但是在找索引时最坏的情况是遍历完所有元素都还没找到，即并未进行旋转，时间复杂度为o(n)
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        //思路：利用双指针的思路比较左边是否严格小于右边
        int left = 0;
        int right = isCompare(nums) - 1;
        int temp = right + 1;
        while(left <= right)
        {
            int left_mid = (left + right) >> 1;
            if(nums.at(left_mid) == target) return left_mid;
            if(nums.at(left_mid) < target) left = left_mid + 1;
            else right = left_mid - 1;
        }
        left = temp;
        right = nums.size() - 1;

        while(left <= right)
        {
            int right_mid = (left + right) >> 1;
            if(nums.at(right_mid) == target) return right_mid;
            if(nums.at(right_mid) < target) left = right_mid + 1;
            else right = right_mid - 1;
        }
        return -1;
    }
private:
    int isCompare(const vector<int>& nums)
    {
        //通过这个函数找到那个位置的索引
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            //返回的是索引
            if(nums.at(left) > nums.at(left + 1)) return left + 1;
            if(nums.at(right) < nums.at(right - 1)) return right;
            left++;
            right--;
        }
        return nums.size() - 1;
    }
};
//结论：通过
