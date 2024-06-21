// 1.我自己的解
// 回溯算法的巧妙之处在于退回
// 假设数组时[2,3,6，7] 8
// (第二层i为0)2 -> 2 -> 2 -> 2 push 2 -> 2 -> 2
//             在这层循环中2 -> 2 -> 2 -> 3 由于3大于8 - 6 = 2，故直接结束本轮循环
//     (第三层i变为1)   2 -> 2 -> 3 ->3 直接退出本轮循环
//     (第二层i变为1)   2 -> 2 -> 6 直接退出本轮循环
// (第二层i变为1) 
//   2 -> 3 -> 3 push
//   2 -> 3 -> 6 break
// (第二层i变为2) 
//  2 -> 6 push
//  2 -> 6 -> 6 break
//( 第二层i变为3) 
//  2 -> 7 break
//(((最外层i = 1)))
// 从3 -> 3 -> 6开始
/**/
class Solution 
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        //思路:使用暴力枚举所有的元素,构造一个生序排列排列容器，当当前元素大于target时，直接退出循环
        n = candidates.size();
        if(n == 0) return vector<vector<int>>();
        sort(candidates.begin(), candidates.end());
        vector<int> input{};
        solve(input,candidates,0,target);
        return res;
    }

    void solve(vector<int>& input,vector<int>& candidates,int start,int target)
    {
        if(target < 0)
        {
            //当前解不可能有解
            return;
        }
        else if(target == 0)
        {
            //当前解有解
            res.push_back(input);
            return;
        }
        else
        {
            //当前解可能有解
            for(int i = start; i < n;i++)
            {
                if (candidates.at(i) > target) 
                {
                    // 剪枝：当前数值已经大于目标值，后面的数值也一定大于目标值，可以直接结束循环
                    break;
                }
                input.push_back(candidates.at(i));
                solve(input,candidates,i,target - candidates.at(i));
                input.pop_back();
            }
        }
    }

private:
    vector<vector<int>> res; //定义输出结果
    int n; //候选数组的长度
};

//结论：通过，并且不需要集合去重
