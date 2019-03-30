// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:

// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Note:
// You may assume that you have an infinite number of each kind of coin.


// solution I: dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        // 先排序应该可以稍微提高点效率
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1); // 取最小值
                }
            }
        }
        
        int res = dp.back();
        return res > amount ? -1 : res; // 可能会大于amount，要返回-1
    }
};

// solution II: naive TLE recursion
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end()); // 先排序
        return helper(coins, coins.size() - 1, amount);
    }
    
    int helper(const vector<int>& coins, int pos, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
                    
        int res = INT_MAX;
        
        for (int i = pos; i >= 0; i--) // 从后往前递归
        {
            int n = amount / coins[i];
            
            while (n)
            {
                int t = helper(coins, i - 1, amount - n * coins[i]); // 遍历所有可能的n
                if (t >= 0)
                {
                    res = min(res, n + t); // res取最小值
                }
                
                n--;
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
