// 1.我自己的解
// 使用一个map即有序哈希表对其进行存储
// 如果要返回最小值，那么只需要返回mps的第一个元素的键即可
class MinStack 
{
public:
    MinStack() 
    {
        // 既然要记录最小元素那么在push进去的过程种就应该保存这个最小值
        // 但是如果这个元素被拿走，那么最小值就应该更换
        // 作弊方法一,使用有序哈希表
        
    }
    
    void push(int val) 
    {
        mps[val]++;
        stk.push(val);
    }
    
    void pop() 
    {
        mps[top()]--;
        if(mps[top()] == 0) mps.erase(top());
        stk.pop();
    }
    
    int top() 
    {
        return stk.top();
    }
    
    int getMin() 
    {
        auto it = mps.begin();
        return it->first;
    }
private:
    // 哈希表中第一个是元素排序，第二个是元素个数
    map<int,int> mps;
    stack<int> stk;
};

// 结论:通过.
