// 1.我自己的解
//  利用迭代判断时间
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        //复制一个临时改变的二维容器
        vector<vector<int>> nums = grid; 
        int row = grid.size();
        if(row == 0) return -1;
        int col = grid.at(0).size();
        int res = 0;
        while(1)
        {
            bool flag = false; //只要有一个进入if，发生了腐蚀变化，就说明腐蚀仍在进行
            for(int i = 0;i < row;i++)
            {
                for(int j = 0;j < col;j++)
                {
                    if(grid.at(i).at(j) == 2)
                    {
                        //腐烂的橘子开始腐蚀
                        if(i - 1 >=0 && grid.at(i - 1).at(j) == 1)
                        {
                            //当且仅当不超出边界且是一个新鲜的橘子的情况
                            nums.at(i - 1).at(j) = 2;
                            flag = true;
                        }
                        if(j - 1 >=0 && grid.at(i).at(j - 1) == 1)
                        {
                            nums.at(i).at(j - 1) = 2;
                            flag = true;
                        }
                        if(i + 1 < row && grid.at(i + 1).at(j) == 1)
                        {
                            nums.at(i + 1).at(j) = 2;
                            flag = true;
                        }
                        if(j + 1 < col && grid.at(i).at(j + 1) == 1)
                        {
                            nums.at(i).at(j + 1) = 2;
                            flag = true;
                        }
                    }
                }
            }
            // 当遍历完一轮时,需要判断是否和上一次未计算的一样，如果一样，说明本轮本没有发生腐蚀
            // 之后在检查是否元素没有1，如果没有1，则返回当前的值，否则返回-1
            if(!flag)
            {
                //本轮未发生腐蚀
                for(auto num : nums)
                {
                    for(int single : num)
                    {
                        if(single == 1)
                        {
                            return -1;
                        }
                    }
                }
                return res;
            }
            else
            {
                res++;
                grid = nums;
            }
        }
    }
};
	// 结论：通过
	// 每次都重复遍历之前已经遍历过的位置，并且新增一个额外的容器
	// 如何使用广度优先遍历？
	
	//2.官方题解
	//巧妙的使用一个count变量节省时间复杂度和空间复杂度
	class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // 思路为通过一个count变量记录一个新鲜橘子的个数
        // 如果广度优先遍历结束之后还没有变为0
        // 说明有不能被污染的橘子
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid.at(0).size();
        int count = 0; //新鲜橘子的数量
        queue<pair<int,int>> que;
        for(int i = 0;i < row;i++)
        {
            for(int j = 0;j < col;j++)
            {
                if(grid.at(i).at(j) == 1) count++;
                if(grid.at(i).at(j) == 2) que.push({i,j});
            }
        }
        int res = 0; //定义输出结果
        while(count > 0 && !que.empty())
        {
            int S_size = que.size(); //定义本轮的队列长度
            for(int i = 0;i < S_size;i++)
            {
                int currow = que.front().first;
                int curcol = que.front().second;
                que.pop();
                //腐蚀逻辑处理
                if(currow - 1 >=0 && grid.at(currow - 1).at(curcol) == 1)
                {
                    //当且仅当不超出边界且是一个新鲜的橘子的情况
                    grid.at(currow - 1).at(curcol) = 2;
                    count--;
                    que.push({currow - 1,curcol});
                }
                if(curcol - 1 >=0 && grid.at(currow).at(curcol - 1) == 1)
                {
                    grid.at(currow).at(curcol - 1) = 2;
                    count--;
                    que.push({currow,curcol - 1});
                }
                if(currow + 1 < row && grid.at(currow + 1).at(curcol) == 1)
                {
                    grid.at(currow + 1).at(curcol) = 2;
                    count--;
                    que.push({currow + 1,curcol});
                }
                if(curcol + 1 < col && grid.at(currow).at(curcol + 1) == 1)
                {
                    grid.at(currow).at(curcol + 1) = 2;
                    count--;
                    que.push({currow,curcol + 1});
                }
            }
            res++;
        }
        if(count > 0) return -1;
        return res;
    }
};
//结论：通过

//只要从队列的角度去思考就时广度优先遍历
