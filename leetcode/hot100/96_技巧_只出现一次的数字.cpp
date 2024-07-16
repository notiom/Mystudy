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
// 结论:通过 时间复杂度 o(n * logn),空间复杂度 o(1)

// 附录 ： 原地快速排序
int partition(vector<int>& nums,int low,int high)
{
    int pivot = nums.at(high);
    int i = (low - 1);

    for(int j = low; j < high;j++)
    {
        if(nums.at(j) < pivot)
        {
            i++;
            swap(nums.at(i), nums.at(j));
        }
    }
    swap(nums.at(i + 1), nums.at(high));
    return (i + 1);
}

void quickSort(vector<int>& nums,int low,int high)
{
    if(low < high)
    {
        int pivot = partition(nums,low,high);
        quickSort(nums,low,pivot - 1);
        quickSort(nums, pivot + 1, high);
    }
}
// 3.官方题解
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        // 任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0=a。
        // 任何数和其自身做异或运算，结果是 0，即 a⊕a=0。
        // 异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。
        // 由于满足交换律，所以可以知道最后一个的元素一定会在最终异或的结果中
        int single = 0;
        int n = nums.size();
        for(int i = 0;i < nums.size();i++)
        {
            single ^= nums.at(i);
        }
        return single;
    }
};
// 结论:通过 异或操作太强了！ 时间复杂度o(n)

