// 1.我自己的解
// 本题的主要思路就是判断当前循环的位置是否等于val,如果等于，则交换他和right的位置,如果这两个交换的值都等于val
// 则使i不动,如果在这个if中使得right < 0，就说明所有元素都等于val,i值一直不动的做交换，直到所有元素都交换完成
// 但是right < 0的if判断其实就是right == -1的时候,这在i >= break时可以被满足
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        // 只需要选用一个右指针即可
        // 右指针标注为下次要插入的位置
        int n = nums.size();
        int right = n - 1;

        for(int i = 0;i < n;i++)
        {
            if(nums[i] == val)
            {
                swap(nums[i],nums[right]);
                if(nums[right] == val) i--;
                right--;
                // if(right < 0) break;
            }
            if(i >= right) break;
        }
        // return (n - (n - 1 -right));
        return (right + 1);
    }
};
// 结论:通过 时间复杂度o(N),空间复杂度o(1).

// 2.双指针法
// 快指针控制等于val的元素,慢指针控制交换的位置
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int left = 0; //left指针指向要更新的索引位置
        int right = 0; //right指针指向val目标的元素
        int n = nums.size();

        for(int i = 0;i < n;i++)
        {
            // 如果当前元素等于val,就使快指针 + 1，慢指针不动，最后要返回的就是慢指针的值
            if(nums[i] == val)
            {
                right++;
                continue;
            }
            nums[left] = nums[right];
            right++;
            left++;
        }
        return left;
    }
};
// 结论:通过 时间复杂度o(n),空间复杂度o(1).


