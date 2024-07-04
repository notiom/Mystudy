// 1.我自己的解
// 暴力解法，直接双循环找出最大值
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        // 双循环选择两者差值最大
        int max_profit = 0;
        int n = prices.size();
        for(int i = 0;i < n;i++)
        {
            for (int j = i + 1; j< n; j++)
            {
               if(prices.at(j) - prices.at(i) > max_profit)
               {
                   max_profit = prices.at(j) - prices.at(i);
               }
            }
        }
        return max_profit;  
    }
};
结论：未通过，超出时间限制

// 2.改进版本
// 思路:一次循环记录当前所遍历到的最低值
// 不断更新当前的最小值和最大利润
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        // 单次循环记录当前的目标点前的最小值和当前利润最大
        int max_profit = 0;
        int n = prices.size();
        int min_price = INT_MAX;
        for(int i = 0;i < n;i++)
        {
            min_price = min(prices[i],min_price);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;  
    }
};
//结论:通过
