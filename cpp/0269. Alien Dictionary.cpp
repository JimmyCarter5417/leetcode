// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

// For example,
// Given the following words in dictionary,

// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
 
// The correct order is: "wertf".

// Note:

// You may assume all letters are in lowercase.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return any one of them is fine.


// a good issue
// 单向图问题，待进一步理解
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> g(26, vector<bool>(26, false));
        vector<bool> visit(26, false);
        string res;

        for (string word : words) 
        {
            for (char c : word) 
            {
                g[c - 'a'][c - 'a'] = true; // 先记录所有存在的字符
            }
        }

        for (int i = 0; i < words.size() - 1; ++i) 
        {
            int mn = min(words[i].size(), words[i + 1].size())
            int j = 0;

            for ( ; j < mn; ++j) 
            {
                if (words[i][j] != words[i + 1][j]) 
                {
                    g[words[i][j] - 'a'][words[i + 1][j] - 'a'] = true; // 记录第一个不同字符序列
                    break;
                }
            }

            if (j == mn && words[i].size() > words[i + 1].size()) // 可能出现非法排序
                return "";
        }

        for (int i = 0; i < 26; ++i) 
        {
            if (!dfs(g, i, visit, res)) 
                return "";
        }

        for (int i = 0; i < 26; ++i) 
        {
            if (g[i][i]) 
                res += (char)(i + 'a');
        }

        return string(res.rbegin(), res.rend());
    }

    bool dfs(vector<vector<bool>>& g, int idx, vector<bool>& visit, string& res) 
    {
        if (!g[idx][idx]) // false代表不需要再访问，不是错误
            return true;

        visit[idx] = true;

        for (int i = 0; i < 26; ++i) 
        {
            if (i == idx || !g[idx][i]) // 不能与自己比较，也要跳过忽略的字符
                continue;
            if (visit[i]) // 自己递归再和自己比较，肯定出错了
                return false;
            if (!dfs(g, i, visit, res)) 
                return false;
        }

        visit[idx] = false; // 还原标志位
        g[idx][idx] = false; // 置为false，不需要再处理了
        res += (char)(idx + 'a');

        return true;
    }
};