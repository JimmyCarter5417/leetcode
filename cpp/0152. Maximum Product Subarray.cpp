// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int mn = nums[0];
        int mx = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            // 同时记录最大最小值
            int t1 = mn * nums[i];
            int t2 = mx * nums[i];
            // 可能要用num[i]更新最大最小值
            int a = min(min(t1, t2), nums[i]);
            int b = max(max(t1, t2), nums[i]);
            mn = a;
            mx = b;
            res = max(res, mx);
        }
        
        return res;
    }
};
