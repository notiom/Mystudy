// 1.我自己的解
// 使用回溯算法控制从前往后去遍历不同的组合，不需要做有重复的判断
class Solution 
{
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> nums;
        for(int i = 1;i <= n;i++)
        {
            nums.push_back(i);
        }
        vector<int> current;
        backtrack(nums,current,k,0);
        return res;
    }
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums,vector<int>& current,int k,int start)
    {
        if(current.size() == k)
        {
            // 不需要检查，只需要从前往后，就不可能重复
            res.push_back(current);
        }

        for(int i = start;i < nums.size();i++)
        {
            // i最大就是nums.size() - k + 1
            current.push_back(nums.at(i));
            backtrack(nums,current,k,i + 1);
            current.pop_back();
        }
    }
};
//结论：通过 时间复杂度: O(n * 2^n) 空间复杂度: O(n)

//2. 代码改进版本,取消nums的设置
class Solution 
{
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> current;
        backtrack(current,k,n,1);
        return res;
    }
private:
    vector<vector<int>> res;
    void backtrack(vector<int>& current,int k,int n,int start)
    {
        if(current.size() == k)
        {
            // 不需要检查，只需要从前往后，就不可能重复
            res.push_back(current);
        }

        for(int i = start;i <= n;i++)
        {
            // i最大就是nums.size() - k + 1
            current.push_back(i);
            backtrack(current,k,n,i + 1);
            current.pop_back();
        }
    }
};
// 结论:通过 间复杂度: O(n * 2^n) 空间复杂度: O(n)
