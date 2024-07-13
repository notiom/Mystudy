// 1.我自己的解
// 和不同路径的动态规划相似
// 只要利用上一行和左一列的数据更新即可
class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        // 最短路径是上一个位置的上面的加左边的得到的最小值作为当前值

        // 先初始化第一行和第一列
        int m = grid.size();
        int n = grid.at(0).size();
        vector<int> pre(n,grid.at(0).at(0));
        vector<int> res(n);
        for(int i = 1;i < n;i++)
        {
            // 初始化第一行
            pre.at(i) = pre.at(i - 1) + grid.at(0).at(i);
        }
        if(m == 1) return pre.back();

        for(int j = 1;j < m;j++)
        {
            res.at(0) = pre.at(0) + grid.at(j).at(0);
            for(int k = 1;k < n;k++)
            {
                // 两层循环计算动态规划方程
                // res的当前值应该为上方的元素的最小值加上左边加当前元素的最小值
                res.at(k) = min((pre.at(k) + grid.at(j).at(k)),res.at(k - 1) + grid.at(j).at(k));
            }
            pre = res;
        }
        return res.back();
    }
};
// 结论:通过 时间复杂度 o(m * n) 空间复杂度o(n)

// 2.不消耗额外空间的改进方案
// 直接改变原数组
class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        // 最短路径是上一个位置的上面的加左边的得到的最小值作为当前值

        // 先初始化第一行和第一列
        // 优化方式为直接使用原矩阵更新，不使用额外的空间
        int m = grid.size();
        int n = grid.at(0).size();
        for(int i = 1;i < n;i++)
        {
            // 初始化第一行
            grid.at(0).at(i) = grid.at(0).at(i - 1) + grid.at(0).at(i);
        }

        for(int j = 1;j < m;j++)
        {
            grid.at(j).at(0) = grid.at(j - 1).at(0) + grid.at(j).at(0);
            for(int k = 1;k < n;k++)
            {
                // 两层循环计算动态规划方程
                // res的当前值应该为上方的元素的最小值加上左边加当前元素的最小值
                grid.at(j).at(k) = min((grid.at(j - 1).at(k) + grid.at(j).at(k)),grid.at(j).at(k - 1) + grid.at(j).at(k));
            }
        }
        return grid.at(m - 1).at(n - 1);
    }
};
// 结论:空间复杂度o(1).
