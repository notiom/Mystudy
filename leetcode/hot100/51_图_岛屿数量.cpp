//1.官方题解
//思路，依次遍历每个格子，如果之前已经遍历过就将其置为1，每次只要遇到陆地，那么他必定可以构成一个岛屿，就自增
//使用深度优先遍历计算最大连通区域
class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int col = grid.size();
        if(col == 0) return 0;
        int row = grid.at(0).size();

        for(int i = 0; i < col; i++)
        {
            for(int j = 0; j < row; j++)
            {
                if(grid.at(i).at(j) == '1')
                {
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(!isArea(grid,i,j)) return;

        if(grid.at(i).at(j) != '1') return;

        //这里不使用岛屿沉没，会造成不必要的麻烦
        grid.at(i).at(j) = '2';

        //访问上下左右四个相邻的节点
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }

    bool isArea(vector<vector<char>>& grid,int i, int j)
    {
        return i>=0 && j>=0 && i<grid.size() && j<grid.at(0).size();
    }
private:
    int res = 0;

};

//结论：通过

//2.法二，利用队列的方式实现广度优先遍历

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid.at(0).size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid.at(i).at(j) == '1')
                {
                    res++;
                    grid.at(i).at(j) = '2';
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    while(!que.empty())
                    {
                        int currow = que.front().first;
                        int curcol = que.front().second;

                        que.pop();
                        if(currow - 1 >= 0 && grid.at(currow - 1).at(curcol) == '1')
                        {
                            que.push({currow - 1, curcol});
                            grid.at(currow - 1).at(curcol) = '2';
                        }
                        if(currow + 1 < row && grid.at(currow + 1).at(curcol) == '1')
                        {
                            que.push({currow + 1, curcol});
                            grid.at(currow + 1).at(curcol) = '2';
                        }
                        if(curcol - 1 >= 0 && grid.at(currow).at(curcol - 1) == '1')
                        {
                            que.push({currow, curcol - 1});
                            grid.at(currow).at(curcol - 1) = '2';
                        }
                        if(curcol + 1 < col && grid.at(currow).at(curcol + 1) == '1')
                        {
                            que.push({currow, curcol + 1});
                            grid.at(currow).at(curcol + 1) = '2';
                        }
                    }

                }
            }
        }
        return res;
    }

private:
    int res = 0;

};
//结论：通过
