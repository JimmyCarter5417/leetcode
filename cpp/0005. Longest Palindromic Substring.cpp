// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
// 
// Example:
// 
// Input: "babad"
// 
// Output: "bab"
// 
// Note: "aba" is also a valid answer.
// Example:
// 
// Input: "cbbd"
// 
// Output: "bb"


//dp
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        //vector<vector<bool>> dp(size, vector<bool>(size, false));        
        bool dp[size][size];        
        
        for (int i = 0; i < size; ++i)
            dp[i][i] = true;
        
        int maxLen = 0;
        int start = 0;
        
        for (int i = size - 1; i >= 0; --i)
        {
            for (int j = size - 1; j >= i; --j)
            {
                if (i == j)
                    dp[i][j] = true;
                else if (j - i == 1)
                    dp[i][j] = (s[i] == s[j]);
                else 
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                    
                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
