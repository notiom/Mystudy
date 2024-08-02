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
