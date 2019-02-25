// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// The array may contain duplicates.

// Example 1:

// Input: [1,3,5]
// Output: 1
// Example 2:

// Input: [2,2,2,0,1]
// Output: 0
// Note:

// This is a follow up problem to Find Minimum in Rotated Sorted Array.
// Would allow duplicates affect the run-time complexity? How and why?


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0; 
        int right = nums.size() - 1;
        int res = nums[0];
        
        if (nums[left] < nums[right])
            return nums[left];
            
        while (left < right - 1)
        {
            int mid = left + (right - left) / 2;
            // 最小值有可能在移动left/right过程中被丢掉，要先记录下来
            if (nums[mid] > nums[left])
            {                
                res = min(res, nums[left]);
                left = mid;
            }
            else if (nums[mid] < nums[left])
            {
                res = min(res, nums[right]);
                right = mid;
            }
            else
            {
                left++;
            }
        }
        // 原理同153. Find Minimum in Rotated Sorted Array
        return min(res, nums[right]);
    }
};
