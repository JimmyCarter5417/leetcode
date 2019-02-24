//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//Example:
//
//Input: "aab"
//Output:
//[
//  ["aa","b"],
//  ["a","a","b"]
//]
//


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        dfs(s, 0, out, res);
        return res;
    }
    
    void dfs(const string& str, int start, vector<string>& out, vector<vector<string>>& res)
    {
        if (start == str.size())
        {
            res.push_back(out);
            return;
        }
        
        for (int i = start; i < str.size(); i++)
        {
            string tmp = str.substr(start, i - start + 1);
            if (isPalindrome(tmp)) // 只需要对回文子串递归
            {
                out.push_back(tmp);
                dfs(str, i + 1, out, res);
                out.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& str)
    {
        int left = 0;
        int right = str.size() - 1;
        
        while (left <= right)
        {
            if (str[left++] != str[right--])
            {
                return false;
            }            
        }
        
        return true;
    }
};

