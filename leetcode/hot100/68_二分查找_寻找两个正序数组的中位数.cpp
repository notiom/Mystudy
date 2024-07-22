// 1.我自己的解
// 使用原地快速排序之后在查找中位数
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // 我能想到的第一思路是通过排序算法之后在寻找中位数
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        quickSort(nums1,0,nums1.size() - 1);
        int n = nums1.size();
        if(n % 2 == 0) return (double)(nums1[n / 2 - 1] + nums1[n / 2]) / 2;
        return nums1[n / 2]; 
    }
private:
    int partition(vector<int>& nums,int start,int end)
    {
        int pivotValue = nums[end];
        int i = start - 1;
        for(int j = start; j < end; j++)
        {
            if(nums[j] < pivotValue)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[end]);
        return i + 1;
    }

    void quickSort(vector<int>& nums,int start,int end)
    {
        if(start < end)
        {
            int pivot = partition(nums,start,end);
            quickSort(nums,0,pivot - 1);
            quickSort(nums,pivot+1,end);
        }
    }
};
// 结论:超时未通过

// 2.使用堆排序
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // 我能想到的第一思路是通过排序算法之后在寻找中位数
        // 使用堆排序
        priority_queue<int> que;
        for(const int num : nums1)
        {
            que.push(num);
        }
        for(const int num : nums2)
        {
            que.push(num);
        }
        int n = que.size();
        for(int i = 0;i < (n - 1) / 2;i++)
        {
            que.pop();
        }
        if(n % 2 == 0) 
        {
            int temp = que.top();
            que.pop();
            return (double)(que.top() + temp) / 2.0;
        }
        return que.top();
    }
};
// 结论:通过 时间复杂度o(n * logn) 空间复杂度o(n).

// 3.官方题解
// 归并排序
// 两个有序数组合并时的算法的时间复杂度时o(m + n)
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // 既然是两个数组，那么可以使用归并排序
        int count = 0;
        // 只要当新建数组的长度达到中位数时即可停止并输出
        int m = nums1.size();
        int n = nums2.size();

        int Sumsize = (m + n) / 2; //计算索引 //为奇数时还需要加上前一个元素，为偶数直接输出
        vector<int> nums(Sumsize + 1); // 新建一个数组来存放排序后的结果
        for(int i = 0,j = 0;i < m || j < n;)
        {
            if(i == m)
            {
                nums[count++] = nums2[j++];
                if(count == Sumsize + 1) 
                {
                    break;
                }
            }

            else if(j == n)
            {
                nums[count++] = nums1[i++];
                if(count == Sumsize + 1) 
                {
                    break;
                }
            }

            else if(nums1[i] < nums2[j])
            {
                nums[count++] = nums1[i++];
                if(count == Sumsize + 1) 
                {
                    break;
                }
            }
            else if(nums1[i] >= nums2[j])
            {
                nums[count++] = nums2[j++];
                if(count == Sumsize + 1) 
                {
                    break;
                }
            }
        }
        return (m + n) % 2 == 0 ?  (double)(nums[count - 1] + nums[count - 2]) / 2.0 : nums[count - 1];
    }
};
// 结论:通过 因为利用了剪枝操作 所以空间复杂度为o((m + n) / 2)

// 4. 对于该排序算法的空间复杂度优化
// 使用left保存上一个即可
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // 既然是两个数组，那么可以使用归并排序
        int count = 0;
        // 只要当新建数组的长度达到中位数时即可停止并输出
        int m = nums1.size();
        int n = nums2.size();

        // 不需要创建数组，只需要保存上一个的结果即可
        int left = 0,right = 0;
        for(int i = 0,j = 0;i < m || j < n;)
        {
            if(i == m)
            {
                left = right;
                right = nums2[j++];
                count++;
                if(count == (m + n) / 2 + 1) 
                {
                    break;
                }
            }

            else if(j == n)
            {
                left = right;
                right = nums1[i++];
                count++;
                if(count == (m + n) / 2 + 1) 
                {
                    break;
                }
            }

            else if(nums1[i] < nums2[j])
            {
                left = right;
                right = nums1[i++];
                count++;
                if(count == (m + n) / 2 + 1) 
                {
                    break;
                }
            }
            else if(nums1[i] >= nums2[j])
            {
                left = right;
                right = nums2[j++];
                count++;
                if(count == (m + n) / 2 + 1) 
                {
                    break;
                }
            }
        }
        return (m + n) % 2 == 0 ?  (double)(left + right) / 2.0 : right;
    }
};
// 结论:空间复杂度仅为o(1).
