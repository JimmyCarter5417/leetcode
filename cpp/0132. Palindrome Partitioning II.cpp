//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//Example:
//
//Input: "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//


// HARD 
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        vector<vector<bool>> flag(n, vector<bool>(n, false));

        for (int i = 0; i <= n; ++i)
            dp[i] = n - i - 1;

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if (s[i] == s[j] && (j - i <= 1 || flag[i + 1][j - 1]))
                {
                    flag[i][j] = true;
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }

        return dp.front();
    }
};

