// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200. 

// Example 1:
// Input: [1, 5, 11, 5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
 
// Example 2:
// Input: [1, 2, 3, 5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.


// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
// https://www.youtube.com/watch?v=s6FhG--P7z0&t=1s
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        
        for (int num: nums)
        {
            sum += num;
        }
        
        if (sum % 2)
        {
            return false; // 和为奇数肯定是false
        }        
        sum /= 2; // 目的就是找到和为总和一半的字序列
        
        // dp[i][j]代表nums[0 ~ i-1]之间存在一个字序列，其和为j
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        
        dp[0][0] = true; // 空序列的和为0
        for (int i = 1; i < n + 1; i++)
        {
            dp[i][0] = true; // 前n个元素，一个都不选，就可以组成0
        }
        for (int i = 1; i < sum + 1; i++)
        {
            dp[0][i] = false; // 空序列，只能组成0
        }
        
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (nums[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j]; // 新增一个元素，取上一行的值
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - nums[i - 1]]); // 上一行，或者上一行左移新元素大小的位置
                }
            }
        }
        
        return dp[n][sum];
    }
};
