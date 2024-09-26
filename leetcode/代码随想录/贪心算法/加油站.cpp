// 1.暴力解法
// 我自己的解
// 外层循环控制起始位置,内层循环判断是否可以满足每一次出发的油都大于消耗
// 超时
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        // 贪心算法
        // 如果使用暴力解法,应该为从每一个索引位置开始加减,如果环路绕了一周，则存在解
        int n = gas.size();
        for(int i = 0;i < n;i++)
        {
           int j = n;
           int res = gas[i]; // 起始的油箱油量
           int idx = i + 1;
           while(j > 0)
           {
                if(idx == n) 
                {
                    // res = res - cost[n - 1] + gas[0]; //计算结果
                    if(res - cost[n - 1] < 0) 
                    {
                        res = -1;
                        break;
                    } 
                    res = res - cost[n - 1] + gas[0]; // 要分为两步去计算
                    // 如果第一个差值 < 0 就break
                    idx = 1;
                }
                else
                {
                    if(res - cost[idx - 1] < 0) 
                    {
                        res = -1;
                        break;
                    } 
                    res = res - cost[idx - 1] + gas[idx]; //计算结果
                    idx++;
                }
                j--;
           }
           if(res >= 0) return i;
        }
        return -1;
    }
};
// 结论:未通过

// 2.贪心算法(方式一)
// 利用填补的方式使其满足条件
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        // 贪心算法
        // 如果使用暴力解法,应该为从每一个索引位置开始加减,如果环路绕了一周，则存在解
        // 直接从全局进行贪心选择，情况如下：
        int n = gas.size();
        int min_oil = INT_MAX;
        int curSum = 0;
        for(int i = 0;i < n;i++)
        {
            int res = gas[i] - cost[i]; // 记录这个的累加和
            curSum += res;
            if(curSum < min_oil)
            {
                min_oil = curSum;
            }
        }
        // 情况一：如果gas的总和小于cost总和,那么无论从哪里出发,一定是跑不了一圈的

        if(curSum < 0) return -1;

        // 情况二：rest[i] = gas[i]-cost[i]为一天剩下的油，i从0开始计算累加到最后一站，如果累加没有出现负数，说明从0出发，油就没有断过，那么0就是起点。
        if(min_oil >= 0) return 0;
        // 情况三：如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪个节点能把这个负数填平，能把这个负数填平的节点就是出发节点。
        for(int i = n - 1;i >= 0;i--)
        {
            // 从后向前遍历是关键,因为在出发时要从前向后,就算从前向后将其填满,出发的索引位置也不对
            min_oil += (gas[i] - cost[i]);
            if(min_oil >= 0) return i;
        }
        return -1;
    }
};
// 结论:时间复杂度 o(n),空间复杂度o(1).

// 3.贪心算法(方式二)
// 通过区间的方式,累加如果不大于0，那么说明当前位置一定使他变得更负
// 在之前的计算中都为正,所以最一开始累加都不行,说明后面更不行
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        // 贪心算法
        // 直接从全局进行贪心选择，情况如下：
        int n = gas.size();
        int totalSum = 0; // 只要总和大于0,那一定有位置可以
        int curSum = 0; 
        int start = 0; // 只要curSum还大于0,那就一定可以从这个位置出发
        for(int i = 0;i < n;i++)
        {
            int res = gas[i] - cost[i]; // 记录这个的累加和
            curSum += res;
            totalSum += res;
            if(curSum < 0)
            {
                // 从这个区间内的哪个位置出发都会在这里断油
                start = i + 1; // 起始位置更新为i+1 
                curSum = 0; // 重新开始累积
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
};
// 结论:通过 时间复杂度o(n),空间复杂度o(1).
