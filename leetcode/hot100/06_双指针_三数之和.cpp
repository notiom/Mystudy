// 1.我自己的，运用三层循环找到这三个数并加入到vector中，问题在于，无法实现去重，如果用循环时间复杂度会很高。
  
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 定义最终的输出结果
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                for(int k = j + 1;k < n;k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        res.push_back(sort(vector<int>({nums[i],nums[j],nums[k]})));
                        
                    }
                }
            }
        }
        return res;
    }
};

// 结论：测试用例由于重复元素未通过
	
//2.结合官方题解做第二遍，在排序之后每次枚举出的数不能和前一个数相同：

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 定义最终的输出结果
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])         { 
                continue;
            }
            for(int j = i + 1;j < n;j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])            { 
                continue;
                }
                for(int k = j + 1;k < n;k++)
                {
                    if (k > j + 1 && nums[k] == nums[k - 1])            { 
                continue;
                    }
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        res.push_back(vector<int>({nums[i],nums[j],nums[k]}));

                    }
                }
            }
        }
        return res;
    }
};

/*
3.官方题解(双指针)
	思路：这题的难点在于去重，
	------------for---------
1.（去重）如果目前的元素等于前一个元素，那么为重复元素，直接跳过本轮循环
2.（简化时间复杂度）且如果for循环中第一个元素>0,则说明后续不可能有相加为0了。（因为进行过排序）。故直接返回res
	---------while(left<right)---------
	在while循环中，判断两数之和与target的关系。
	1.（相等）
	-----（1）判断左边的元素是否和左边前一个元素相等，如果相等，则left++，
 ----- （2）同理，右边元素也要进行right++，
 ----- （3）如果都没有，right--或者left++，（目的是为了使元素变化去找其他可能存在的三元素和为0）
	2.(大于)
	说明right数大了，应该使右边指针向左移
             right--;
	3.(小于)
	说明left数小了，应该使左边指针向右移
             left++;
*/
																			
//代码部分																		
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 定义最终的输出结果
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++)
        {
            if(nums[i] > 0)
            {
                return res;
            }
            if (i > 0 && nums[i] == nums[i - 1])         { 
                continue;
            }
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while(left < right)
            {
                if(nums[left] + nums[right] > target)
                {
                    //说明right数大了，应该使右边指针向左移
                    right--;
                }
                else if(nums[left] + nums[right] < target)
                {
                    //说明left数小了，应该使左边指针向右移
                    left++;
                }
                else
                {
                    if (left > (i + 1) && nums[left] == nums[left - 1])         { 
                        left++;
                        continue;
                    }
                    if(right < (n - 1) && nums[right] == nums[right + 1])
                    {
                        right--;
                        continue;
                    }
                    res.push_back(vector<int>({nums[left],nums[right],-target}));
                    right--;
                }
            }
        }
        return res;
    }
};

// 4.后续通过cs版本改进的三数之和
// 使用剪枝和去重
public class Solution 
{
    private  List<IList<int>> res = new List<IList<int>>();
    public IList<IList<int>> ThreeSum(int[] nums) 
    {
        // 正常逻辑的三数之和是遍历,但是时间复杂度会超
        // 使用双指针
        int n = nums.Length;
        QuickSort(nums,0,n - 1);
        for(int i = 0;i < n - 1;i++)
        {
            if(nums[i] > 0) break; // 剪枝
            if(i > 0 && nums[i] == nums[i - 1]) continue; // 对一个元素可能出现的去重
            int left = i + 1;
            int right = n - 1;

            while(left < right)
            {
                int target = -nums[i];
                
                if(nums[left] + nums[right] == target)
                {
                    res.Add( new List<int> {nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    // 对第二个元素去重
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    // 对第三个元素去重
                    left++;
                    right--;

                }
                else if(nums[left] + nums[right] < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return res;
    }

    private void QuickSort(int []nums,int start,int end)
    {
        if(start < end)
        {
            int pivot = Partition(nums,start,end);
            QuickSort(nums,start, pivot - 1);
            QuickSort(nums,pivot + 1,end);
        }

    }

    private int Partition(int []nums,int start,int end)
    {
        int height = nums[end];
        int i = start - 1;

        for(int j = start;j < end;j++)
        {
            if(nums[j] < height)
            {
                i++;
                Swap(ref nums[i], ref nums[j]);
            }
        }
        Swap(ref nums[i + 1],ref nums[end]);
        return i + 1;
    }

    private void Swap(ref int a,ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}
// 通过 时间复杂度o(n * n),空间复杂度o(n).
