//1. 我自己的解
// 利用插针法解决此问题
// 要设置一个预先存放上一次变化的队列，之后记录上一次队列的长度
// 新的一轮，将队列中所有的容器都进行插入操作，即实现将新的元素插入到当前所遍历容器的每一个位置
// 假设第一轮只有<1>进入队列，之后对元素2进行操作
// 将2插入到1的左边<2,1>,将2插入到1的右边<1,2> 之后本轮队列操作完毕，将新的<1,2>,<2,1>入队
// 之后对元素3进行操作 此时队列中有2个容器<1,2>,<2,1>
// 先对<1,2>进行操作,同理得到<3,1,2>,<1,3,2>,<1,2,3> 之后在对<2,1>操作,得到<3,2,1>,<2,3,1>,<2,1,3>
// 此时已经没有元素可以操作了，返回当前队列并push到res结果中
class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        //思路:插针法
        //先将第一个元素固定，然后在选出第二个元素，将其插到左和右
        //之后在将第三个元素插到左中右
        //之后依次类推，最后选出所有可能的情况
        int n = nums.size();
        if(n == 0) return vector<vector<int>>();
        // 当上一轮容器被添加新元素后，这一轮的就容器就应该剔除
        queue<vector<int>> que;
        que.push(vector<int>{nums.at(0)});
        //当指定的循环次数结束时,就将当前队列的元素放到res中输出
        vector<vector<int>> res; //定义输出结果
        for(int i = 1;i < n;i++)
        {
           //该层循环表示要将所有的元素都进行一遍插值
           int S_size = que.size(); //当前队列的大小
           for(int j = 0;j < S_size;j++)
           {
                //将当前队列中所有元素都遍历完
                vector<int> cur = que.front();
                que.pop();
                //当前容器的大小就为i
                for(int k = 0;k <= i;k++)
                {
                    //此时的i就是当前容器的大小
                    //将当前容器的元素插入到当前容器的第k个位置
                    vector<int> temp = cur;
                    temp.insert(temp.begin() + k,nums.at(i));
                    que.push(temp);
                }
           }
           
        }
        //外层for循环结束后，队列中现有的所有元素就是全排列
        while(!que.empty())
        {
            res.push_back(que.front());
            que.pop();
        }
        return res;
    }
};
//结论:通过,插针法

//2.官方题解
