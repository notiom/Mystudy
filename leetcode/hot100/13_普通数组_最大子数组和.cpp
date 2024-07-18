// 1.思路:先由一个容器表示前1，2，3，n项和
// 之后找到在左边的最小值和在最右边的最大值之间的差与两个边界的最大值
// 但是在实现找左边最小值和右边最大值时无法实现
// 解决方案,两层for循环

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> sumvec;
        int n = nums.size();
        int currentsum = 0;
        for(auto const &num : nums)
        {
            currentsum += num;
            sumvec.push_back(currentsum);
        }
        int left = 0;  // 左指针
        int right = n - 1;  // 右指针
        int res = -INT_MAX; //左边最小的值
        for(int i = 0;i < n;i++)
        {
            if(sumvec[i] > sumvec[left])
            {
                continue;
            }
            int maxdis = 0; //两个差值
            for(int j = i + 1;j < n;j++)
            {
                sumvec[left] = sumvec[i];
                maxdis = sumvec[j] - sumvec[left];
                res = max(res,maxdis);
            }
        }
        return max(res,max(sumvec[0],sumvec[n - 1]));
    } 
};
//结论：算法思路为错误
																				
//2.官方题解
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res = nums[0]; //先将结果定义为第一个元素
        int sum = 0; //计算当前和
        for(auto const &num : nums)
        {
            if(sum > 0)
            // 只要这个元素还大于0，就说明前面的积累都有效，
            // 但是如果小于0，就可以重新开始找，以当前元素为第一个元素作为起始，
            // 直到找到第一个>0的可以使和变大的数
                sum += num;
            else
            {
                sum = num;
            }
            res = max(res,sum);
        }
        return res;
    }
};
//结论： 只有和大于0时才有必要继续累加，如果和不大于0，则可以选取后面的元素作为起始继续计算，因为前面的复数只会让结果越来越小
	
//3. 滚动数组，也是利用前驱节点，动态规划
// f(i)=max{f(i−1)+nums[i],nums[i]} 动态规划方程
// 即如果前面所有元素和当前元素的累加和比我当前大，那就说明前面元素时有效的正数，可以使结果变大，如果没有当前元素大，那就丢弃前面所有的和，从现在开始计算后面的最大值
	
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        // f(i)=max{f(i−1)+nums[i],nums[i]} 动态规划方程
        int pre = 0; //将f(1)定义为nums[0],f(2) = max(f(1) + nums[1],nums[1])
        int res = nums[0]; //定义结果
        for(auto const &num : nums)
        {
            pre = max(pre + num,num); //要保证pre > 0 Pre的最后结果才会比原来大
            res = max(res,pre);
        }
        return res;
    }
};
//4. 分治 递归思想 线段树
	
class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        int res =  get(nums, 0, nums.size() - 1).mSum;
        return res;
    }
};
//结论：期待二刷，第四种解法目前还未学会
