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
class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        if(matrix.empty()) return res;
        int upper = 0;
        int lower = matrix.size() - 1;
        int left = 0;
        int right = matrix.at(0).size() - 1;
        while(true)
        {
            //从左到右遍历 - > 当i到有边界时直接退出本次循环
            cout << "1: ";
            for(int i = left;i <=right;i++)
            {
                res.push_back(matrix.at(upper).at(i));
                cout << res.back();
            }
            cout << endl;        
            //重新设定上边界，若上边界大于下边界，退出循环
            if(++upper > lower) break; //避免了使用nextrow和nextcol等变量

            //从上到下遍历 |||
            cout << "2: ";
            for(int i = upper;i <= lower;i++)
            {
                res.push_back(matrix.at(i).at(right));
                cout << res.back();
            }
            cout << endl;
            //重新设定右边界，若右边界小于左边界，退出循环
            if(--right < left) break;
            //从右到左遍历 <-(此处不能从right开始，不然右下角的数会遍历两次)
            cout << "3: ";
            for(int i = right;i >= left;i--)
            {
                res.push_back(matrix.at(lower).at(i));
                cout << res.back();
            }
            cout << endl;
            if(--lower < upper) break;

            //从下到上遍历 ||
            cout << "4: ";
            for(int i = lower;i >= upper;i--)
            {
                res.push_back(matrix.at(i).at(left));
                cout << res.back();
            }
            cout << endl;
            if(++left > right) break;
        }
        return res;
    }
};
//结论:通过，不需要设置方向数组，空间复杂度很低，关键是判断是否上下或者左右边界重合，且利用++提前判断下一个元素是否大于边界，如果大于，就退出
