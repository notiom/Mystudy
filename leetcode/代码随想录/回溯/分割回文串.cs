// 1.我自己的解
// 使用回溯去判断是否是回文字符串
// 复杂的点在于判断回文字符串的函数可以使用动态规划去改进
public class Solution 
{
    IList<IList<string>> res = new List<IList<string>>();
    public IList<IList<string>> Partition(string s) 
    {
        List<string> path = new List<string>();
        BackTrack(s, path, 0);
        return res;
    }

    private void BackTrack(string s,List<string> path,int start)
    {
        if(start == s.Length)
        {
            //找到一种可行解
            res.Add(new List<string>(path));
        }

        for(int i = start;i < s.Length;i++)
        {
            if(IsHuiwen(s.Substring(start,i - start + 1)))
            {
                path.Add(s.Substring(start,i - start + 1));
                BackTrack(s,path,i + 1);
                path.RemoveAt(path.Count - 1);
            }
        }
    }

    private bool IsHuiwen(string s)
    {
        for(int i = 0; i < s.Length / 2; i++)
        {
            if(s[i] != s[s.Length - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
}
// 结论:通过
-------------------------------------
