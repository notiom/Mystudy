//1.解法1：利用一个临时队列接住容器末尾的元素
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        queue<int> temp; //利用先进先出的性质
        int n = nums.size();
        for(int i = n - 1; i > n - 1 - k;i --)
        {
            temp.push(nums[i]);
            nums.pop_back(); //将最后一个元素弹出
        }
        for(int j = 0;j < k;j++)
        {
            nums.insert(nums.begin(),temp.front());
            temp.pop();
        }
    }
};
//结论：没有考虑到k > nums.size()的情况
	
解决方法：对k = k % n 对其取余
	
附完整代码：class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        queue<int> temp; //利用先进先出的性质
        int n = nums.size();
        k = k % n;
        for(int i = n - 1; i > n - 1 - k;i --)
        {
            temp.push(nums[i]);
            nums.pop_back(); //将最后一个元素弹出
        }
        for(int j = 0;j < k;j++)
        {
            nums.insert(nums.begin(),temp.front());
            temp.pop();
        }
    }
};
//结论：超时
																
//2.解法2 ： 官方题解
//官方思路旋转为将其倒序排列，然后从k分开，再将其倒序排列，但是时间复杂度怎么o(1)，利用reverse方法
																
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        queue<int> temp; //利用先进先出的性质
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(),nums.end()); // 先翻转一次
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin() + k,nums.end());
    }    
};

//结论：通过
												
