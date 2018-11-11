// Given a string S, count the number of distinct, non-empty subsequences of S .

// Since the result may be large, return the answer modulo 10^9 + 7.

 

// Example 1:

// Input: "abc"
// Output: 7
// Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
// Example 2:

// Input: "aba"
// Output: 6
// Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".
// Example 3:

// Input: "aaa"
// Output: 3
// Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
 

 

// Note:

// S contains only lowercase letters.
// 1 <= S.length <= 2000


class Solution {
public:
    int distinctSubseqII(string S) {
        vector<int> dp(S.size(), 0); // 记录当前位置及之前的位置可组合的不同序列个数
        vector<int> last(256, -1); // 记录当前字符最近一次出现的位置
        int mod = 1000000007;
        int res = 0;
        
        dp[0] = 2; // 单个字符有两种组合（包含空字符串“”）
        last[S[0]] = 0; // 首字符出现的位置为0
        
        for (int i = 1; i < S.size(); i++)
        {
            // abab
            // dp[0] = 2,  ("", "a")
            // dp[1] = 4,  ("", "a", "b", "ab");
            // dp[2] = 7,  ("", "a", "b", "aa", "ab", "ba", "aba");
            // dp[3] = 12, ("", "a", "b", "aa", "ab", "ba", "bb", "aab", "aba", "abb", "bab", "abab").
            // dp[i] = 2 * dp[i - 1] - dp[last[S[i]] - 1]
            dp[i] = 2 * dp[i - 1] % mod;            
            if (last[S[i]] > 0)
            {
                dp[i] -= dp[last[S[i]] - 1];
            }
            else if (last[S[i]] == 0) // 首字符只需要减一，即“”
            {
                dp[i]--;
            }
            
            dp[i] %= mod;
            last[S[i]] = i;
        }
        
        res = dp.back() - 1; // 减去空字符串“”
        if (res < 0)
        {
            res += mod;
        }
        
        return res;
    }
};