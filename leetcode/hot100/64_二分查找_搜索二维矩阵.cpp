// 1.我自己的解
// 由于当前矩阵是有序排列，只需要定义两个指针，起始指向右下角，如果当前元素小于该元素，那么划除当前列
// 反之则划除当前行
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        // 该题逻辑为可以从右上角开始搜索,如果当前元素小于该元素，那么划除当前列
        // 反之则划除当前行
        int raw = matrix.size();
        int col = matrix.at(0).size();
        int curraw = 0; //定义当前遍历的行
        int curcol = col - 1; //定义当前遍历的列
        while(curraw < raw && curcol >= 0)
        {
            // 当curraw = raw - 1时，如果还没有找到就会退出循环
            if(matrix.at(curraw).at(curcol) == target)
            {
                return true;
            }
            else if(matrix.at(curraw).at(curcol) > target)
            {
                curcol--;
            }
            else
            {
                curraw++;
            }
        }
        return false;
    }
};
//结论：通过

//题解2：
// 由题得，在这个矩阵中当前行的的元素都大于上一行的最后一个元素
// 思路：将整体矩阵看作一个二分查找

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix.at(0).size();
        int low = 0, high = m * n - 1;
        while (low <= high) 
        {
            int mid = (high - low) / 2 + low; // 此时避免因为两个数太大无法相加
            int x = matrix.at(mid / n).at(mid % n);
            if (x < target) 
            {
                low = mid + 1;
            } 
            else if (x > target) 
            {
                high = mid - 1;
            } 
            else 
            {
                return true;
            }
        }
        return false;
    }
};
//结论：通过
