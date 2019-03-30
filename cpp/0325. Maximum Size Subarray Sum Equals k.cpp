// Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

// Example 1:
// Given nums = [1, -1, 5, -2, 3], k = 3,
// return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

// Example 2:
// Given nums = [-2, -1, 2, 1], k = 1,
// return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

// Follow Up:
// Can you do it in O(n) time?


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            
            if (sum == k) 
                res = i + 1;
            else if (m.count(sum - k)) 
                res = max(res, i - m[sum - k]); // 左开右闭区间
            
            if (!m.count(sum)) // sum的位置不能再更新了，因为要取最小值
                m[sum] = i;
        }

        return res;
    }
};