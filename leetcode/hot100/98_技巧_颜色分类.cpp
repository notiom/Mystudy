// 1.我自己的解
// 颜色分类 已知只有0 1 2 那么只需要计算0 1 2 的个数即可
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        // 先记录0 1 2的个数,之后对原始nums的元素进行替换
        int n = nums.size();
        int num_0 = 0,num_1 = 0,num_2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums.at(i) == 0) num_0++;
            else if(nums.at(i) == 1) num_1++;
            else num_2++;
        }

        for(int j = 0;j < n;j++)
        {
            if(j < num_0)
            {
                nums.at(j) = 0;
            }
            else if(j < num_0 + num_1)
            {
                nums.at(j) = 1;
            }
            else
            {
                nums.at(j) = 2;
            }
        }
    }
};

// 应该可以使用insert函数替换掉原来的值
// 2.使用fill函数改进的版本

class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        // 先记录0 1 2的个数,之后对原始nums的元素进行替换
        int n = nums.size();
        int num_0 = 0,num_1 = 0,num_2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums.at(i) == 0) num_0++;
            else if(nums.at(i) == 1) num_1++;
            else num_2++;
        }

        fill(nums.begin(), nums.begin() + num_0,0);
        fill(nums.begin() + num_0, nums.begin() + num_0 + num_1,1);
        fill(nums.begin() + num_0 + num_1,nums.end(),2);

    }
};
// 结论：一趟循环加o(n)时间复杂度

// 3. 双指针的思路
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        // 双指针的思路
        int n = nums.size();
        int p0 = 0,p1 = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums.at(i) == 1) 
            {
                swap(nums.at(p1), nums.at(i));
                p1++;
            }
            else if(nums.at(i) == 0)
            {   
                swap(nums.at(p0), nums.at(i));
                if(p0 < p1)
                {
                    // 2 2 1 1 0 0 
                    // 交换后变成1 1 2 2 0 0
                    // 此时由于p0 < P1,故要交换0 0 2 2 1 1
                    // 还需要对当前交换的元素的位置与p1指针的位置交换
                    swap(nums.at(p1), nums.at(i));
                }
                p0++;
                p1++;
            }
        }
    }
};
// 结论:通过 时间复杂度o(n) 空间复杂度o(1).
