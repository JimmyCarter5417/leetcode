// Given a string S, find the length of the longest substring T that contains at most two distinct characters.
// For example,
// Given S = “eceba”,
// T is “ece” which its length is 3.

// 同340
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0
        int left = 0;
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); i++) 
        {
            m[s[i]]++;

            while (m.size() > 2) 
            {
                if (--m[s[left]] == 0) 
                    m.erase(s[left]);
                    
                left++;
            }

            res = max(res, i - left + 1);
        }

        return res;
    }
};