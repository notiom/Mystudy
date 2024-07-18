//1.我的方法，测试通过
存在的问题：vector中查找是否存在的函数，如何快速给vector每个元素赋值
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //第一个数
        int signle = 0;
        //第二个数
        int score = -1;
        for(int i =0;i<nums.size();i++)
        {
            int chazhi = target - nums[i];
            for(int key = i + 1;key<nums.size();key++)
            {
                if(nums[key] == chazhi)
                {
                    score = key;
                    signle = i;
                    break;
                }
            }

        }
        vector<int> output(2);
        output[0] = signle;
        output[1] = score;
        return output;
        
    }
};
	
//改进为return vector<int> {i,j};
//2.改进后
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //第一个数
        int signle = 0;
        //第二个数
        int score = -1;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            int chazhi = target - nums[i];
            for(int key = i + 1;key<n;key++)
            {
                if(nums[key] == chazhi)
                {
                    score = key;
                    signle = i;
                    break;
                }
            }

        }
        return vector<int> {signle,score};
        
    }
};
	
//3.官方题解(哈希表)
//hash.find(函数去查找键是否匹配，如果匹配到，返回值为it->first和it->second分别对应建和值，如果未找到，则返回容器尾部的迭代器，即.end)
	
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end())
            {
                return {it->second , i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
