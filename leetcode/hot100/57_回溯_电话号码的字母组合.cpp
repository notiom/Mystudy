//1.我自己的解
// 结合子集的递归调用的思路，其实也就是回溯算法
class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        //使用迭代的方式
        this->n = digits.length();
        if(digits == "") return vector<string>();
        this->lettermap['2'] = {"a","b","c"};
        this->lettermap['3'] = {"d","e","f"};
        this->lettermap['4'] = {"g","h","i"};
        this->lettermap['5'] = {"j","k","l"};
        this->lettermap['6'] = {"m","n","o"};
        this->lettermap['7'] = {"p","q","r","s"};
        this->lettermap['8'] = {"t","u","v"};
        this->lettermap['9'] = {"w","x","y","z"};
        letterHelper(0,"",digits);
        return lettervec;
    }

    void letterHelper(int idx,string targets,string digits)
    {
        if(idx == n)
        {
            //此时应该把元素push进到vec中
            if(targets.length() == n)
            {
                this->lettervec.push_back(targets);
            }
            return;
        }
        for(int i = idx;i < n;i++)
        {
            char num = digits.at(i);
            vector<string> letters = this->lettermap[num];
            for(const auto& letter : letters)
            {
                letterHelper(i+1,targets+letter,digits);  //递归调用
            }
        }
    }
private:
    vector<string> lettervec;
    int n; //dights大小
    unordered_map<char,vector<string>> lettermap; //数字和字母的对应关系
};

//结论：通过
