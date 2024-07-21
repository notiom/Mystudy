// 1.官方题解
// 解题思路:哈希表
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> hashmap;
        string key;
        for(string &str:strs)
        {
            key = str;
            sort(key.begin(),key.end());
            hashmap[key].emplace_back(str);
        }
        vector<vector<string>> output;
        for(auto it = hashmap.begin();it!=hashmap.end();it++)
        {
            output.emplace_back(it->second);
        }
        return output;
     }
};
/*
总结：掌握到的知识：
	对字符串的排序函数：sort（begin，end）
	对字符串的循环
	for（string &str：strs）
	哈希表的定义unordered_map
	emplace_back
*/
