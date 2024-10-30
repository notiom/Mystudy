//1.自己的解，先进行排序，之后在进行while遍历到第一个正数，设置一个isexists变量，每次依次让isexists和it迭代器自增，如果*it不等于exists，说明这个变量不存在，直接返回，如果遍历完之后还没有退出循环，就返回isexists++
class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        set<int> st(nums.begin(), nums.end());
        sort(st.begin(), st.end());
        set<int>::iterator it = st.begin();
        while(it != st.end())
        {
            if(*it > 0)
            {
                break;
            }
            it++;
        }
        if(it == st.end())
        {
            return 1;
        }
        int isexists = 1;
        while(it != st.end())
        {
            if(*it != isexists)
            {
                return isexists;
            }
            it++;
            isexists++;
        }
        return isexists;
    }
};
//结论：nums = [0,2,2,1,1]时报错，没有考虑有重复元素的情况，故用集合去重
	
//2.集合去重
class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        set<int> st(nums.begin(), nums.end());
        set<int>::iterator it = st.begin();
        while(it != st.end())
        {
            if(*it > 0)
            {
                break;
            }
            it++;
        }
        if(it == st.end())
        {
            return 1;
        }
        int isexists = 1;
        while(it != st.end())
        {
            if(*it != isexists)
            {
                return isexists;
            }
            it++;
            isexists++;
        }
        return isexists;
    }
};
//结论：排序使用的时间复杂度为nlog(n),不符合题目要求

// 3.官方题解
// 原地哈希
class Solution 
{
public:
    int firstMissingPositive(vector<int> &nums) 
    {
        // 原地哈希
        // 使用nums数组作哈希表
        // 应该是元素的位置对应与索引0 -> 1
        // 1 -> 2

        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            // 该大循环结束后每个位置都对应该有的元素
            // 只要不等于,就直接返回
            while(nums[i] != i + 1)
            {
                if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                {
                    // 条件1.不应该有小于等于0的数
                    // 条件2. 不应该有大于元素容量的数
                    // 条件3. 去除重复元素,即当前元素等于他对应位置索引的数
                    // 比如2 = nums[1] = 2
                    break;
                }
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }

        for(int i = 0;i < n;i++)
        {
            if(nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1; // 每个元素都存在应该返回n + 1
    }
};
// 通过 时间复杂度o(n),和空间复杂度o(1).
