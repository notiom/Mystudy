// 使用动态维护一个最大值和最小值
// 暴力解法失效
class Solution 
{
public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        // 暴力解法
        int m = arrays.size();
        int res = 0;
        int leftmin = arrays[0][0],leftmax = arrays[0][0];
        int rightmin = arrays[0].back(),rightmax = arrays[0].back();
        for(int i = 1;i < m;i++)
        {
            // 最大值可能是右边最大值减去左边最小值
            // 也可能是左边最大值减去右边最小值
            // 下方分析的情况为当前行可能是右边最大或者左边最大，也可能不是
            // 1.是最大
            int num1 = max(abs(arrays[i].back() - leftmin),abs(arrays[i][0] - rightmin));
            // 2.不是最大
            int num2 = max(abs(rightmax - arrays[i][0]),abs(leftmax - arrays[i].back()));
            num2 = max(num1,num2);
            res = max(res,num2);
            // 更新这4个变量
            leftmin = min(leftmin,arrays[i][0]);
            leftmax = max(leftmax,arrays[i][0]);
            rightmin = min(rightmin,arrays[i].back());
            rightmax = max(rightmax,arrays[i].back());
        }
        return res;
    }
};
// 结论:时间复杂度为o(m)，空间复杂度为o(1).

// 2.改进版本
class Solution 
{
public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        // 暴力解法
        int m = arrays.size();
        int res = 0;
        int leftmin = arrays[0][0];
        int rightmax = arrays[0].back();
        for(int i = 1;i < m;i++)
        {
            int num = max(abs(arrays[i].back() - leftmin),abs(arrays[i][0] - rightmax));
            res = max(res,num);
            leftmin = min(leftmin,arrays[i][0]);
            rightmax = max(rightmax,arrays[i].back());

        }
        return res;
    }
};
// 省去多余的计算
