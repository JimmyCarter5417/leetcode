// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Note:

// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        int n = nums.size();
        while (cur < n)
        {
            if (nums[cur] != 0)
                swap(nums[cur], nums[pre++]); // 关键是记录pre并与cur交换
            cur++;
        }
    }
};
