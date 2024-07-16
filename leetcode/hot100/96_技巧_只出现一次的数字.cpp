// 1.我自己的解
// 双层循环判断元素是否出现两次
// 算是暴力解法
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        // 那只能牺牲时间复杂度来换取空间复杂度
        // 两层循环来判断是否有元素存在
        int n = nums.size();
        for(int i = 0; i < n;i++)
        {
            if(nums.at(i) == 30001) continue;
            bool flag = true;
            for(int j = i + 1;j < n;j++)
            {
                if(nums.at(j) == nums.at(i))
                {
                    // 后面有一个元素与之相同，说明不是该元素，直接退出
                    flag = false;
                    nums.at(j) = 30001;
                    break;
                }
            }
            if(flag) return nums.at(i);
        }
        return -1;
    }
};
// 结论:通过 时间复杂度o(n *  n) 使用额外的空间复杂度o(1)

// 法二，使用排序算法先排序
// 原地排序算法
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        // 先使用快速排序将元素排序
        // 之后判断当前元素和下一个元素是否相同
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i+=2)
        {
            // 可能会出现奇数的情况，最后一个元素没有下一个元素
            if(nums.at(i) != nums.at(i + 1))  return nums.at(i);
        }
        // 最后一个元素一定是单独的
        return nums.back();  // 注意返回最后一个元素
    }
};
// 时间复杂度 o(n * logn),空间复杂度 o(1)
