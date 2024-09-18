// 1.我自己的解
// 在回溯遍历中遍历的最大长度为3，而不是设置start && end
class Solution 
{
public:
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> path;
        backtrack(s,path,s.size());
        return res;
    }
private:
    vector<string> res;
    void backtrack(string s,vector<string>& path,int n)
    {
        if(path.size() == 4)
        {
            bool flag = true;
            string sin_str = "";
            for(int i = 0;i < 4;i++)
            {
               if(!digitCount(path.at(i)) || (path.at(i).at(0) == '0' && path.at(i).size() != 1))
               {
                    // 第一个判断是首先判断数字的大小是否在0 - 255
                    // 第二个判断是判断是否有首0元素，首0元素的特征是字符串长度大于1并且第一个元素是0
                    flag = false;
                    break;
               }
               sin_str += path.at(i);
               if(i == 3) break;
               sin_str += '.';
            }
            if(flag && sin_str.size() == n + 3) 
            {
                // 如果数字大小都满足且将所有的字符串所有遍历完，加上3个.就是总长度等于n + 3
                res.push_back(sin_str);
            }
             return;
        }

        for(int i = 0; i < 3 && i < s.size();i++)
        {
            // 每个字符串的长度最大为3，有时剩余的字符串长度不足3
            string current = s.substr(0,i + 1);
            path.push_back(current);
            backtrack(s.substr(i + 1),path,n);
            path.pop_back();
        }
    }
    bool digitCount(string s)
    {
        int n = s.size();
        if(n > 3 || n == 0) return false;
        int digit = 0;
        int value = n - 1;
        // 将数字合体
        for(const char c : s)
        {
            if(!isdigit(c)) return false;
            int num = c - '0';
            digit += num * pow(10,value);
            value--;
        }
        // 判断数字大小
        if(digit > 255) return false;
        return true;
    }
};
// 结论:通过 时间复杂度O(3^4)，空间复杂度o(n).

// 2.代码随想录改进版本
