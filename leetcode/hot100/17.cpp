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
//3.官方题解
// author:rmokerone
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                    break;
                // 将nums[i] 放置到对应位置上[1,2,3...]
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                return (i + 1);
            }
        }
        return (nums.size() + 1);
    }
};
//原地哈希，暂时未理解
