// Given an unsorted array of integers, find the length of longest increasing subsequence.

// Example:

// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
// Note:

// There may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n2) complexity.
// Follow up: Could you improve it to O(n log n) time complexity?


// solution I: 动态规划，O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        int res = 0;
        vector<int> dp(nums.size(), 1);
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
};


// solution II: 动态规划 + 二分查找，O(NlgN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        vector<int> dp;
        
        for (int n: nums)
        {
            auto itr = lower_bound(dp.begin(), dp.end(), n);
            if (itr == dp.end())
            {
                dp.insert(itr, n);
            }
            else
            {
                *itr = n;
            }
        }
        
        return dp.size(); // dp里面不一定是LIS序列，只是长度与LIS序列相同
    }
};
