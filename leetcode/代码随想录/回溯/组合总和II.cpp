// 1.我自己的解
// 使用集合去重的思想
class Solution 
{
public:
    vector<vector<int>> res;
    set<vector<int>> sumSet;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        // 难点在于有重复元素,且组合数只能出现一次，每个元素也只能选一次
        // 难点就在于去重复
        // 方法 集合去重
        n = candidates.size();
        sort(candidates.begin(), candidates.end()); // 先进行排序,方便后续剪枝
        vector<int> path;
        backtrack(candidates,path,target,0);
        for(const vector<int>& element : sumSet)
        {
            res.push_back(element);
        }
        return res;
    }

    void backtrack(vector<int>& candidates,vector<int>& path,int target,int start)
    {
        if(target == 0)
        {
            sumSet.insert(path);
            return;
        }

        for(int i = start; i < n; i++)
        {
            if(target - candidates[i] < 0)
            {
                break;
            }
            path.push_back(candidates[i]);
            backtrack(candidates,path,target - candidates[i],i + 1);
            path.pop_back();
        }
    }
};
// 结论:未通过 集合去重的思路不可取

// 2.通过startIndex变量来判断某一变量是否使用过
// 具体逻辑解释

// i > start：这个条件确保我们只在当前层的递归中进行去重。如果 i == start，
// 说明是第一次选中这个数，即便它和前一个数相同也不影响，必须要选择它。这是为了避免漏掉合法的组合。

// candidates[i] == candidates[i - 1]：如果当前元素和前一个元素相同，
// 意味着如果选择了当前的 candidates[i]，会得到与选择了前一个 candidates[i - 1] 一模一样的组合，因此应该跳过。
/*
结合例子 [1, 1, 2]
->开始递归：

输入：[1, 1, 2]，目标：3，路径：[]
第一层循环：

i = 0：选择 candidates[0] = 1
递归：[1]，目标：2
第二层循环：

i = 1：选择 candidates[1] = 1（因为还未进入去重条件，i == start）
递归：[1, 1]，目标：1
第三层循环：

i = 2：选择 candidates[2] = 2
剩余目标：-1，不满足，回溯，撤销选择 2
回到第二层，撤销选择 candidates[1] = 1

i = 2：选择 candidates[2] = 2

递归：[1, 2]，目标：0
找到一个合法组合 [1, 2]
回到第一层，撤销选择 candidates[0] = 1

i = 1：此时 candidates[1] == candidates[0]，触发去重逻辑 if (i > start && candidates[i] == candidates[i - 1]) continue;，跳过 candidates[1]

i = 2：选择 candidates[2] = 2

递归：[2]，目标：1
没有更多合法选择，回溯
*/

class Solution 
{
public:
    vector<vector<int>> res;;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        // 难点在于有重复元素,且组合数只能出现一次，每个元素也只能选一次
        // 难点就在于去重复
        // 方法 集合去重
        n = candidates.size();
        sort(candidates.begin(), candidates.end()); // 先进行排序,方便后续剪枝
        vector<int> path;
        backtrack(candidates,path,target,0);
        return res;
    }

    void backtrack(vector<int>& candidates,vector<int>& path,int target,int start)
    {
        if(target == 0)
        {
            res.push_back(path);
            return;
        }

        for(int i = start; i < n; i++)
        {
            // 此处i == start是第一次选择这个数
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            if(target - candidates[i] < 0)
            {
                break;
            }
            path.push_back(candidates[i]);
            backtrack(candidates,path,target - candidates[i],i + 1);
            path.pop_back();
        }
    }
};
// 结论:通过 时间复杂度O(n * 2^n) 空间复杂度O(n)
