// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// Example:

// Input: "Hello World"
// Output: 5


class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int right = s.size() - 1;
        while (right >= 0 && s[right] == ' ') // 找到最右边
            --right;
            
        while (right >= 0 && s[right] != ' ') // 向左计算
        {
            ++res;
            --right;
        }
        
        return res;
    }
};
