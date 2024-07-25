// 1.我自己的解
// 使用二分法快速确定应该插入的位置元素
class MedianFinder 
{
public:
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        quickInsert(vec,num);
    }
    
    double findMedian() 
    {
        int n = vec.size();
        if(n % 2 == 0)
        {
            return (double)((vec.at(n / 2 - 1) + vec.at(n / 2)) / 2.0);
        }
        return vec.at(n / 2);
    }
private:
    priority_queue<int> que;
    vector<int> vec; // 该容器应该被排序
    void quickInsert(vector<int>& nums,int num)
    {
        // 使用二分查找应该插入的元素位置
        int left = 0,right = nums.size();
        while(left < right)
        {
            int mid = (left + right) >> 1;
            if(nums.at(mid) < num)
            {
                // 使左边界扩大
                left = mid + 1;
            }
            else
            {
                // 此处也可能会使该元素等于,所以left = right时有可能元素会相等
                right = mid;
            }
        }
        nums.insert(nums.begin() + left, num); // 应该插入的位置
    }
};
// 结论:通过 时间复杂度 o(logn),空间复杂度o(n).
