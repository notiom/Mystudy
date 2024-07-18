//1.自己的解
//利用公式旋转90度，即当前位置的值应该为原容器中matrix[m * (m  - 1) + 行数 - 列数 * m]，之后再定义一个容器将其索引位置保存即可
class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        //正向旋转公式
        // i = 7 + y - 3x
        vector<int> vec; //将二维容器展成一维
        vector<int> idx; //该容器记录对应的索引值，类似于哈希表 ,因为可能有重复元素，所以不可以用哈希表
        int m = matrix.size();
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < m;j++)
            {   
                //展成一维
                vec.push_back(matrix.at(i).at(j));
                //记录对应的索引值
                idx.push_back((m * (m - 1)) + i - m * j);
            }
        }
        int k = 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < m;j++)
            {
                //将一维容器中的元素重新赋值给二维容器
                matrix.at(i).at(j) = vec.at(idx.at(k++));
            }
        }
        
    }
};
//结论：通过
//2.官方题解
/////////////////////////////
class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        //0行0列变为0行n - 1列,1行0列0行n - 2列
        vector<vector<int>> matrix_copy(matrix);
        int n = matrix.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrix_copy.at(j).at(n - 1 - i) = matrix.at(i).at(j);
            }
        }
        //值拷贝
        matrix = matrix_copy;
    }
};
//结论：通过，同样空间复杂度降低，他直接计算出了索引值，而无需像我这样保存索引值
