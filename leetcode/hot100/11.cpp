//1.我自己的代码
// 思路：利用map存放键最大的数，然后记录count，如果count = 0，就把map中的这个数删除掉
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res; //定义输出结果
        int left = 0;
        int n = nums.size();
        int right = k;
        map<int, int> sortmap;
        for (int i = 0; i < right; i++)
        {
            sortmap[nums[i]]++;
        }
        auto max_it = sortmap.rbegin();
        int currentmax = max_it->first; //返回当前建的最大值
        res.push_back(currentmax);
        while (right < n)
        {
            //当右指针到达边界时结束
            sortmap[nums[left]]--;
            sortmap[nums[right]]++;
            auto max_it = sortmap.rbegin();
            while(1)
            {
                auto max_it = sortmap.rbegin();
                if (max_it->second != 0)
                {
                    break;
                }
                sortmap.erase((++max_it).base());
            }
            //循环结束后找到不为0的最大值
            max_it = sortmap.rbegin();
            currentmax = max_it->first;
            res.push_back(currentmax);
            left++;
            right++;
        }
        return res;
    }
};

//结论：时间复杂度和空间复杂度略高
	
//2.官方题解,利用优先队列，就无需通过哈希表（map）记录一个数的值
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            vector<int> res; //定义输出结果
            int n = nums.size();
            priority_queue<pair<int,int>> q;
            for(int i = 0;i < k;i++)
            {
                q.emplace(nums[i],i); //该队列会自动排序nums[i]的最大值
            }
            res.push_back(q.top().first); //注意优先队列的栈顶就是最大元素
            for(int i = k; i < n;i++)
            {
                q.emplace(nums[i],i);
                // 判断栈顶的这些元素是否需要出栈
                while(q.top().second <= i - k)
                {
                    q.pop(); //将栈顶元素弹出
                }
                res.push_back(q.top().first);
            }
            return res;
        }

};
// 结论：掌握priority_queue，他的类型定义是priority_queue<int,vector<int>,less<int>> q;如果使用这种种类，并没有emplace属性
使用push函数，并且在使用pair时不需要指定后面的两个参数
