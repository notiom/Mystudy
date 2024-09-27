// 1.我自己的解
// 贪心的本质就是找到局部最优反推全局最优解
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        // 每个孩子只能得到一个饼干
        // 所以要尽可能使吃的多的孩子分到大的
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        // Loop
        int left = s.size() - 1; //饼干的指针
        int right = g.size() - 1; //小孩胃口的容量
        int res = 0; //满足胃口的小孩
        while(left >= 0 && right >= 0)
        {
            if(g[right] > s[left])
            {
                // 该小孩满足不了,尝试满足其他小孩
                right--;
                continue;
            }
            // 可以满足这些小孩,指针位移
            res++;
            left--;
            right--;
        }
        return res;
    }
};
// 结论: 通过 时间复杂度是冒泡排序的时间复杂度o(n * log(n)),空间复杂度o(1).

// 2.贪心思路2 小饼干先喂饱小胃口

class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        // 每个孩子只能得到一个饼干
        // 所以要尽可能使吃的多的孩子分到大的
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        // Loop
        int left = 0; //小孩胃口的容量
        int right = 0; //饼干的指针
        int res = 0; //满足胃口的小孩
        while(left < g.size() && right < s.size())
        {
            if(g[left] > s[right])
            {
                // 该小孩满足不了,尝试满足其他小孩
                right++;
                continue;
            }
            // 可以满足这些小孩,指针位移
            res++;
            left++;
            right++;
        }
        return res;
    }
};
// 结论: 通过
