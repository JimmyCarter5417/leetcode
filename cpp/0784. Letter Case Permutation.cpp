// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

// Input: S = "3z4"
// Output: ["3z4", "3Z4"]

// Input: S = "12345"
// Output: ["12345"]
// Note:

// S will be a string with length at most 12.
// S will consist only of letters or digits.

class Solution {
public:
    vector<string> letterCasePermutation(string S) {        
        vector<string> res;
        dfs(S, 0, res, "");
        
        return res;
    }
    
    void dfs(const string& src, int pos, vector<string>& res, string out)
    {
        if (pos >= src.size()) 
        {
            res.push_back(out);
            return; 
        }
        
        char ch = src[pos];        

        //　大小写互转
        if (islower(ch))           
        {       
            dfs(src, pos + 1, res, out + (char)toupper(ch));// 字母转换后继续递归
        }
        else if (isupper(ch))
        {      
            dfs(src, pos + 1, res, out + (char)tolower(ch));// 字母转换后继续递归
        }   
        else
        {
            // 其他字符不处理
        }
        
        dfs(src, pos + 1, res, out + ch);// 不改变当前字符　从下一位置递归
       
        return;
    }
};
