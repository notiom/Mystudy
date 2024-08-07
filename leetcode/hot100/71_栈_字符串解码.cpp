// 1.官方题解1 辅助栈的思路
// 利用栈存放一个pair元素,一部分为上一次括号前的元素，另一部分为当前的倍数
string operator*(const int multi,const string& value)
{
    string res;
    for(int i = 0;i < multi;i++)
    {
        res += value;
    }
    return res;
}
class Solution 
{
public:
    string decodeString(string s) 
    {
        // 利用栈的思路，但是该栈有两个元素，一个是倍数，一个是上一轮遇到上次加倍前的temp暂存结果
        int n = s.size();
        stack<pair<int, string>> stk;
        string res = "";
        int multi = 0;
        for(const char& single : s)
        {
            if(single == '[')
            {
                // 开始push
                stk.push({multi, res});
                res = "";
                multi = 0;
            }
            else if(single == ']')
            {
                // 将当前的res结果与倍数相乘并加上上一轮的结果
                pair<int, string> temp = stk.top();
                stk.pop();
                res = temp.second + temp.first * res;
            }
            else if(isdigit(single))
            {
                // 记录倍数
                // 遇到字符‘1’：
                // multi = multi * 10 + 1 = 0 * 10 + 1 = 1
                // 遇到字符‘2’：
                // multi = multi * 10 + 2 = 1 * 10 + 2 = 12
                multi = multi * 10 + single - '0';
            }
            else
            {
                //此时为字符，使结果叠加
                res += single;
            }
        }
        return res;
    }
};
// 结论:通过
// 细节为multi的 * 10

//2.官方题解2
// 递归

string operator*(const int multi,const string& value)
{
    string res;
    for(int i = 0;i < multi;i++)
    {
        res += value;
    }
    return res;
}

class Solution 
{
public:
    string decodeString(string s) 
    {
        // 利用递归的思路，遇到]时就返回当前的结果
        int index = 0;
        return dfs(s,index).second;
    }

    pair<int,string> dfs(string s,int& index)
    {
        //其实是有一部分是递归，算是半递归，并且循环并不浪费
        string res = "";
        int multi = 0;
        while(index < s.size())
        {
            if(isdigit(s.at(index)))
            {
                multi = multi * 10 + s.at(index) - '0';
            }
            else if(s.at(index) == '[')
            {
                //  得到结果
                index++;
                pair<int,string> subRes = dfs(s,index);
                res += multi * subRes.second;
                multi = 0;
            }
            else if(s.at(index) ==']')
            {
                return pair<int,string>(multi,res);
            }
            else
            {
                res += s.at(index);
            }
            index++;
        }
        return pair<int,string>(multi,res);
    }
};
// 结论: 通过
// 细节:index处必须使用引用传递

string operator*(int n ,const string& str)
{
    string res;
    for(int i = 0; i < n;i++)
    {
        res += str;
    }
    return res;
}

// 3.7.22日大彬面试题重温
string operator*(int n ,const string& str)
{
    string res;
    for(int i = 0; i < n;i++)
    {
        res += str;
    }
    return res;
}

class Solution 
{
public:
    string decodeString(string& s)
    {
        // 定义一个栈,记录当前字符串
        stack<string> stk; 
        for(const char& ch : s)
        {
            if(isalpha(ch) || isdigit(ch) || ch == '[') 
            {
                // 遇到字母, 直接入栈
                // 遇到数字也可以入栈
                // 遇到[也可以入栈
                stk.push(string(1, ch));
            }

            else
            {
                // 这种情况只有可能遇到]
                // 出栈, 直到遇到[
                string curstr; // 记录当前字符串
                while(1)
                {
                    if(!stk.empty() && stk.top()[0] == '[')
                    {
                        stk.pop();
                        break;
                    }
                    curstr.insert(0,stk.top());
                    stk.pop();
                }
                string multiStr;
                while (!stk.empty() && isdigit(stk.top()[0])) 
                {
                    multiStr = stk.top() + multiStr;
                    stk.pop();
                }
                int beishu = stoi(multiStr);
                stk.push((beishu * curstr)); //cdcdcdcd
            } 
        }
        // 此时的栈大概率不为空
        // 出栈, 直到为空
        while(!stk.empty())
        {
            res.insert(0,stk.top());
            stk.pop();
        }
        return res;
    }
private:
    string res;
};
