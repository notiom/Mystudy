// 1.我自己的解
// 将每个位置所要到达的最少步数记录到一个容器中，最后当curmaxindex第一次满足条件时，直接return vec的最后一个元素，就是最小步数
class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        // 思路:和到达最大距离的题目相似，只不过此时需记录一下到达每个点的最小步数
        // 如果当前的位置被之前到达过，那么在该位置上的索引就不被改变
        // 如果该位置没有被到达过，那么就是置为上一个数 + 1
        int n = nums.size();
        // 该容器记录每个索引位置需要最少几步
        // 该变量记录当前可以到的最大索引
        int curmaxindex = 0;
        vector<int> res(n,0);
        for(int i = 0;i < n - 1;i++)
        {
            // 找到前一个元素能跳到的所有位置，将其置为步数
            for(int j = i + 1;(j <= (nums.at(i) + i) || j <= curmaxindex) && j < n;j++)
            {
                if(j > curmaxindex)
                {
                    res.at(j) = res.at(i) + 1;
                }
            }
            curmaxindex = max(curmaxindex,nums.at(i) + i);
            if(curmaxindex >= n - 1) return res.back();
        }
        return res.back();
    }
};
//结论:通过 时间复杂度 o(n * n) ,空间复杂度o(n)
