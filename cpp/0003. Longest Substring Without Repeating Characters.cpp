//Given a string, find the length of the longest substring without repeating characters.

//Examples:

//Given "abcabcbb", the answer is "abc", which the length is 3.

//Given "bbbbb", the answer is "b", with the length of 1.

//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = 0;
        unordered_map<char, int> m;
        
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            
            if (m.find(ch) == m.end() || m[ch] < start)
            {                
                 res = max(res, i - start + 1);               
            }            
            else
            {
                start = m[ch] + 1;
            }                
            
            m[ch] = i;
        }
        
        return res;
    }
};
