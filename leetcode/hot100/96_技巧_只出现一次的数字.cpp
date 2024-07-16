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

//法二，使用排序算法先排序
