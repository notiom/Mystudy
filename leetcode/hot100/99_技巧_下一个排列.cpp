// 1.我自己的解
// 思路不完全正确
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        // 起始思路为从后向前遍历，如果发现了一个右边的数大于左边的数，就交换位置,
        // 并将此后所有的位置翻转并退出
        int n = nums.size();
        for(int i = n - 1;i > 0;i--)
        {
            if(nums.at(i) > nums.at(i-1))
            {
                swap(nums.at(i), nums.at(i-1));
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        // 如果没有找到这样的交换，说明数组是逆序的，需要翻转
        reverse(nums.begin(),nums.end());
    }
};
//结论:未通过

// 2.官方题解
// 在原思路上稍作修改 加入了在遇到第一个升序排列后在从后向前看谁是第一个比他大的数之后交换
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        // 起始思路为从后向前遍历，如果发现了一个右边的数大于左边的数，就交换位置,
        // 并将此后所有的位置翻转并退出
        int n = nums.size();
        for(int i = n - 1;i > 0;i--)
        {
            if(nums.at(i) > nums.at(i-1))
            {
                // 找到该升序对之后从后向前查找第一个大于nums.at(i-1)的值
                // 因为在后面的排列也是降序排列，第一个大于nums.at(i - 1)的元素就是最小的元素
                for(int j = n - 1;j >= i;j--)
                {
                    if(nums.at(j) > nums.at(i - 1))
                    {
                        swap(nums.at(j), nums.at(i-1));
                        reverse(nums.begin() + i, nums.end());
                        return;
                    }
                }
            }
        }
        // 如果没有找到这样的交换，说明数组是逆序的，需要翻转
        reverse(nums.begin(),nums.end());
    }
};
// 结论:通过 时间复杂度o(n) 空间复杂度o(1).
