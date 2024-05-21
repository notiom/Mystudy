//1.自己的解
//思路：设置一个idx容器变量，将0所在的行列保存在容器中，之后在一个循环中将其置为0
class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m =matrix.size(); //行
        int n = matrix[0].size(); //列
        vector<vector<int>> idx;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(matrix.at(i).at(j) == 0)
                {
                    idx.push_back(vector<int>{i,j});
                }
            }
        }

        while(!idx.empty())
        {
            vector<int> temppop = idx.back();
            idx.pop_back();
            for(int j = 0;j< n;j++)
            {   //将行置为0
                 matrix.at(temppop.at(0)).at(j) = 0;
            }

            for(int i = 0;i < m;i++)
            {
                //将列置为0
                matrix.at(i).at(temppop.at(1)) = 0;
            }            
        }
    }
};
//结论：通过
	
//2.官方题解
	
从左上角遍历处理：行从第0行遍历，列从第1列遍历，思路：第一次循环 1、0行数组的每个元素临时标识该元素所在列是否有0，0列数组的每个元素临时标识该元素所在行是否有0。 2、判断每行的第0列是否为0，有则赋值额外的标识字段，该字段的作用是用于后续对称遍历的时候，赋值所有行的0列是否应该赋值0使用

比如原始数组为 [ [2,1,2,3], [2,1,2,3], [3,0,5,2], [1,3,0,5] ]

    // 如果当前遍历位置为0，则该行0列设置标识，以便后续使用
    // 如果当前遍历位置为0，则0行该列设置标识，以便后续使用
    [
        [2,0,0,3],
        [2,1,2,3],
        [0,0,5,2],
        [0,3,0,5]
    ]
    // 第二次循环-从右下角遍历处理：行从最后一行遍历（直到0行），列从最后一列遍历(直到第一列)
    // 使用0行数组、0列数组判断当前遍历位置是否应该置0
    // 注意需要额外使用标识字段判断该行0列是否应该置0
    // 处理完成之后
    [
        [2,0,0,3],
        [2,0,0,3],
        [0,0,0,0],
        [0,0,0,0]
    ]
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)  {
        bool col0_flag = false;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) col0_flag = true;
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0_flag) matrix[i][0] = 0;
        }
    }
};
//结论：时间复杂度很低
