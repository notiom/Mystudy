// 1.我自己的解
//  使用递归调用自身先将当前的元素去掉一个作为子集，之后使用集合去重
// 但是时间复杂度太高了
class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        //思路:先选出只包含少一个元素的子集,之后将他们合并
        // 法一：对列
        int n = nums.size();
        uniqueRows.insert(vector<int>()); 
        sunHelper(nums,0,n - 1);
        //在循环结束后还需要添加自己本身
        uniqueRows.insert(nums);
        //将其转换为二维vector输出
        return vector<vector<int>>(uniqueRows.begin(),uniqueRows.end());

    }

    void sunHelper(vector<int> &nums,int start,int end)
    {
        if(start > end)
        {
            return;
        }
        for(int i = start;i <= end;i++)
        {
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            //当前就是一个子集
            uniqueRows.insert(temp);
            sunHelper(temp,start,end - 1);
        }
    }

private:
    // 使用set去重
    set<vector<int>> uniqueRows;
};
	
//结论：测试用例耗时太长了
	
	// 2.结合全排列的回溯思想重做
	// 但是还是需要加入循环和去重的思想
	
	// 3.官方题解
	// 使用迭代法
	vector<int> operator+(const vector<int> &nums1,const vector<int> &nums2)
{
    vector<int> res = nums1;
    res.insert(res.end(),nums2.begin(),nums2.end());
    return res;
}

class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        this->res.push_back(vector<int>());
        int n = nums.size();
        if(n == 0) return this->res;
        for(int i = 0;i < n;i++)
        {
            //使用迭代的方法可以求出子集
            int S_size = res.size();
            for(int j = 0;j < S_size;j++)
            {
                //使用了一个伪队列来控制循环次数
                this->res.push_back(vector<int>{nums.at(i)} + this->res.at(j));
            }
        }

        return res;
    }

private:
    vector<vector<int>> res; //定义输出结果
};
//结论：思路太新奇了
	
//4.回溯

class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        n = nums.size();
        vector<int> targets{};
        subHelper(0,targets,nums);
        return res;
    }

    void subHelper(int idx, vector<int> &targets,vector<int>& nums)
    {
        this->res.push_back(targets);

        for(int i = idx;i < n;i++)
        {
            vector<int> temp = targets;
            temp.push_back(nums.at(i));
            subHelper(i + 1,temp,nums);
        }
    }

private:
    vector<vector<int>> res; //定义输出结果
    int n; //容器大小
};

//结论：很像迭代的方式但在迭代里递归调用，当最外层的迭代循环结束后，就会自动退回上一步
