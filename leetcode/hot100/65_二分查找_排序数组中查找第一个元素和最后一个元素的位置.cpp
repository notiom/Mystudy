// 1.我自己的解
// 使用两个二分查找查找位于最左边的索引和最右边的索引
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        //思路:利用二分查找查找满足当前元素的第一个元素和最后一个元素
        if(nums.empty()) return vector<int>{-1,-1};
        int left = 0; //定义左指针
        int right = nums.size() - 1; //定义右指针
        vector<int> res;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                 //此时可以找到最左边的目标值
                right = mid;
            }
        }
        if(nums.at(left) == target) res.push_back(left);
        else return vector<int>{-1,-1};

        left = right;
        right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                 //此时可以找到最左边的目标值
                left = mid;
            }
        }
        res.push_back(right);
        return res;
    }
};
