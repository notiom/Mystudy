//1.使用广度优先遍历
//我自己的解

class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        // 思路为利用广度优先遍历探索是否有符合的一条路径
        // 该路径存放有符合条件的行列数
        queue<pair<int,int>> que;
        // 存放还可以遍历的行列
        vector<vector<bool>> isiter;
        int raw = board.size();
        if(raw == 0) return false;
        int col = board.at(0).size();
        isiter.resize(raw);
        int n = word.size(); // word的长度
        int count = 0; //如果最后结果为word.size就说明成功找到
        for(int i = 0;i < raw;i++)
        {
            isiter.at(i).resize(col);
            for(int j = 0;j < col;j++)
            {
                if(board.at(i).at(j) == word[0])
                {
                    // 题意为word >= 1
                    que.push({i,j});
                    count = 1;
                }
                isiter.at(i).at(j) = true;
            }
        }
        while(!que.empty() && count != n)
        {
            int S_size = que.size();
            bool flag = false; // 本轮是否有元素入队，如果有，说明广度优先遍历找到
            vector<pair<int,int>> temp; //本轮循环结束后在统一将其赋值为false
            for(int i = 0; i < S_size;i++)
            {
                pair<int,int> p = que.front();
                que.pop();
                int curraw = p.first;
                int curcol = p.second;
                // 将当前位置视为不可用
                temp.push_back({curraw,curcol});
                //四个方向
                // 上
                if(curraw - 1 >= 0 && isiter.at(curraw - 1).at(curcol) && board.at(curraw - 1).at(curcol) == word.at(count))
                {
                    que.push({curraw - 1, curcol});
                    flag = true;
                }
                // 下
                if(curraw + 1 < raw && isiter.at(curraw + 1).at(curcol) && board.at(curraw + 1).at(curcol) == word.at(count))
                {
                    que.push({curraw + 1, curcol});
                    flag = true;
                }
                // 左
                if(curcol - 1 >= 0 && isiter.at(curraw).at(curcol - 1) && board.at(curraw).at(curcol - 1) == word.at(count))
                {
                    que.push({curraw, curcol - 1});
                    flag = true;
                }
                // 右
                if(curcol + 1 < col && isiter.at(curraw).at(curcol + 1) && board.at(curraw).at(curcol + 1) == word.at(count))
                {
                    que.push({curraw, curcol + 1});
                    flag = true;
                }

            }
            for(const auto &num : temp)
            {
                isiter.at(num.first).at(num.second) = false;
            }
            if(flag)
            {
                count++;
                if(count == n) return true;
            }
            
        }
        if(count == n) return true;
        return false;
    }
};
//结论：某些测试用例不过，并不知是什么原因

//2.官方题解回溯
//迭代法，代码还是有点难理解
class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();

        // 遍历每个起点
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                visited = vector<vector<bool>>(rows, vector<bool>(cols, false)); // 初始化访问标记
                if (check(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    vector<vector<bool>> visited;
    vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool check(vector<vector<char>>& board, string word, int row, int col, int index)
    {
        if (index == word.size()) return true; // 匹配整个单词
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false; // 越界检查
        if (board[row][col] != word[index]) return false; // 字符不匹配
        if (visited[row][col]) return false; // 已经访问过

        visited[row][col] = true; // 标记为已访问

        bool result = false;
        for (const auto& dir : direction)
        {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (check(board, word, newRow, newCol, index + 1))
            {
                result = true;
                break;
            }
        }

        visited[row][col] = false; // 取消标记，进行回溯
        return result;
    }
};
//结论:通过


//3.使用dfs深度优先遍历
// 在递归调用每行每列之后返回||，就可以只要有元素满足就返回true，并且要在每轮迭代之后复原board
class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        // 法三:使用回溯 + 递归
        int raw = board.size();
        int col = board.at(0).size();
        for(int i = 0; i < raw; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(board.at(i).at(j) == word.at(0) && dfs(board,word,i,j,0))              
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word,int raw,int col,int index)
    {
        if(index == word.size()) return true;
        if(raw < 0 || col < 0 || raw >= board.size() || col >= board.at(0).size()) return false;
        if(board.at(raw).at(col) != word.at(index)) return false;
        auto board_val = board.at(raw).at(col); 
        
        // 将其换做一个非字母的char
        board.at(raw).at(col) = '0';
        bool result = dfs(board,word,raw - 1,col,index + 1)
        || dfs(board,word,raw + 1,col,index + 1)
        || dfs(board,word,raw,col - 1,index + 1)
        || dfs(board,word,raw,col + 1,index + 1);
        board.at(raw).at(col) = board_val;
        return result;
    }
};
//结论:通过，代码简洁，可读性强
