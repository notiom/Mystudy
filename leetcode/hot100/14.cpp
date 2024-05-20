//1.自己的解，
// 我的情况必须应对左区间必须要小于右区间才可以
class Solution 
{
public:
    static bool cmp(vector<int> &num1,vector<int> &num2)
    {
        return num1.at(0) < num2.at(0);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res; //定义输出结果
        vector<int> currentres; //要push的res结果
        sort(intervals.begin(),intervals.end(),cmp); // 按照第一个元素进行排序
        int n = intervals.size(); //二维容器的长度
        int leftbind;
        int rightbind;
        if(n == 1) return intervals;
        for(int i = 0; i < n;)
        {
            int leftbind = intervals[i][0];
            int rightbind = intervals[i][1];
            if(i == n - 1)
            {
                //说明最后一个元素还没有被push，且他是孤立的
                res.push_back(vector<int>{leftbind,rightbind});
                return res;
            }
            for(int j = i + 1; j < n; j++)
            {   
                //两层循环表示对当前元素后面有多少元素要合并
                if(rightbind < intervals[j][0])
                {
                    //如果左边元素的右边界小于右边元素的左边界，说明没有交集,直接push
                    res.push_back(vector<int>{leftbind,rightbind});
                    i = j; //令i = j,省略已经被合并的轮次
                    break; //跳出这轮循环
                }
                else if(rightbind > intervals[j][1])
                {
                    //说明左边完全包含右边，使i = j
                    leftbind = intervals[i][0];
                    rightbind = intervals[i][1];
                    if(j == n - 1)
                    {
                        res.push_back(vector<int>{leftbind,rightbind});
                        return res;
                    }
                    else
                    {
                        i = j;
                    }
                }
                else
                {
                    //元素出现交集,要合并并且继续向后遍历
                    rightbind = intervals[j][1];
                    if(j == n - 1)
                    {
                        //说明最后一个元素还没有被push，且他是孤立的,执行到末尾都没有运行i = j的一步
                        res.push_back(vector<int>{intervals[i][0],rightbind});
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
//2. 针对此种情况，可以选取一个这两种合并情况的最大值即可
	
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res; //定义输出结果
        sort(intervals.begin(),intervals.end(),cmp); //按照第一个元素进行排序
        int n = intervals.size();
        if(n == 1) return intervals;
        for(int i = 0;i < n;)
        {
            if(i == n - 1) 
            {   
                res.push_back(vector<int>{intervals.at(i).at(0),intervals.at(i).at(1)});
                break;
            }
            int rightbind = intervals.at(i).at(1);
            for(int j = i + 1;j < n;j++)
            {
                if(rightbind < intervals.at(j).at(0))
                {
                    //说明当前元素的右边界小于下一个元素的左边界，无重叠区域，直接入栈
                    res.push_back(vector<int>{intervals.at(i).at(0),rightbind});
                    i = j; //省略掉前面合并的所有轮次
                    break;
                }
                else
                {
                    //要发生合并
                    rightbind = max(rightbind,intervals.at(j).at(1)); //要一直更新
                    if(j == n - 1)
                    {
                        //到最后一个元素全部合并完成
                        res.push_back(vector<int>{intervals.at(i).at(0),rightbind});
                         return res;
                    }
                }
            }
        }
        return res;
    }
private:
    static bool cmp(vector<int> &num1,vector<int> &num2)
    {
        return num1.at(0) < num2.at(0);
    }
};
//结论：通过，在这个例子中要注意
1.合并相同项时，如果直到最后一个元素都每个都重合，就应该把左边界最小的元素和rightbind push进res并返回
2.当恰好最后一个元素不重合时，无法进入第二个循环，此时应该把最后一个元素push进res，并将主循环退出	 

//3.改进版代码(将当前元素push进去，如果有重合，在改变该元素的右边界)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res; //定义输出结果
        sort(intervals.begin(),intervals.end(),cmp); //按照第一个元素进行排序
        int n = intervals.size();
        for(int i = 0;i < n;i++)
        {
            //假设每个元素都不重合，每个元素都遍历
            //push条件为第一个元素和没有重合的情况
            if(!res.size() || res.back().at(1) < intervals.at(i).at(0))
            {
                res.push_back({intervals.at(i).at(0),intervals.at(i).at(1)});
            }
            else
            {
                //有元素重合,改变最后一个元素
                res.back().at(1) = max(res.back().at(1),intervals.at(i).at(1));
            }
        }
        return res;
    }
private:
    static bool cmp(vector<int> &num1,vector<int> &num2)
    {
        return num1.at(0) < num2.at(0);
    }
};
