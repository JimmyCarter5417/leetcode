// Given two strings s and t , write a function to determine if t is an anagram of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mm; // 记录每个字符的绝对计数
        
        for (auto ch: s)
        {
            ++mm[ch];
        }
        
        for (auto ch: t)
        {
            if (mm.find(ch) == mm.end() || mm[ch] == 0) / 可提前结束
            {
                return false;
            }
            else
            {
                --mm[ch];
            }
        }
        
        for (auto p: mm)
        {
            if (p.second != 0)
                return false;
        }
        
        return true;
    }
};
