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
