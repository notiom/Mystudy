// 1.代码随想录官方题解
// 使用回溯
// 主要思想是将n皇后可以简化为n个皇后不能同行，不能同列，不能同斜线
class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        // n皇后可以简化为n个皇后不能同行，不能同列，不能同斜线
        // 回溯算法
        vector<string> chessboard(n,string(n,'.')); //这是可能的一种情况
        backtracking(n,0,chessboard);
        return res;
    }
private:
    vector<vector<string>> res;
    void backtracking(int n,int row,vector<string>& chessboard)
    {
        // 检查是否满足最终条件
        if(row == n) 
        {
            res.push_back(chessboard);
            return;
        }

        for(int col = 0;col < n;col++)
        {
            if(isValid(row,col,chessboard,n))
            {
                // 说明当前行可以被选择
                chessboard[row][col] = 'Q';
                backtracking(n,row+1,chessboard);
                chessboard[row][col] = '.'; // 撤销上次的操作
            }
        }
    }

    bool isValid(int row, int col, vector<string>& chessboard, int n)
    {
        // 检查列是否满足条件
        for(int i = 0;i < row;i++)
        {
            // 只需要到本行即可,因为下一行还没有开始
            if(chessboard[i][col] == 'Q')
            {
                // 发现在当前列上存在皇后
                return false;
            }
        }

        // 检查左上方45度角
        for(int i = row - 1,j = col - 1; i >= 0 && j >= 0; i--,j--)
        {
            if(chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        // 检查右上方135度角
        for(int i = row - 1,j = col + 1; i>=0 && j < n; i--,j++)
        {
            if(chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};
// 结论:时间复杂度o(n!) 空间复杂度o(n * n).


