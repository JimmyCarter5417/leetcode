// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// Example 1:

// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.


// solution I: 递归
class Solution {
public:
    int numSquares(int n) {
        int res = n;
        int num = 1;
        
        while (num * num <= n)
        {
            int a = n / (num * num);
            int b = n % (num * num);
            res = min(res, a + numSquares(b));
            num++;
        }
        
        return res;
    }
};

// solution II: dp
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; i + j * j <= n; j++)
            {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1); // 利用i和j更新每个状态，与筛素数法是相同的思想
            }
        }
        
        return dp[n];
    }
};
