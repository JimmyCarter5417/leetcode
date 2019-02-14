// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        
        for (const string& str: strs)
        {
            string t = str;
            sort(t.begin(), t.end());
            
            // 排序后记录其位置即可
            if (m.find(t) == m.end())
            {
                res.push_back({});
                m[t] = res.size() - 1;
            }
            
            res[m[t]].push_back(str);
        }
        
        return res;
    }
};
