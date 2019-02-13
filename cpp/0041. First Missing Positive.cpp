// Given an unsorted integer array, find the smallest missing positive integer.

// Example 1:

// Input: [1,2,0]
// Output: 3
// Example 2:

// Input: [3,4,-1,1]
// Output: 2
// Example 3:

// Input: [7,8,9,11,12]
// Output: 1
// Note:

// Your algorithm should run in O(n) time and uses constant extra space.


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size())
        {
            // 将正整数a交换到a-1位置，最多交换n次
            if (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else
            {
                i++;
            }
        }
        
        for (i = 0; i < nums.size(); i++)
        {
            // i位置的正整数是i+1，即正整数a在a-1位置
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        
        return nums.size() + 1;
    }
};
