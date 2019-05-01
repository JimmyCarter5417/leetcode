// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example 1:
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5

// Explanation: 
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
// There are 5 ways to assign symbols to make the sum of nums be target 3.

// Note:
// The length of the given array is positive and will not exceed 20.
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.


// solution I: 动态规划
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1; // 与递归思想类似，都是记录每个位置每种合法值的组合数，但需要从前往后记录
        
        for (int i = 0; i < n; ++i)
        {
            for (auto p: dp[i])
            {
                int sum = p.first;
                int cnt = p.second;
                
                dp[i + 1][sum + nums[i]] += cnt;
                dp[i + 1][sum - nums[i]] += cnt;
            }
        }
        
        return dp[n][S]; // 只需要S的个数
    }
};

// solution II: 递归，with memorization 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> dp(nums.size()); // 记录每个位置每种合法值的组合数，从后往前记录
        return helper(nums, S, 0, dp);
    }

    int helper(vector<int>& nums, int sum, int start, vector<unordered_map<int, int>>& dp) 
    {
        if (start == nums.size()) 
        {
            return sum == 0;
        }

        if (dp[start].count(sum)) 
        {
            return dp[start][sum];
        }

        int cnt1 = helper(nums, sum - nums[start], start + 1, dp);
        int cnt2 = helper(nums, sum + nums[start], start + 1, dp);

        return dp[start][sum] = cnt1 + cnt2;
    }
};