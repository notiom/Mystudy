// 1.解法一：暴力枚举
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int res = 0; //定义输出结果
        int idx = 1; //定义当前指向
        int n = nums.size();
        for(int i = 0 ; i < n; i++)
        {
            int idx = i;
            int currentsum = 0; //定义当前的和
            while(idx < n)
            {
                currentsum += nums[idx];
                if(currentsum == k)
                {
                    res++;
                }
                idx++;
            }
        }
        return res;
    }
};

//结论：用时超级久，时间复杂度像一坨狗屎，但是空间复杂度还行
//2.官方题解(哈希表利用前缀之和去表示)

class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int res = 0; //定义输出结果
        int pre = 0; //定义前缀之和
        int n = nums.size();
        unordered_map<int, int> mp; //定义哈希表用来存放前缀之和
        mp[0] = 1;
        for(auto &num:nums)
        {
            pre += num;
            if(mp.find(pre - k) != mp.end())
            {
                //说明找到了该数
                res += mp[pre - k];
            }
            mp[pre]++;
        }
        return res;
    }
};

//结论：时间复杂度接近完美
