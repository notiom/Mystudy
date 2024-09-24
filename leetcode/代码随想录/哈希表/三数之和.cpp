// 1.我自己的解
// 和四数之和类似,只是可以利用双指针法去简化时间复杂度
class Solution 
{
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while(right > left)
            {
                int temp = nums[i] + nums[left] + nums[right];
                if(temp < 0) left++;
                else if(temp > 0) right--;
                else
                {
                    // 三数元素满足,开始push -> res
                    res.push_back({nums[i],nums[left],nums[right]});
                    // 去重
                    while(right > left && nums[right] == nums[right - 1]) right--;
                    while(right > left && nums[left] == nums[left + 1]) left++;
                    // 同时收缩
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
// 通过 时间复杂度o(N * N),空间复杂度o(1).
