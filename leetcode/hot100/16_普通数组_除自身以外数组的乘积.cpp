//1.我自己的，暴力求解
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res; //定义输出结果
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            int current = 1;
            for(int j = 0; j < n;j++)
            {
                if(j == i) continue;
                current *= nums[j];
            }
            res.push_back(current);
        }
        return res;
    }
};
//结论：超出时间限制
	
//2. 官方题解一
//思路：利用两个vector存放当前元素的前缀积和后缀积，最后将这两个元素相乘
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res; //定义输出结果
        int n = nums.size();
        vector<int> Llist;
        vector<int> Rlist;
        Llist.resize(n);
        Rlist.resize(n);
        Llist.front() = 1;
        Rlist.back() = 1;
        for(int i = 1; i < n; i++)
        {
            //因为第0个元素的左侧元素的乘积为1
            Llist.at(i) = (Llist.at(i - 1) * nums.at(i - 1));
        }
        for(int j = n - 2; j >= 0; j--)
        {
            Rlist.at(j) = Rlist.at(j + 1) * nums.at(j + 1);
        }
        for(int k= 0; k < n; k++)
        {
            Llist.at(k) *= Rlist.at(k);
        }
        return Llist;
    }
};
//结论：未用空间复杂度为o(1)的算法
														
//3.o(1)算法
//考虑到输出结果不计入空间复杂度计算，所以将前缀积或者后缀积放入结果vector中，在从反方向遍历取出后缀积或者前缀积，此时只需要一个temp变量存储即可
														
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res; //定义输出结果
        int n = nums.size();
        vector<int> Rlist;
        Rlist.resize(n);
        Rlist.back() = 1;
        int premultiplied = 1;
        for(int j = n - 2; j >= 0; j--)
        {
            Rlist.at(j) = Rlist.at(j + 1) * nums.at(j + 1);
        } 
        for(int k= 0; k < n; k++)
        {
            Rlist.at(k) *= premultiplied;
            premultiplied *= nums.at(k);
        }
        return Rlist;
    }
};
//结论：空间复杂度除去结果容器为o(1)
