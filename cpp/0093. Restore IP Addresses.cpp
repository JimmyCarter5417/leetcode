// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// Example:

// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string out;
        dfs(s, 0, 0, out, res);
        return res;
    }
    
    void dfs(const string& s, int level, int pos, string out, vector<string>& res)
    {
        // 这个越界判断是必须的，“1111“
        if (pos > s.size())
        {
            return;
        }
        
        if (level == 4)
        {
            if (pos == s.size())
            {
                out.pop_back();
                res.push_back(out);
            }
            
            return;
        }
        
        // 每次最多只要前进3步
        for (int i = 1; i < 4; i++)
        {
            string t = s.substr(pos, i);            
            if (isValidNum(t))
            {
                dfs(s, level + 1, pos + i, out + t + ".", res);
            }
        }
    }
    
    bool isValidNum(const string& str)
    {
        if (str.empty() || str.size() > 3 || (str.size() > 1 && str.front() == '0') || stoi(str) > 255)
        {
            return false;
        }
        
        return true;
    }
};