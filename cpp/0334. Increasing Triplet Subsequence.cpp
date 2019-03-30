// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should:

// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

// Example 1:

// Input: [1,2,3,4,5]
// Output: true
// Example 2:

// Input: [5,4,3,2,1]
// Output: false


// solution I: naive dp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++) // 遍历i之前的数字，获取dp[i]
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    
                    if (dp[i] == 3)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};


// solution II: 利用双最小值
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        
        for (int n: nums)
        {
            if (n <= m1)
            {
                m1 = n;
            }
            else if (n <= m2)
            {
                m2 = n;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};