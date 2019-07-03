// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

// Example 1:
// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.

// Example 2:
// Input: "aba"
// Output: False

// Example 3:
// Input: "abcabcabcabc"
// Output: True
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)


// KMP算法
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        s.push_back('#');
        int size = s.size();
        
        int next[size] = {0};
        next[0] = -1;
        int i = 0;
        int j = -1;
        while (i < size - 1)
        {
            if (j == -1 || s[i] == s[j])
            {
                next[++i] = ++j;
            }    
            else
            {
                j = next[j];
            }    
        }
        
        // 上面是普通的KMP next数组计算，关键在于这里的判断
        return next[size - 1] > 0 && ((next[size - 1]) % (size - next[size - 1] - 1) == 0);
    }
};