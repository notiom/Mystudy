//1.我自己的
// 思路：利用循环便利并进行判断。
// 1.判断是否前一个元素 + 1 = 后一个元素
// 2.判断是否前一个元素等于后一个元素
// 3.判断前面已生成的最大输出是否小于当前的最大输出
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int output = 1; 
        int max = -1;
        if(n ==0)
        {
            return 0;
        }    
        for(int i = 0;i<n -1;i++)
        {
            if(nums[i] + 1 ==nums[i+1])
            {
                output++;
            }
            else if(nums[i] ==nums[i + 1])
            {
                continue;
            }
            else
            {
                if(output > max)
                {
                    max = output;
                }
                output = 1;
            }
        }
        if(output > max)
        {
            return output;
        }
        return max;
    }
};

//2.官方题解,时间复杂度过于复杂，不采纳，但有一个改进的地方 ，提出了集合去重的概念
	
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};

//该思路的精华就在使用num - 1，来确定他是第一个开始的数，之后再通过迭代加一来判断有多少连续数
//3.结合之后我自己的代码改进版本

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> nums_set;
        sort(nums.begin(),nums.end());
        for(auto &num:nums)
        {
            nums_set.insert(num);
        }
        int n = nums_set.size();
        int output = 1; 
        int max = -1;
        if(n ==0)
        {
            return 0;
        }
        auto end_it = nums_set.end();
        end_it--;
        for(auto it = nums_set.begin();it !=end_it;it++)
        {
            auto next_it = next(it);
            if(*it + 1 == *next_it)
            {
                output++;
            }
            else
            {
                if(output > max)
                {
                    max = output;
                }
                output = 1;
            }
        }
        if(output > max)
        {
            return output;
        }
        return max;
    }
};
// 总结，最一开始的时间复杂度最低，最好用
