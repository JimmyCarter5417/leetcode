// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:

// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.


class Solution {
public:
    int longestPalindrome(string s) {        
        unordered_map<char, int> mm;
        for (auto ch: s)
        {
            ++mm[ch];
        }
        
        int odds = 0;
        for (auto n: mm)
        {
            odds += n.second & 1;
        }
        
        return s.size() - max(0, odds - 1); // 每个奇数个数的字符都要删掉一个，变成偶数，最多保留一个奇数个数
    }
};