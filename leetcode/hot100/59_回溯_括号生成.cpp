//1.我自己的解
// 先生成所有可能的情况，再删除不合法的括号

class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<int> parent;
        for(int i = 0; i < n * 2; i++)
        {
            parent.push_back(1);
        }
        leftParenthesis(parent,0,n,0);
        deletenoLaw();
        return res;
    }

    void leftParenthesis(vector<int> parent,int index,int n,int flag)
    {
        if(flag == n)
        {
            // 将parent里的索引号取出，将其添加到结果容器中
            // 如果索引值为0，就是），否则就是左括号
            string temp;
            for(int i = 0;i < 2 * n;i++)
            {
                if(parent[i] == 0)
                {
                    temp += "(";
                }
                else if(parent[i] == 1)
                {
                    temp += ")";
                }
            }
            this->res.push_back(temp);
            return;
        }

        for(int i = index;i < 2 * n;i++)
        {
            if(parent[i] == 1)
            {
                parent[i] = 0;
                
                leftParenthesis(parent,i + 1,n,flag+1);
                parent[i] = 1;
            }
        }
    }

        void deletenoLaw()
    {
        // 删除不合法的括号匹配
        // 将左括号压入栈，如果2 * n 循环结束时栈不为空，就删除这个string
        auto it = res.begin();
        while (it != res.end())
        {
            if (!isValid(*it))
            {
                it = res.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    bool isValid(const string& s)
    {
        stack<char> stk;
        for (const char& ch : s)
        {
            if (ch == '(')
            {
                stk.push(ch);
            }
            else if (ch == ')')
            {
                if (stk.empty())
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }

private:
    vector<string> res;
};
//结论：通过，但是代码又长又臭

//2.通过在生成过程中检测是否是合法的括号
//思路为,一定要先添加(，再添加），所以在回溯时可以当左括号数量小于n时就一致添加，直到 = n

class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<int> parent;
        for(int i = 0; i < n * 2; i++)
        {
            parent.push_back(1);
        }
        leftParenthesis(parent,0,n,0,0);
        return res;
    }

    void leftParenthesis(vector<int> parent,int index,int n,int open,int close)
    {
        if(open == n && close == n)
        {
        
            // 将parent里的索引号取出，将其添加到结果容器中
            // 如果索引值为0，就是），否则就是左括号
            string temp;
            for(int i = 0;i < 2 * n;i++)
            {
                temp += (parent[i] == 0) ? '(' : ')';
            }
            this->res.push_back(temp);
            return;
        }

        if(open < n)
        {
            parent[index] = 0; //添加左括号
            leftParenthesis(parent,index + 1,n,open + 1,close);
        }

        if(close < open)
        {
            parent[index] = 1; //添加右括号
            leftParenthesis(parent,index + 1,n,open,close + 1);
        }   
        
    }
private:
    vector<string> res;
};
//通过回溯的方式实现左右括号匹配

//3.自己的方法在push过程中检查是否合法
class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<int> parent;
        for(int i = 0; i < n * 2; i++)
        {
            parent.push_back(1);
        }
        leftParenthesis(parent,0,n,0);
        return res;
    }

    void leftParenthesis(vector<int> parent,int index,int n,int flag)
    {
        if(flag == n)
        {
            // 将parent里的索引号取出，将其添加到结果容器中
            // 如果索引值为0，就是），否则就是左括号
            string temp;
            for(int i = 0;i < 2 * n;i++)
            {
                if(parent[i] == 0)
                {
                    temp += "(";
                }
                else if(parent[i] == 1)
                {
                    temp += ")";
                }
            }
            if(isValid(temp)) this->res.push_back(temp);
            return;
        }

        for(int i = index;i < 2 * n;i++)
        {
            if(parent[i] == 1)
            {
                parent[i] = 0;
                
                leftParenthesis(parent,i + 1,n,flag+1);
                parent[i] = 1;
            }
        }
    }

    bool isValid(const string& s)
    {
        //判断括号是否合法
        stack<char> stk;
        for (const char& ch : s)
        {
            if (ch == '(')
            {
                stk.push(ch);
            }
            else if (ch == ')')
            {
                if (stk.empty())
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }

private:
    vector<string> res;
};
//结论：通过
