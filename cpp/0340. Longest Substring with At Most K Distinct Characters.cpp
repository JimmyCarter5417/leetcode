// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// For example, Given s = “eceba” and k = 2,

// T is "ece" which its length is 3.


// 同0159. Longest Substring with At Most Two Distinct Characters
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0
        int left = 0;
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); i++) 
        {
            m[s[i]]++;

            while (m.size() > k) // 这里要用循环，因为左边界右移不一定导致m内数字减少
            {
                if (--m[s[left]] == 0) // 左边界数字计数减一
                    m.erase(s[left]); // 弹出数字
                    
                left++; // 左边界右移
            }

            res = max(res, i - left + 1);
        }

        return res;
    }
};