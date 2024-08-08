// 完全背包的核心就是从前往后遍历,使得后面的可以用前面的结果
void test_CompletePack() 
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) 
    { 
        // 遍历物品
        for(int j = weight[i]; j <= bagWeight; j++) 
        { 
            // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
}
