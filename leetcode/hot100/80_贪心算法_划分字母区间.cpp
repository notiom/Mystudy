// 1.我自己的解
// 思路:先将每一个元素出现的索引位置记录到哈希表中，之后通过遍历每个元素找到maxindex，如果恰好当前索引就是最后一个maxindex，就说明当前元素可以被分割
class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        // 将所有元素都存放至哈希表中
        // 哈希表中的键为字母，哈希表中的值为vector，存放该字母出现的索引位置
        unordered_map<char,vector<int>> mps;
        int n = s.length();
        for(int i = 0;i < n;i++)
        {
            // 其中vector元素一定是升序排列
            mps[s.at(i)].push_back(i);
        }
        int maxindex = 0;
        int start = 0; //定义一个片段的起始位置
        vector<int> res; // 存储每一段的长度
        for(int j = 0;j < n;j++)
        {
            maxindex = max(maxindex,mps[s.at(j)].back());
            if(j == maxindex)
            {
                // 若j == maxindex 说明当前位置就是分割点，要返回长度
                res.push_back(j - start + 1);
                start = j + 1; // 并将start 置为下一段的起始位置
                maxindex = 0; // 将 maxindex 置为 0，重新开始找下一段的分割点
            }
        }
        return res;
    }
};
//结论：通过 时间复杂度o(n) 空间复杂度o(n)

// 2.自己的改进版本
// 哈希表中只需要存放该元素出现的最后一个元素即可，不需要存放整个容器

class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        // 将所有元素都存放至哈希表中
        // 哈希表中的键为字母，哈希表中的值为出现的最后一个位置
        unordered_map<char,int> mps;
        int n = s.length();
        for(int i = 0;i < n;i++)
        {
            // 其中vector元素一定是升序排列
            mps[s.at(i)] = i;
        }
        int maxindex = 0;
        int start = 0; //定义一个片段的起始位置
        vector<int> res; // 存储每一段的长度
        for(int j = 0;j < n;j++)
        {
            maxindex = max(maxindex,mps[s.at(j)]);
            if(j == maxindex)
            {
                // 若j == maxindex 说明当前位置就是分割点，要返回长度
                res.push_back(j - start + 1);
                start = j + 1; // 并将start 置为下一段的起始位置
                maxindex = 0; // 将 maxindex 置为 0，重新开始找下一段的分割点
            }
        }
        return res;
    }
};
// 结论:通过
