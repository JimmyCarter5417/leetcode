//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
//
//Note:
//
//The same word in the dictionary may be reused multiple times in the segmentation.
//You may assume the dictionary does not contain duplicate words.
//Example 1:
//
//Input:
//s = "catsanddog"
//wordDict = ["cat", "cats", "and", "sand", "dog"]
//Output:
//[
//  "cats and dog",
//  "cat sand dog"
//]
//Example 2:
//
//Input:
//s = "pineapplepenapple"
//wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//Output:
//[
//  "pine apple pen apple",
//  "pineapple pen apple",
//  "pine applepen apple"
//]
//Explanation: Note that you are allowed to reuse a dictionary word.
//Example 3:
//
//Input:
//s = "catsandog"
//wordDict = ["cats", "dog", "sand", "and", "cat"]
//Output:
//[]
//


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> possible(s.size() + 1, true);
        dfs(s, 0, "", dict, possible, res);
        return res;
    }
    
    void dfs(const string& s, int start, string out, const unordered_set<string>& dict, vector<bool>& possible, vector<string>& res)
    {
        if (start == s.size())
        {
            out.pop_back(); // 弹出末尾多余的空格
            res.push_back(out);
            return;
        }
        
        for (int i = start; i < s.size(); i++)
        {
            string t = s.substr(start, i - start + 1);
            if (dict.find(t) != dict.end() && possible[i + 1])
            {
                int oldSize = res.size();
                dfs(s, i + 1, out + t + " ", dict, possible, res);                
                if (res.size() == oldSize)
                {
                    possible[i + 1] = false; // 剪枝：未生成新的分割方法，表示i+1位置开始都不需要再递归了
                }
            }
        }
    }
};

