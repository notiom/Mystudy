// 返回最后一个应该插入元素的位置
private int BinarySearch(List<int> nums, int num)
{
    // 返回最后一个等于 num 的插入位置索引
    int left = 0;
    int right = nums.Count - 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (num < nums[mid])
        {
            right = mid - 1;
        }
        else // 继续向右搜索，确保找到最后一个相等的元素
        {
            left = mid + 1;
        }
    }
    return left;
}
// 返回第一个应该插入元素的位置
private int BinarySearch(List<int> nums, int num)
{
    // 返回第一个等于 num 的插入位置索引
    int left = 0;
    int right = nums.Count - 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (num > nums[mid])
        {
            left = mid + 1;
        }
        else // 继续向左搜索，确保找到第一个相等的元素
        {
            right = mid - 1;
        }
    }
    return left;
}

