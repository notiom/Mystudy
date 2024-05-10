// 1.官方题解 有思路 但是 不知道怎样写查找字符串以及返回下标位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //滑动窗口思路
        //定义一个最大字串长度
        unordered_set<char> lookup;
        int res = 0;
        int left = 0;
        int n = s.size();
        for(int i = 0;i<n;i++)
        {
            while(lookup.find(s[i]) != lookup.end())
            {
                lookup.erase(s[left]);
                left++; //记录当前位置的指针
            }
            res = max(res,i - left + 1); //因为索引值从0开始，所以要加1
            lookup.insert(s[i]);  
​
        }
        return res;
    }
};
​// 结论：思路为当发现这个字符串在map中时，删除最左端元素，直到没有这个元素出现，并让计数指针加一，最后计算i - pointer +1 和之前的max比较
                               
//2.使用一个length计算在原始数组中的位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
    //最终的最大值结果
    int res = 0;
    int length = 0;
    int n = s.size();
    //存放子字符串的容器
    vector<char> lookup;
​
    for(int i = 0;i < n;i++)
    {
        auto it = find(lookup.begin(),lookup.end(),s[i]);
        if(it != lookup.end())
        {
            //说明找到了该字符，开始删除并计算索引
            length += distance(lookup.begin(), it) + 1;
            lookup.erase(lookup.begin(),next(it)); //删除该元素前的所有元素
        }
        res = max(res,i - length + 1); //这里需要+1，，因为字符长度总比索引要大1
        lookup.push_back(s[i]);
    }
    return res;
    }
};
