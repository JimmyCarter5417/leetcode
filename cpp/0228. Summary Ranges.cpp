// Given a sorted integer array without duplicates, return the summary of its ranges.

// Example 1:

// Input:  [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
// Example 2:

// Input:  [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int left = 0;
        int n = nums.size();
        while (left < n)
        {
            int cur = left;
            while (cur < n - 1 && nums[cur] + 1 == nums[cur + 1]) // 二次循环得到连续区间
                cur++;
            res.push_back(cur == left ? to_string(nums[left]) : to_string(nums[left]) + "->" + to_string(nums[cur]));
            
            left = cur + 1;
        }
        
        return res;
    }
};
