// 1.我自己的解
// 摆动排序
// 先完成排序，在两对两对进行交换
/ 如果是奇数可以将第一个元素放到最后面
class Solution 
{
public:
    void wiggleSort(vector<int>& nums) 
    {
        // 摆动排序
        // 思路为随机选择一个降序排列
        // 然后将其他元素插入进去
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // 然后将块两两配对得出最终结论
        if(n % 2 != 0) 
        {
            int num = nums[0];
            // 完成移位
            for(int i = 0; i < n - 1; i++)
            {
                nums[i] = nums[i + 1];
            }
            nums[n - 1] = num;
            n = n - 1; // 进行交换
        }
        for(int i = 0;i < n / 2;i+=2)
        {
            swap(nums[i],nums[n - 2 - i]);
            swap(nums[i + 1],nums[n - 1 - i]);
        }
    }
};
// 时间复杂度o(n * logn)(冒泡排序),空间复杂度o(1).

//2. 官方题解
// 贪心匹配
class Solution 
{
public:
    void wiggleSort(vector<int>& nums) 
    {
        // 摆动排序
        // 贪心匹配
        // 位于索引0和2的元素（即位于偶数索引的元素）如果大于下一个相邻元素，
        // 就会与下一个相邻元素交换。
        // 在索引 1 和 3（即位于奇数索引的元素）的元素如果小于下一个相邻元素，
        // 就会与下一个相邻元素交换。
        int n = nums.size();
        for(int i = 0; i < n - 1; i++)
        {
            if(i % 2 == 0)
            {
                // 如果当前元素是偶数
                // 比较当前元素是否大于下一个元素
                // 如果大于，交换，使其满足nums[0] < nums[1]
                if(nums[i] >  nums[i + 1])
                {
                    // 2 1 4 3
                    // 2 1 -> 1 2
                    swap(nums[i], nums[i + 1]);
                }
            }
            else
            {   
                // 如果当前元素是奇数
                // 比较当前元素是否小于下一个元素
                if(nums[i] < nums[i + 1])
                {
                    // 2 1 4 -> 2 4 1
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
    }
};
// 结论:时间复杂度o(n),空间复杂度o(1).
