// 1.我自己的解
// 使用哈希表的unordered_set
class Trie 
{
public:
    Trie() 
    {
        mps.clear();
    }
    
    void insert(string word) 
    {
        mps.insert(word);
    }
    
    bool search(string word) 
    {
        if(mps.find(word) != mps.end())
        {
            // 找到
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) 
    {
        for(const string& s : mps)
        {
            if(s.substr(0, prefix.length()) == prefix)
            {
                // 找到
                return true;
            }
        }
        return false;
    }   
private:
    unordered_set<string> mps;
};
// 结论:通过

// 2.使用Trie树结构
// 相当于26叉树，头节点可以看作不存在
class Trie 
{
private:
    // 相当于每个Trie结构都含有26个字母的数组
    // 并且还有一个判断该字符串是否结束的flag
    bool isEnd;
    Trie* next[26];
public:
    Trie() 
    {
        isEnd = false;
        // 初始化的构造函数
        // 相当于在之后的初始化中假设apple 中a的next数组全部置为0,p中的next数组全部置为0
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) 
    {
        Trie* node = this;
        for(const char& c : word)
        {
            if(node->next[c - 'a'] == nullptr)
            {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) 
    {
        Trie* node = this;
        for(const char& c : word)
        {
            node = node->next[c - 'a'];
            if(node == nullptr)
            {
                // 说明之后的单词不存在
                return false;
            }
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) 
    {
        Trie* node = this;
        for(const char& c : prefix)
        {
            node = node->next[c - 'a'];
            if(node == nullptr)
            {
                return false;
            }
        }
        return true;
    }   
};
// 结论:通过
