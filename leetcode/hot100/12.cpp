//1.滑动窗口的思路
class Solution
{
public:
	string minWindow(string s, string t)
	{
        int ansl = -1;// 起始索引
        int sonlen = INT_MAX; //结果字串长度
		int left = 0; //定义左边指针
		int right = 0; //定义右边指针 因为可能第一个元素就满足
		unordered_map<char, int>hashmap; //定义一个哈希表，用来对比当前串是否完全覆盖子串
		unordered_map<char, int>need; // 定义满足条件子串所需要的哈希表去对比
		int fathersize = s.size(); //定义父串长度
		int sonsize = t.size(); //子串长度
		int valid = 0; //该标志位定义为当前子串是否满足条件
		//为need赋值
		for (auto const& child : t)
		{
			need[child]++;
		}
		int need_size = need.size(); //满足条件的valid个数
		while (right < fathersize)
		{
			//当右指针超出边界时循环结束
			//当左右指针距离不够时,需要增大右指针
			if (need.count(s[right]))
			{
          hashmap[s[right]]++;
				  // 如果这个值有才会进入下一步，否则会报错
				  if (hashmap[s[right]] == need[s[right]])
				  {   
					  valid++;
				  }
			}
			while (right - left >= sonsize - 1 && valid == need_size)
			{
				//在满足该循环条件下有理由一直缩小边界直到不满足条件便退出

				//说明满足条件，将其保存在当前可能的最小子串里
				if (right - left + 1 < sonlen)
				{
					sonlen = right - left + 1;
          ansl = left;
				}
				
				if (need.count(s[left]))
				{
					//如果这个值有才会进入下一步，否则会报错
					if (hashmap[s[left]] == need[s[left]])
					{
						// 只有当哈希表里的count小于need需要的值时,则表示不满足,循环需要结束
						valid--;
					}
				}
                // 开始缩小左边界
				//当左右指针距离不够时,需要增左指针
				hashmap[s[left]]--;
				left++;
			}
			right++;
		}
		return ansl == -1 ? string() : s.substr(ansl,sonlen);
	}

};
//必须要在结果中在输出字串，中间过程仅需记录这个可能的最小字串的索引值，不然会超出内存限制

//2.原先的错误写法
class Solution
{
public:
	string minWindow(string s, string t)
	{
    string minstring; //定义了一个最小索引字串
		int left = 0; //定义左边指针
		int right = 0; //定义右边指针 因为可能第一个元素就满足
		unordered_map<char, int>hashmap; //定义一个哈希表，用来对比当前串是否完全覆盖子串
		unordered_map<char, int>need; // 定义满足条件子串所需要的哈希表去对比
		int fathersize = s.size(); //定义父串长度
		int sonsize = t.size(); //子串长度
		int valid = 0; //该标志位定义为当前子串是否满足条件
		//为need赋值
		for (auto const& child : t)
		{
			need[child]++;
		}
		int need_size = need.size(); //满足条件的valid个数
		while (right < fathersize)
		{
			//当右指针超出边界时循环结束
			//当左右指针距离不够时,需要增大右指针
			if (need.count(s[right]))
			{
          hashmap[s[right]]++;
				  // 如果这个值有才会进入下一步，否则会报错
				  if (hashmap[s[right]] == need[s[right]])
				  {   
					  valid++;
				  }
			}
			while (right - left >= sonsize - 1 && valid == need_size)
			{
				//在满足该循环条件下有理由一直缩小边界直到不满足条件便退出

				//说明满足条件，将其保存在当前可能的最小子串里
        if (right - left < minstring.size() - 1 || minstring.size() ==0)
				{
					minstring = s.substr(left,right - left + 1);// ********************就是这一步超时
				}
				if (need.count(s[left]))
				{
					//如果这个值有才会进入下一步，否则会报错
					if (hashmap[s[left]] == need[s[left]])
					{
						// 只有当哈希表里的count小于need需要的值时,则表示不满足,循环需要结束
						valid--;
					}
				}
                // 开始缩小左边界
				//当左右指针距离不够时,需要增左指针
				hashmap[s[left]]--;
				left++;
			}
			right++;
		}
    return minstring;
	}

};
