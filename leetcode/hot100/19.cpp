//1.自己的解
// 定义四个方向，分别为右，下，左，上，定义一个reached数组，如果到达就标记标志位，在判断下一次该方向是否可行，如果不行，就改变方向
class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res; //定义输出结果
        int direction[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int currentrow = 0;
        int currentcol = 0;
        int currentdirection = 0; //定义当前方向
        int row = matrix.size();
        int col = matrix.at(0).size();
        int reached[row][col];//作用为记录当前元素是否到达过
        for(int i = 0;i < row;i++)
        {
            for(int j =0;j < col;j++)
            {
                reached[i][j] = 0;
            }
        }
        res.push_back(matrix.at(0).at(0));
        reached[0][0] = 1;
        int value = 2;
        while(value <= row * col)
        {
            int nextrow = currentrow + direction[currentdirection][0];
            int nextcol = currentcol + direction[currentdirection][1];
            if(nextrow < 0 || nextrow >= row || nextcol < 0 || nextcol >= col || reached[nextrow][nextcol] == 1)
            {
                if(currentdirection == 3) 
                {currentdirection = 0;}
                else 
                {currentdirection += 1;} 
            }
            currentrow += direction[currentdirection][0];
            currentcol += direction[currentdirection][1];
            res.push_back(matrix[currentrow][currentcol]);
            reached[currentrow][currentcol] = 1;
            value++;
        }
        return res;
    }
};
//结论：时间复杂度除了赋初值外，仅为o（row * col），空间复杂度略高

//2.官方题解
///////////////////////////////
