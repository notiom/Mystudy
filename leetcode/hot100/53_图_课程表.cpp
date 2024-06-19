//1.官方题解
// 使用拓扑排序构建有向无环图
//引入了入度的概念
class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // 有向无环图
        // 拓扑排序
        // 使用一个int容器保存每个节点的入度，初始化为0
        vector<int> inDegree(0);
        inDegree.resize(numCourses);
        // 使用一个哈希表/二维邻接矩阵记录课与课（节点）之间的关系 int -> vector<int>
        unordered_map<int,vector<int>> maps;

        //初始化入度和所属关系
        int n = prerequisites.size();
        for(int i = 0; i < n;i++)
        {
            inDegree.at(prerequisites.at(i).at(0))++;
            // 谁要依赖于他就把谁添加进去
            // 假设0 1 都依赖于2 那么当前哈希表就为 2 : <0 , 1>
            maps[prerequisites.at(i).at(1)].push_back(prerequisites.at(i).at(0));//添加依赖他的后续课
        }

        queue<int> que;
        // 入度为0的节点入队
        for(int i = 0;i < numCourses;i++)
        {
            if(inDegree.at(i) == 0) que.push(i);
        }

        int count = 0; //完成课程的数目
        while(!que.empty())
        {
            int cur = que.front();
            que.pop(); //出列
            count++; // 所选课加1
            vector<int> toEnQueue = maps[cur]; //后续所有依赖于他的课的入度都可以减1
            int m = toEnQueue.size();
            if(m)
            {
                //如果他后续有依赖于他的课
                for(int i = 0;i < m;i++)
                {
                    if(inDegree[toEnQueue[i]] > 0)
                    {
                        inDegree[toEnQueue[i]]--; //此时使入度减1
                        if(inDegree[toEnQueue[i]] == 0) que.push(toEnQueue[i]); //入度为0的入队
                    }
                    
                }
            }
            
        
        }
        if(count == numCourses) return true;
        return false;
    }
};
//结论：拓扑排序使程序自己完成是否可以完成所有课程
// 其实将有向图构建出来之后问题就变成了广度优先遍历
