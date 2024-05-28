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
