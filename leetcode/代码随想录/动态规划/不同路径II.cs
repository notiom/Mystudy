// 1.我自己的解
// 使用原数组原地进行修改
// 只是在障碍物出不进行初始化，使其为0
public class Solution 
{
    public int UniquePathsWithObstacles(int[][] obstacleGrid) 
    {
        // 不同路径2
        // 有障碍物的情况
        // 可以直接改变原数组来进行动态规划
        int m = obstacleGrid.Length;
        int n = obstacleGrid[0].Length;
        // 如果起点或终点有障碍物，直接返回0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }
        
        bool flag = true;

        // 完成初始化和初始列的赋值
        for(int i = 0;i < m;i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                flag = false;
            }
            obstacleGrid[i][0] = flag? 1 : 0;
        }

        flag = true;
        for(int j = 1;j < n;j++)
        {
            // 此处的j应该从1开始，不然将会覆盖掉之前第一遍列初始化
            if(obstacleGrid[0][j] == 1)
            {
                flag = false;
            }
            obstacleGrid[0][j] = flag? 1 : 0;
        }

        for(int i = 1;i < m;i++)
        {
            for(int j = 1;j < n;j++)
            {
                // 进行dp数组填充
                if(obstacleGrid[i][j] == 1)
                {
                    obstacleGrid[i][j] = 0;
                }
                else
                {
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
                }
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
}
// 结论:时间复杂度为o(n),空间复杂度为o(n).
