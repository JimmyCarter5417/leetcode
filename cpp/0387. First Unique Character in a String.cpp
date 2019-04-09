// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.


class Solution {
public:
    int firstUniqChar(string s) {
        int A[256] = {0};
        
        for (char ch: s)
        {
            A[ch]++;
        }
        
        // 找到第一个计数为1的字符即可
        for (int i = 0; i < s.size(); i++)
        {
            if (A[s[i]] == 1)
            {
                return i;
            }
        }
        
        return -1;
    }
};