// 1.我自己的解
// 使用回溯算法超出时间限制
// 应该使用双指针法
class Solution 
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        
        quickSort(nums,0,nums.size() - 1);
        backtrack(nums,target,0);
        return res;
    }

    void backtrack(vector<int>& nums, int target,int startIndex)
    {
        if(path.size() == 4)
        {
            if(target == 0)
            {
                res.push_back(path);
            }
            return; // 不能在往下递归了
        }

        for(int i = startIndex;i < nums.size();i++)
        {
            // 去重处理
            if(i > startIndex && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtrack(nums,(size_t)target - nums[i],i + 1);
            path.pop_back();
        }
    }

    // 手撕原地冒泡排序
    void quickSort(vector<int> & nums,int start,int end)
    {
        if(start < end)
        {
            int pivot = partition(nums,start,end);
            quickSort(nums,0,pivot - 1);
            quickSort(nums,pivot + 1,end);
        }
    }
    int partition(vector<int> & nums,int start,int end)
    {
        int height = nums[end];
        int i = start - 1;
        for(int j = start;j < end;j++)
        {
            if(nums[j] < height)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i + 1],nums[end]);
        return (i + 1);
    }

};
// 结论:未通过

// 2.四数之和的双指针法将时间复杂度简化为o(n * n n).
// 利用双指针法的四树之和
class Solution 
{
public:
    vector<vector<int>> res;
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        
        sort(nums.begin(),nums.end());
        int n =nums.size();
        // 最外层选择一层循环
        for(int i = 0;i < n;i++)
        {
            // 剪枝处理
            if(nums[i] > target && nums[i] >= 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue; // 去重
            for(int j = i + 1;j < n;j++)
            {
                // 2级剪枝处理
                if(nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = n - 1;

                while(right > left)
                {
                    int temp = (size_t)((size_t)nums[i] + (size_t)nums[j] + (size_t)nums[left] + (size_t)nums[right]);
                    if(temp < target) left++;
                    else if(temp > target) right--;
                    else
                    {
                        // 满足条件的一个解
                        res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        // 如果不满足right > left,可能会超出该层控制范围，导致重复元素出现
                        while(right > left && nums[right] == nums[right - 1]) right--;
                        while(right > left && nums[left] == nums[left + 1]) left++;
                        // 同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};
// 结论:通过 时间复杂度o(n * n * n),空间复杂度o(1).
