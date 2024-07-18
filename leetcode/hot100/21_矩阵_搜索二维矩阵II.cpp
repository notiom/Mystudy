//1.自己的解，利用中心点分治
//思路：先用对角线的中心点，判断大小，如果当前值大于目标值，那么可以排除右下角，反之则排除左下角，当分治矩阵到达有一方长度为1时，变为2分查找
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //二分查找(相当于相对于左上角和右下角应用二分查找)
        //之后判断大小，如果大于目标值，排除左上角的快，反之则排除右下角的块
        int m = matrix.size() - 1;
        int n = matrix.at(0).size() - 1;
        if(m == 0)
        {
            // 此时说明在分治矩阵块中只有一行或者一列，变成普通的二分查找
            int left = 0;
            int right = n;
            int pointer;
            while(left <= right)
            {
                pointer = (left + right) >> 1;
                if(target < matrix.at(0).at(pointer))
                {
                    right = pointer - 1;
                }
                else if(matrix.at(0).at(pointer) < target)
                {
                    left = pointer + 1;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }

        if(n == 0)
        {
            // 此时说明在分治矩阵块中只有一行或者一列，变成普通的二分查找
            int left = 0;
            int right = m;
            int pointer;
            while(left <= right)
            {
                pointer = (left + right) >> 1;
                if(target < matrix.at(pointer).at(0))
                {
                    right = pointer - 1;
                }
                else if(matrix.at(pointer).at(0) < target)
                {
                    left = pointer + 1;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
        int currentcol = m / 2;
        int currentrow = n / 2;
        if(target == matrix.at(currentrow).at(currentcol)) return true;
        else if(target < matrix.at(currentrow).at(currentcol))
        {
            //舍弃右下角的矩阵
            //左上
            return searchMatrix(getSubmatrix(matrix,0,0,currentrow - 1,currentcol - 1),target) ||
            //左下
            searchMatrix(getSubmatrix(matrix,currentrow,0,m,currentcol - 1),target) ||
            //右上
            searchMatrix(getSubmatrix(matrix,0,currentrow,currentrow - 1,n),target);
        }
        else if(target > matrix.at(currentrow).at(currentcol))
        {
            //舍弃左上角的矩阵
            //右下
            return searchMatrix(getSubmatrix(matrix,currentrow + 1,currentcol + 1,m,n),target) ||
            //左下
            searchMatrix(getSubmatrix(matrix,currentrow + 1,0,m,currentcol),target) ||
            //右上
            searchMatrix(getSubmatrix(matrix,0,currentrow + 1,currentrow,n),target);
        }
        return false;
    }
private:
    vector<vector<int>> &getSubmatrix(const vector<vector<int>>& matrix, int startRow, int startCol, int endRow, int endCol) 
    {
        vector<vector<int>> submatrix;
        // Check bounds
        if (startRow < 0 || startCol < 0 || endRow >= matrix.size() || endCol >= matrix[0].size() || startRow > endRow || startCol > endCol) {
            cout << "Invalid submatrix bounds!" << endl;
            return submatrix;
        }

        for (int i = startRow; i <= endRow; ++i) {
            vector<int> row;
            for (int j = startCol; j <= endCol; ++j) {
                row.push_back(matrix[i][j]);
            }
            submatrix.push_back(row);
        }

        return submatrix;
    }

};
// 结论：未实现，代码执行出错
// 2.同思路重写
/////////////////////

																							
//3.官方题解
/*
“根节点” 对应的是矩阵的 “左下角” 和 “右上角” 元素，本文称之为 标志数 ，以 matrix 中的 左下角元素 为标志数 flag ，则有:

若 flag > target ，则 target 一定在 flag 所在 行的上方 ，即 flag 所在行可被消去。
若 flag < target ，则 target 一定在 flag 所在 列的右方 ，即 flag 所在列可被消去。
算法流程：
从矩阵 matrix 左下角元素（索引设为 (i, j) ）开始遍历，并与目标值对比：
当 matrix[i][j] > target 时，执行 i-- ，即消去第 i 行元素。
当 matrix[i][j] < target 时，执行 j++ ，即消去第 j 列元素。
当 matrix[i][j] = target 时，返回 truetruetrue ，代表找到目标值。
若行索引或列索引越界，则代表矩阵中无目标值，返回 falsefalsefalse 。
每轮 i 或 j 移动后，相当于生成了“消去一行（列）的新矩阵”， 索引(i,j) 指向新矩阵的左下角元素（标志数），因此可重复使用以上性质消去行（列）。
*/
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //类似于二叉搜索树
        //立扣官方使用从左下到右上，我使用从右上到左下
        // 若target < 当前根节点， 则当前列可以消去
        // 若taeget > 当前根节点， 则当前行可以消去

        int row = 0; //定义的当前行
        int n = matrix.size();
        int col = matrix[0].size() - 1; //定义的当前列
        while(row < n && col >= 0)
        {   
            //防止数组越界
            if(target < matrix.at(row).at(col))
            {
                col --;
            }
            else if(target > matrix.at(row).at(col))
            {
                row ++;
            }
            else return true;
        }
        return false;
    }

};
//结论:通过(z字形查找)
