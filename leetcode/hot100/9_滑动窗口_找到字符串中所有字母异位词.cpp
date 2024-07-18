// 1.我自己的
// 即两层循环，滑动窗口，并且删除元素
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ///子串的长度
        int n = p.size();
        //父串的长度
        int m = s.size();
        //输出的结果容器
        vector<int> res;
        for(int i = 0;i < m;i++)
        {
            //这个标志位的含义为如果她被置为false，说明有一个元素未被找到，跳过这轮循环
            bool flag = true;
            //存放中间变量的容器
            string temp = p;
            for(int j = i;j < i + n;j++)
            {
                //对子串进行遍历
                size_t position = temp.find(s[j]);
                if(position != std::string::npos)
                {
                    temp.erase(position, 1);
                }
                else
                {
                    //未找到这个元素
                    flag = false;
                    break;
                }
            }
            //遍历完本轮仍然true,说明n个元素都被找到，是一个异位词
            if(flag == true)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

//2.官方题解，滑动窗口快，参考后自己写
class Solution {
public:
     vector<int> findAnagrams(string s, string t) 
    {
        unordered_map<char,int> need; // 创建need用来存放需要的子字符串
        int n = s.size(); //父字符串的长度
        int m = t.size(); //子字符串的长度
        vector<int> res; //定义结果的容器
        for(char c: t)
        {
            //添加子字符串到need中
            need[c]++; // 统计一个字符串出现过的次数
        }
        int left = 0; //定义左指针
        int right = 0; //定义右指针
        int valid = 0; //判断该位置的滑动窗口是否满足题目条件
        
        for(int k = 0; k < n - m + 1;k++)
        {   
            unordered_map<char,int> window; //定义一个滑动窗口
            for(int i = k;i < m + k;i++)
            {
                //初始化滑动窗口
                char c = s[i];
                window[c]++;
            }
            bool valid = true; //定义一个标志位
            for(const auto &pair: window)
            {
               if(window[pair.first] != need[pair.first]) 
               {
                valid = false;
                break;
               }
            }
            if(valid)
            {
                res.push_back(k);
            }

        }
        return res;  
    }
};

//结论：还是超时
3.改进滑动窗口，不要每次都赋值，只减去第一个和加上最后一个即可
				
class Solution {
public:
    vector<int> findAnagrams(string s, string t) 
    {
        unordered_map<char,int> need; // 创建need用来存放需要的子字符串
        int n = s.size(); //父字符串的长度
        int m = t.size(); //子字符串的长度
        vector<int> res; //定义结果的容器
        for(char c: t)
        {
            //添加子字符串到need中
            need[c]++; // 统计一个字符串出现过的次数
        }
        int left = 0; //定义左指针
        int right = m; //定义右指针
        int valid = 0; //判断该位置的滑动窗口是否满足题目条件
        unordered_map<char,int> window; //定义一个滑动窗口
        for(int k = 0; k < n - m + 1;k++)
        {   
            if(k == 0)
            {
                for(int i = k;i < m + k;i++)
                {
                //初始化滑动窗口
                char c = s[i];
                window[c]++;
                }
            }
            else
            {
                char c = s[left];
                window[c]--;
                char d = s[right];
                window[d]++;
                left++;
                right++;
            }

            bool valid = true; //定义一个标志位
            for(const auto &pair: window)
            {
               if(window[pair.first] != need[pair.first]) 
               {
                valid = false;
                break;
               }
            }
            if(valid)
            {
                res.push_back(k);
            }

        }
        return res;  
    }
};

//结论：通过，但是时间复杂度和空间复杂度都很高
4.官方题解(经过改进)

class Solution 
{
public:
    vector<int> findAnagrams(string s, string t) 
    {
        //加入need.count是为了不让need的size变化,如果不是，会改变need的长度
        vector<int> res; // 定义输出结果
        int n = s.size();   
        int m = t.size(); //子串的长度
        int valid = 0; //判断是否目标子串 = 当前子串
        int left = 0; //定义左指针
        int right = 0; // 定义右指针
        unordered_map<char,int> need,window;//need是存放目标子串的哈希表,而window是存放当前子串的哈希表
        for(char c : t)
        {
            need[c]++; //给need赋值
        }
        while(right < n)
        {
            // 当右指针指向最右端时，循环结束
            char d = s[right];
            right++; //右指针右移
            if(need.count(d))
            {
                window[d]++; //将当前字符串存入哈希表中
                if(need[d] == window[d])
                {
                    valid++;
                }
            }

            if((right - left) == m)
            {
                //如果当前串的长度 = 目标子串长度,收缩左侧
                if(valid == need.size())
                {
                    //说明每个元素都出现过，则当前索引的字符串是一个结果
                    res.push_back(left);
                }
                char e = s[left];
                left++;
                if(need.count(e))
                {
                    if(need[e] == window[e])
                    {
                        valid--;
                    }
                    window[e]--;
                }
            
            }
        }
        return res; //返回结果
    }
};
