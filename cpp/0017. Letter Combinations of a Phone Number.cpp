// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:

// Although the above answer is in lexicographical order, your answer could be in any order you want.


class Solution {
public:
    vector<string> letterCombinations(string digits) {        
        vector<string> res;
        if (digits.empty())
        {
            return res;
        }
        
        unordered_map<char, string> m = 
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        
        dfs(digits, 0, m, "", res);
        
        return res;
    }
    
    void dfs(const string& digits, 
             int level, 
             unordered_map<char, string>& m, 
             string out, 
             vector<string>& res)
    {
        if (level == digits.size())
        {
            res.push_back(out);
            return;
        }
        
        string str = m[digits[level]];
        for (int i = 0; i < str.size(); i++)
        {
            out.push_back(str[i]);
            dfs(digits, level + 1, m, out, res);
            out.pop_back();
        }
    }
};