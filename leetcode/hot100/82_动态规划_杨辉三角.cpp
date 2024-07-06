// 1.我自己的解
// 思路:将两边的元素置为1，其余的通过上一个back容器中的元素相加
class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        // 观察规律发现，两边都是1
        // 思路：将vector的左右边界设置为1，再将前一个vector的元素相加
        vector<vector<int>> res;
        res.push_back(vector<int>{1});
        if(numRows == 1) return res;
        res.push_back(vector<int>{1,1});
        for(int i = 2; i < numRows;i++)
        {
            // 其中以2为索引是指从0开始计数的第三行
            vector<int> temp;
            vector<int> prevec = res.back(); //将上一个容器的元素拿出
            for(int j = 0;j <=i;j++)
            {
                //从temp中push值
                if(j == 0 || j == i) 
                {
                    temp.push_back(1);
                    continue;
                }
                temp.push_back(prevec[j-1] + prevec[j]); // 将上一层的元素相加
            }
            res.push_back(temp); // 加入到结果中
        }
        return res;  // 最后返回结果
    }

};
// 结论:通过，时间复杂度，空间复杂度还未分析
// 预估时间复杂度为o(n * n),空间复杂度 o(n * n) 因为要计算结果

//2. 官方题解
// 将每下一行都在两边添加一个新的0元素，在与上一个元素相加
class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        // 观察规律发现，两边都是1
        // 思路：将vector的左右边界在每一轮相加时都补充一个0，这样两边就自动为1
        vector<vector<int>> res;
        res.push_back(vector<int>{1});
        for(int i = 1; i < numRows;i++)
        {
           vector left = res.back();
           vector right(left);
           left.insert(left.begin(), 0);  // 左边界补0
           right.push_back(0);  // 右边界补0
           for(int j = 0;j <=i;j++) left.at(j) = left.at(j) + right.at(j);
           res.push_back(left);  // 加入新一行的vector到res中
        }
        return res;  // 最后返回结果
    }
};
//结论:通过
