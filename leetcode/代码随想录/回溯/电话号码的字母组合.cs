// 1.我自己的解
// 使用一个哈希表进行映射电话号码
// 使用不成熟的cs语法进行编辑
public class Solution 
{
        public Hashtable hashtables = new Hashtable();
        private IList<string> res = new List<string>();
        private void InitalizeHashTable()
        {
            hashtables.Clear();
            hashtables.Add('2',"abc");
            hashtables.Add('3',"def");
            hashtables.Add('4',"ghi");
            hashtables.Add('5',"jkl");
            hashtables.Add('6',"mno");
            hashtables.Add('7',"pqrs");
            hashtables.Add('8',"tuv");
            hashtables.Add('9',"wxyz");
        }
        public IList<string> LetterCombinations(string digits) 
        {   
            InitalizeHashTable();
            // dights容量
            int n = digits.Length;
            if(n == 0) return [];
            string path = "";
            backtrack(digits,path,0,n);
            return res;
        }

        public void backtrack(string digits,string path,int start,int n)
        {
            if(path.Length == n)
            {
                // 不需要做if错误判断的处理
                res.Add(path);
                return;
            }

            for(int i = start;i < n;i++)
            {
                for(int idx = 0;idx < hashtables[digits[i]].ToString().Length;idx++)
                {
                    path += hashtables[digits[i]].ToString()[idx];
                    backtrack(digits,path,i + 1,n);
                    path = path.Substring(0,path.Length - 1);
                }
            }
        }
}
// 结论:通过 时间复杂度和空间复杂度O(3^m * 4^n)，其中 m 是对应三个字母的数字个数，n 是对应四个字母的数字个数 

// 2.cs改进版本
// 维护一个索引变量的值,在循环中只对当前号码对应的string遍历,而index控制这个号码
public class Solution 
{
    public string[] letterMap = new string[10] { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    private IList<string> res = new List<string>();
    public IList<string> LetterCombinations(string digits) 
    {   

        // dights容量
        int n = digits.Length;
        if(n == 0) return [];
        string path = "";
        backtrack(digits,path,0,n);
        return res;
    }

    public void backtrack(string digits,string path,int index,int n)
    {
        if(path.Length == n)
        {
            // 不需要做if错误判断的处理
            res.Add(path);
            return;
        }

        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int idx = 0;idx < letters.Length;idx++)
        {
            path += letters[idx];
            backtrack(digits,path,index + 1,n);
            path = path.Substring(0,path.Length - 1);
        }
    }
}
// 结论:比1版本更易理解 通过 时间复杂度和空间复杂度O(3^m * 4^n)，其中 m 是对应三个字母的数字个数，n 是对应四个字母的数字个数 
